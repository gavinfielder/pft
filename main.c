/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 01:32:42 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/25 01:54:25 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/25 01:32:24 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_unit_tester_args		*failsafe_args_recover;

static void		print_help(int extended)
{
	printf(GRN "=============================================================\n" RESET);
	printf(GRN "  printftester2000 (aka PFT)\x1B[0m - \x1B[2mmade by gfielder@42.us.org\n" RESET);
	printf(GRN "=============================================================\n" RESET );
	printf(    "  Run ft_printf unit tests by name or number\n");
	printf("\n");
	printf(    "  \x1B[1;33mBasic Examples:\n" RESET);
	printf(    "    \x1B[0;36m./test moul       \x1B[0m (recommended usage)\n");
	printf(    "      \x1B[0m\x1B[2mRun all tests that start with a string, in this case \"moul\"\n" RESET);
	printf(    "    \x1B[0;36m./test 42 84\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun the 42nd through 84th tests (of those enabled)\n" RESET);
	printf(    "    \x1B[0;36m./test 42\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun all the enabled tests starting at the 42nd\n" RESET);
	printf(    "    \x1B[0;36m./test\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun all the enabled tests\n" RESET);
	printf("\n");
	printf(    "  \x1B[1;33mWildcard Search:\n" RESET);
	printf(    "    All alphabetic queries have an implicit wildcard at the end\n");
	printf("\n");
	printf(    "    \x1B[0;36m./test \"*af\"\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun all the tests that have 'af' anywhere in the test name\n" RESET);
	printf(    "    \x1B[0;36m./test \"*null*prec\"\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun tests that have a 'null' followed by a 'prec' in the name\n" RESET);
	printf(    "    \x1B[0;36m./test \"s_*prec\"\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun tests that start with 's_' and have a 'prec' in the name\n" RESET);
	printf("\n");
	printf(    "    The double quotes are for escaping the *. If your shell\n");
	printf(    "    does not escape the * inside double quotes, you can either\n");
	printf(    "    escape it manually, or use any other character that is not\n");
	printf(    "    alphanumeric or underscore as the wildcard character.\n");
	printf("\n");
	printf(    "    \x1B[0;36m./test s_@prec\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun tests that start with 's_' and have a 'prec' in the name\n" RESET);
	printf("\n");
	printf(    "  \x1B[1;33mTest Naming Conventions:\n" RESET);
	printf(    "    - d, i, o, u, x, X, c, s, p, f tests start with \x1B[33md_\x1B[0m, \x1B[33mi_\x1B[0m, \x1B[33mo_\x1B[0m, etc.\n");
	printf(    "    - %%%% tests start with \x1B[33mpct_\x1B[0m\n");
	printf(    "    - hh, h, l, ll tests usually have '\x1B[33msize\x1B[0m' in the name\n");
	printf(    "    - L (long double) tests start with \x1B[33mf_L_\x1B[0m\n");
	printf(    "    - # tests usually have '\x1B[33maf\x1B[0m' in the name (or '\x1B[33maltform\x1B[0m')\n");
	printf(    "    - 0 (zero padding) tests usually have '\x1B[33mzp\x1B[0m' in the name\n");
	printf(    "    - - (left justify) tests usually have '\x1B[33mlj\x1B[0m' in the name\n");
	printf(    "    - + tests usually have '\x1B[33mas\x1B[0m' or '\x1B[33mallsign\x1B[0m' in the name\n");
	printf(    "    - ' ' (space padding) tests usually have '\x1B[33msp\x1B[0m' in the name\n");
	printf(    "    - Precision tests usually have '\x1B[33mprec\x1B[0m' in the name\n");
	printf(    "    - Field width tests usually have '\x1B[33mwidth\x1B[0m' or just '\x1B[33mw\x1B[0m' in the name\n");
	printf(    "    - Simple tests usually have '\x1B[33mbasic\x1B[0m' in the name\n");
	printf(    "    - Tests taken from moulinette files start with \x1B[33mmoul_\x1B[0m\n");
	printf(    "    - The \x1B[33mmoul_\x1B[0m block has subgroups \x1B[33mmoul_d_\x1B[0m, \x1B[33mmoul_i_\x1B[0m, \x1B[33mmoul_o_\x1B[0m, etc.\n");
	printf(    "    - Tests adapated from 42FileChecker have '\x1B[33mftfc\x1B[0m' in the name\n");
	printf("\n");
	if (!extended) {
		printf("  Run \x1B[0;36m./test help all\x1B[0m  to see more.\n");
		return ;
	}
	printf(    "  \x1B[1;33mOther Specific Test Blocks\n" RESET);
	printf(    "    - \x1B[33mmix_\x1B[0m are tests that combine multiple specifiers at random\n");
	printf(    "    - \x1B[33mf_stress_\x1B[0m and \x1B[33mf_L_stress_\x1B[0m are float stress tests. Don't worry\n");
	printf(    "      if you don't pass some of these.\n");
	printf(    "    - \x1B[33mf_reserved_values_\x1B[0m and \x1B[33mf_L_reserved_values_\x1B[0m are tests of\n");
	printf(    "      special floating-point values (inf, -inf, NaN, negative zero).\n");
	printf(    "      As of the time of writing this, they are not mandatory.\n");
	printf(    "    - \x1B[33mnocrash_\x1B[0m is a specially-handled prefix. \x1B[33mnocrash_\x1B[0m tests will\n");
	printf(    "      pass as long as ft_printf doesn't crash while executing them.\n");
	printf(    "    - \x1B[33margnum_\x1B[0m are tests for the arbitrary argument selector '$'\n");
	printf(    "    - \x1B[33mmoul_notmandatory_\x1B[0m are moulinette tests that used to be\n");
	printf(    "      mandatory but are now bonuses\n");
	printf(    "    - \x1B[33mmoul_D\x1B[0m and \x1B[33mmoul_F\x1B[0m are also tests that used to be\n");
	printf(    "      mandatory but are now bonuses\n");
	printf("\n");
	printf(    "  \x1B[1;33mAdding Tests\n" RESET);
	printf(    "    All tests are located in \x1B[32munit_tests.c\x1B[0m. You can add your own\n");
	printf(    "    tests to this file. A valid unit test has the prototype:\n");
	printf(    "        \x1B[35mint   foo(void)\n" RESET);
	printf(    "    and includes a call to the function:\n");
	printf(    "        \x1B[35mint   test(const char *fmt, ...)\n" RESET);
	printf(    "    You do not have to do anything except write the test in\n");
	printf(    "    unit_tests.c and re-make. The new tests will be included\n");
	printf(    "    in the test index, and can be queried the same way.\n");
	printf("\n");
	printf(    "  \x1B[1;33mEnabling and Disabling Tests\n" RESET);
	printf(    "    Shell scripts are provided to enable and disable tests based\n");
	printf(    "    on alphabetic query. Follows the same format as ./test [query]\n");
	printf(    "    Numeric ranges are not supported for these scripts.\n");
	printf("\n");
	printf(    "    \x1B[0;36m./enable-test nocrash\n" RESET);
	printf(    "      \x1B[0m\x1B[2mEnables all the tests that start with 'nocrash'\n" RESET);
	printf(    "    \x1B[0;36m./disable-test \"f_L*prec\"\n" RESET);
	printf(    "      \x1B[0m\x1B[2mDisables tests that start with 'f_L' and includes 'prec'\n" RESET);
	printf("\n");
	printf(    "  \x1B[1;33mThe Return Value (aka Why are all my tests failing?)\n" RESET);
	printf(    "    By default, this tester first checks your ft_printf return value.\n");
	printf(    "    As of the time of writing this, moulinette does not check the\n");
	printf(    "    ft_printf return value. The PFT Makefile has an option for\n");
	printf(    "    disabling this behavior and only checking output, if you want to\n");
	printf(    "    ignore the return value. I do not endorse it, but it's an option.\n");
	printf("\n");
	printf(    "  \x1B[1;33mHow it Works, in Brief\n" RESET);
	printf(    "    The Makefile creates two copies of unit_tests.c, one that\n");
	printf(    "    uses ft_printf, and one that uses printf. For each test, it\n");
	printf(    "    calls both functions and tests their return value and output.\n");
	printf("\n");
	printf(    "  \x1B[1;33mContact, Support, Feedback\n" RESET);
	printf(    "       intra & slack: \x1B[1;36mgfielder\x1B[0m\n");
	printf(    "    If you have any problems using this tester, let me know. I highly\n");
	printf(    "    appreciate knowing how to make it easier to use.\n");
	printf("\n");

}
	

