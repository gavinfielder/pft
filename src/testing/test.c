/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:53:02 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 20:42:28 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
static int	g_test_num;

/* ----------------------------------------------------------------------------
** Runs a specific test
** --------------------------------------------------------------------------*/
static int		run_test(int test_number)
{
	int		fail;

	g_test_num = test_number;
	printf("Test %4i:  %-42s [",test_number, g_unit_test_names[test_number]);
	fail = g_unit_tests[test_number]();
	if (fail)
		printf(RED "FAIL" RESET);
	else
		printf(GRN "PASS" RESET);
	printf("]\n");
	return (fail);
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
			g_test_num = i;
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
		g_test_num = i;
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
** Calls a vprintf function and outputs the result to a file
** --------------------------------------------------------------------------*/
static int	output_to_file(const char *fmt, va_list args, char *filename, vprintf_func f)
{
	fpos_t		pos;
	int			fd = dup(fileno(stdout));
	int			ret;

	//Set up
	fgetpos(stdout, &pos);
	freopen(filename, "w+", stdout);
	//Write to file
	ret = f(fmt, args);
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
** Main interface for unit tests; returns 1 if fail, 0 if pass
** --------------------------------------------------------------------------*/
int		test(const char *fmt, ...)
{
	va_list			args;
	va_list			args_copy;
	int				ret_val_mine;
	int				ret_val_libc;
	int				failed = 0;
	FILE			*fpmine, *fplibc;
	int				cmine, clibc;

	va_start(args, fmt);
	//Run ft_vprintf
	va_copy(args_copy, args);
	ret_val_mine = output_to_file(fmt, args_copy, OUT_ACTUAL, ft_vprintf);
	va_end(args_copy);
	//Run vprintf
	va_copy(args_copy, args);
	ret_val_libc = output_to_file(fmt, args_copy, OUT_EXPECTED, vprintf);
	va_end(args_copy);
	va_end(args);

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

	if (failed)
	{
		log_failed_test(g_test_num, ret_val_libc, ret_val_mine);
		return 1;
	}
	return failed;
}

/*
int		test_asprintf(const char *fmt, ...)
{
	va_list			args;
	va_list			args_copy;
	t_stringbuilder	*sb;
	char			*ret_mine;
	char			*ret_sys;
	int				ret_val_mine;
	int				ret_val_sys;
	int				failed = 0;
	int				fd;
	
	//initialize test
	sb = ft_sbnew();
	va_start(args, fmt);
	va_copy(args_copy, args);
	//get mine
	ret_val_mine = ft_vsbprintf(sb, fmt, args);
	ret_mine = ft_sbtostr(sb);
	//get system
	ret_val_sys = vasprintf(&ret_sys, fmt, args_copy);
	//compare
	if (ret_val_mine != ret_val_sys || strcmp(ret_mine, ret_sys) != 0)
		failed = 1;
	if (failed)
	{
		fd = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
		dprintf(fd, "Test %3i (%s) : FAILED.\n", g_test_num, g_unit_test_names[g_test_num]);
		dprintf(fd, "    Returned expected %i, actual %i\n",
				ret_val_sys, ret_val_mine);
		dprintf(fd, "      expected: \"%s\"\n", ret_sys);
		dprintf(fd, "      actual:   \"%s\"\n", ret_mine);
		close(fd);
	}
	//clean up
	ft_sbdel(&sb);
	free(ret_mine);
	free(ret_sys);
	va_end(args);
	va_end(args_copy);
	return (failed);
}*/


void	append_to_log(const char *fmt, ...)
{
	va_list			args;
	int				fd;
	
	va_start(args, fmt);
	fd = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
	{
		vdprintf(fd, fmt, args);
		close(fd);
	}
	va_end(args);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:27:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 22:20:15 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int			assert_int(int actual, int expected)
{
	if (actual != expected)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=%i, expected=%i\n",
				g_test_num, g_unit_test_names[g_test_num], actual, expected);
		return (1);
	}
	return (0);
}

int			assert_size_t(size_t actual, size_t expected)
{
	if (actual != expected)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=%lu, expected=%lu\n",
				g_test_num, g_unit_test_names[g_test_num], actual, expected);
		return (1);
	}
	return (0);
}

int			assert_long_long(long long actual, long long expected)
{
	if (actual != expected)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=%lli, expected=%lli\n",
				g_test_num, g_unit_test_names[g_test_num], actual, expected);
		return (1);
	}
	return (0);
}

int			assert_str(char *actual, char *expected)
{
	if (strcmp(actual, expected) != 0)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=\"%s\", expected=\"%s\"\n",
				g_test_num, g_unit_test_names[g_test_num], actual, expected);
		return (1);
	}
	return (0);
}
