/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:53:02 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/26 16:44:56 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


/* ----------------------------------------------------------------------------
** Put any variables that are needed as singular references (e.g., for testing
** pointers, and declare them as extern in unit_tests.c
** --------------------------------------------------------------------------*/

char	a01;
unsigned char a02;
short a03;
unsigned short a04;
int a05;
unsigned int a06;
long a07;
unsigned long a08;
long long a09;
unsigned long long a10;
char *a11;
void *a12;
unsigned int		mx_u = 235;
long double			mx_Lf = 0.375l;
double				mx_f = 0.625;
long				mx_li =  4223372036854775800;
long long			mx_lli = 3223372036654775200;
char				mx_c = 'G';
short				mx_hi = -3244;
char				mx_hhi = 'F';
char			   *mx_s = "Hello, World!";
int					mx_i = 42;


/* ----------------------------------------------------------------------------
** Calls a unit test function and outputs the result to a file
** --------------------------------------------------------------------------*/
static int	output_to_file(char *filename, t_unit_test f)
{
	fpos_t		pos;
	int			fd = dup(fileno(stdout));
	int			ret;

	//Set up redirection of stdout
	fgetpos(stdout, &pos);
	freopen(filename, "w+", stdout);
	//Call the test function
	ret = f();
	chmod(filename, 0644);
	//Clean up
	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	return (ret);
}

/* ----------------------------------------------------------------------------
** Logs a failed test to the test results file
** --------------------------------------------------------------------------*/
void	log_failed_test(int test_number, int expected, int actual,
		char *signal_terminated)
{
	char	buff[MAX_FILE_COPY_SIZE + 1];
	buff[MAX_FILE_COPY_SIZE] = '\0';
	int bytes;

	//Open files
	int finmine = open(OUT_ACTUAL, O_RDONLY);
	if (finmine < 0) return ;
	int finlibc = open(OUT_EXPECTED, O_RDONLY);
	if (finlibc < 0) { close(finmine); return ; }
	int fout = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
	if (fout < 0) { close(finlibc); close(finmine); return ; }

	//Write to test results file
	snprintf(buff, MAX_FILE_COPY_SIZE, "Test %3i (%s) : FAILED.\n", test_number, g_unit_test_names[test_number]);
	write(fout, buff, strlen(buff));
	snprintf(buff, MAX_FILE_COPY_SIZE, "    First line of code: %s", g_unit_test_first_lines[test_number]);
	write(fout, buff, strlen(buff));
	write(fout, "\n", 1);
	if (!signal_terminated)
	{
		snprintf(buff, MAX_FILE_COPY_SIZE, "    Returned expected %i, actual %i", expected, actual);
		write(fout, buff, strlen(buff));
		write(fout, "\n", 1);
		snprintf(buff, MAX_FILE_COPY_SIZE, "      expected : \"");
		write(fout, buff, strlen(buff));
		bytes = read(finlibc, buff, MAX_FILE_COPY_SIZE);
		if (bytes > 0) write(fout, buff, bytes);
		snprintf(buff, MAX_FILE_COPY_SIZE, "\"\n      actual   : \"");
		write(fout, buff, strlen(buff));
		bytes = read(finmine, buff, MAX_FILE_COPY_SIZE);
		if (bytes > 0) write(fout, buff, bytes);
		write(fout, "\"\n", 2);
	}
	else
	{
		write(fout, "    ", 4);
		write(fout, signal_terminated, strlen(signal_terminated));
	}
	//close files)
	close(finlibc);
	close(finmine);
	close(fout);
}