static void		init_args(t_unit_tester_args *args, char *pattern,
					int from, int to, t_unit_tester_func f)
{
	args->pattern = pattern;
	args->from = from;
	args->to = to;
	args->current = from;
	args->num_fails = 0;
	args->num_run = 0;
	args->run = f;
	//Back up stdout
	args->fd_stdout_dup = dup(fileno(stdout));
}

static void		unit_testing(int argc, char **argv)
{
	t_unit_tester_args		args;
	failsafe_args_recover = &args;
	int from, to;

	if (argc > 1)
	{
		if (DEBUG) printf("argv[1] = \"%s\"\n", argv[1]);
		if (!(argv[1][0] >= '0' && argv[1][0] <= '9'))
		{
			//Search pattern
			if (DEBUG) printf("Searching tests with pattern: \"%s\"\n", argv[1]);
			init_args(&args, argv[1], 0, 2147483647, run_search_tests);
			run_search_tests(&args);
		}
		else
		{
			from = atoi(argv[1]);
			if (argc > 2)
				to = atoi(argv[2]);
			else
				to = 2147483647;
			if (DEBUG) printf("Running tests on range [%i, %i]\n", from, to);
			init_args(&args, NULL, from, to, run_test_range);
			run_test_range(&args);
		}
	}
	else
	{
		//No arguments. Run all tests
		if (DEBUG) printf("Running All Tests...\n");
		from = 0;
		to = 2147483647;
		init_args(&args, NULL, from, to, run_test_range);
		run_test_range(&args);
	}
}

int main(int argc, char **argv)
{
	if (argc > 1 && strcmp(argv[1], "help") == 0)
	{
		if (argc == 3 && strcmp(argv[2], "all") == 0)
			print_help(1);
		else
			print_help(0);
	}
	else
		unit_testing(argc, argv);
	return (0);
}










