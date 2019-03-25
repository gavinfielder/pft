/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:53:02 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/24 16:23:23 by gfielder         ###   ########.fr       */
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
void	log_failed_test(int test_number, int expected, int actual)
{
	char	buff[MAX_FILE_COPY_SIZE + 1];
	buff[MAX_FILE_COPY_SIZE] = '\0';

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
	snprintf(buff, MAX_FILE_COPY_SIZE, "    Returned expected %i, actual %i\n", expected, actual);
	write(fout, buff, strlen(buff));
	snprintf(buff, MAX_FILE_COPY_SIZE, "      expected : \"");
	write(fout, buff, strlen(buff));
	int bytes = read(finlibc, buff, MAX_FILE_COPY_SIZE);
	if (bytes > 0) write(fout, buff, bytes);
	snprintf(buff, MAX_FILE_COPY_SIZE, "\"\n      actual   : \"");
	write(fout, buff, strlen(buff));
	bytes = read(finmine, buff, MAX_FILE_COPY_SIZE);
	if (bytes > 0) write(fout, buff, bytes);
	write(fout, "\"\n", 2);

	//close files)
	close(finlibc);
	close(finmine);
	close(fout);
}

/* ----------------------------------------------------------------------------
** Runs a specific test
** --------------------------------------------------------------------------*/
static int		run_test(int test_number)
{
	int				ret_val_mine;
	int				ret_val_libc;
	int				failed = 0;
	FILE			*fpmine, *fplibc;
	int				cmine, clibc;

	printf("Test %4i:  %-42s [",test_number, g_unit_test_names[test_number]);

	//Run test
	ret_val_mine = output_to_file(OUT_ACTUAL, g_unit_tests[test_number]);

	//If the test was not a nocrash_ test
	if (strncmp(g_unit_test_names[test_number], "nocrash_", 8) != 0)
	{
		//Run bench
		ret_val_libc = output_to_file(OUT_EXPECTED, g_bench[test_number]);

		//Evaluate test results
		if (ret_val_mine != ret_val_libc)
			failed = 1;
		else
		{
			fpmine = fopen(OUT_ACTUAL, "r+");
			fplibc = fopen(OUT_EXPECTED, "r+");
			if (!fpmine || !fplibc) {
				perror("error: ");
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
	{
		log_failed_test(test_number, ret_val_libc, ret_val_mine);
		printf(RED "FAIL" RESET);
	}
	else
	{
		printf(GRN "PASS" RESET);
	}
	printf("]\n");

	return failed;
}

/* ----------------------------------------------------------------------------
** Prints a message at the end of all the tests
** --------------------------------------------------------------------------*/
static void	print_end_test_message(int num_tests, int num_passed)
{
	printf("Tests completed. %i/%i tests passed.\n",
			num_passed, num_tests);
	if (num_passed != num_tests)
		printf("See %s for details.\n", TEST_OUTPUT_FILENAME);
}

/* ----------------------------------------------------------------------------
** Runs all the tests that start with [str]
** --------------------------------------------------------------------------*/
void	run_search_tests(char *str)
{
	int fail = 0;
	int num_fails = 0;
	int	num_run = 0;

	for (int i = 0; g_unit_tests[i] != NULL; i++)
	{
		if (strncmp(str, g_unit_test_names[i], strlen(str)) == 0)
		{
			fail = run_test(i);
			num_fails += fail;
			num_run++;
		}
	}
	print_end_test_message(num_run, num_run - num_fails);
}

/* ----------------------------------------------------------------------------
** Runs a range of tests
** --------------------------------------------------------------------------*/
void	run_test_range(int from_num, int to_num)
{
	if (to_num < from_num) to_num = 2147483647;
	int fail = 0;
	int num_fails = 0;
	int	num_run = 0;
	for (int i = from_num; i <= to_num && g_unit_tests[i] != NULL; i++)
	{
		fail = run_test(i);
		num_fails += fail;
		num_run++;
	}
	print_end_test_message(num_run, num_run - num_fails);
}

/* ----------------------------------------------------------------------------
** Runs all the tests
** --------------------------------------------------------------------------*/
void	run_all_tests(void)
{
	run_test_range(0, -1);
}