/* ----------------------------------------------------------------------------
** Signal Handlers for segfault, bus error, etc.
** --------------------------------------------------------------------------*/
static void failsafe_recover(void)
{
	//Go to the next test
	failsafe_args_recover->current++;
	failsafe_args_recover->num_fails++;
	failsafe_args_recover->num_run++;
	//Cleanup stdout
	fflush(stdout);
	fflush(stderr);
	//Recover stdout from the args failsafe
	dup2(failsafe_args_recover->fd_stdout_dup, fileno(stdout));
}
static void	handle_sigsegv(int sigval)
{
	(void)sigval;
	failsafe_recover();
	printf(FAULT "SEGFAULT" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
static void	handle_sigbus(int sigval)
{
	(void)sigval;
	failsafe_recover();
	printf(FAULT "BUSERROR" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
static void handle_sigabrt(int sigval)
{
	(void)sigval;
	failsafe_recover();
	printf(FAULT "SIGABRT" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
static void handle_sigill(int sigval)
{
	(void)sigval;
	failsafe_recover();
	printf(FAULT "SIGILL" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}

/* ----------------------------------------------------------------------------
** Runs the pair of a test function and its bench and outputs to file
** --------------------------------------------------------------------------*/
static t_retvals	output_test(int test_number)
{
	t_retvals		retvals;

	//Run test
	retvals.ret_val_mine = output_to_file(OUT_ACTUAL, g_unit_tests[test_number]);

	//If the test was not a nocrash_ test
	if (strncmp(g_unit_test_names[test_number], "nocrash_", 8) != 0)
	{
		//Run bench
		retvals.ret_val_libc = output_to_file(OUT_EXPECTED, g_bench[test_number]);
	}
	else
		retvals.ret_val_libc = -2;

	return (retvals);
}

/* ----------------------------------------------------------------------------
** Evaluates results from the recently run test
** --------------------------------------------------------------------------*/
static int	evaluate_test_results(t_retvals retvals, int test_number)
{
	int				failed = 0;
	FILE			*fpmine, *fplibc;
	int				cmine, clibc;

	//If the test was not a nocrash_ test
	if (strncmp(g_unit_test_names[test_number], "nocrash_", 8) != 0)
	{
		//Evaluate test results
		if (retvals.ret_val_mine != retvals.ret_val_libc && !(IGNORE_RETURN_VALUE))
			failed = 1;
		else
		{
			fpmine = fopen(OUT_ACTUAL, "r+");
			fplibc = fopen(OUT_EXPECTED, "r+");
			if (!fpmine || !fplibc) {
				perror("Error opening test output files--contact gfielder about this error");
				return 0;
			}
			cmine = getc(fpmine);
			clibc = getc(fplibc);
			while ((cmine != EOF) && (clibc != EOF) && (clibc == cmine)) {
				cmine = getc(fpmine);
				clibc = getc(fplibc);
			}
			if (cmine != clibc)
				failed = 1;
			fclose(fpmine);
			fclose(fplibc);
		}
	}

	if (failed)
		log_failed_test(test_number, retvals.ret_val_libc, retvals.ret_val_mine, NULL);

	return failed;
}

/* ----------------------------------------------------------------------------
** Runs a specific test
** --------------------------------------------------------------------------*/
static int		run_test(int test_number)
{
	t_retvals		retvals;
	int				failed = 0;

	signal(SIGSEGV, handle_sigsegv);
	signal(SIGBUS, handle_sigbus);
	signal(SIGABRT, handle_sigabrt);
	signal(SIGILL, handle_sigill);

	print_test_start(test_number);
	retvals = output_test(test_number);
	failed = evaluate_test_results(retvals, test_number);
	print_test_end(failed);

	return failed;
}

/* ----------------------------------------------------------------------------
** Runs all the tests that match the search pattern
** --------------------------------------------------------------------------*/
void	run_search_tests(t_unit_tester_args *args)
{
	int fail = 0;
	
	//Append a * onto pattern so we don't have to modify the piscine's ft_match
	size_t len = strlen(args->pattern) + 2;
	char *pattern = (char *)malloc(len);
	pattern[len - 1] = '\0';
	for (size_t i = 0; i < len - 2; i++)
		pattern[i] = args->pattern[i];
	pattern[len - 2] = '*';

	//Convert all invalid characters for function names into wildcards
	convert_nonalphanum_to_wildcard(pattern);

	//Search tests
	while (g_unit_tests[args->current] != NULL)
	{
		if (ft_match(g_unit_test_names[args->current], pattern))
		{
			fail = run_test(args->current);
			args->num_fails += fail;
			args->num_run++;
		}
		args->current++;
	}
	print_end_test_message(args->num_run, args->num_run - args->num_fails);
	free(pattern);
	exit(0); //needed in case a test segfaulted
}

/* ----------------------------------------------------------------------------
** Runs a range of tests
** --------------------------------------------------------------------------*/
void	run_test_range(t_unit_tester_args *args)
{
	int	fail = 0;

	while (args->current <= args->to && g_unit_tests[args->current] != NULL)
	{
		fail = run_test(args->current);
		args->num_fails += fail;
		args->num_run++;
		args->current++;
	}
	print_end_test_message(args->num_run, args->num_run - args->num_fails);
	exit(0); //needed in case a test segfaulted
}
