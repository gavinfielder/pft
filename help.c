/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:57:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/27 20:41:28 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void		print_help(int extended)
{
	printf(GRN "=============================================================\n" RESET);
	printf(GRN "  printftester2000 (aka PFT)\x1B[0m - \x1B[2mmade by gfielder@42.us.org\n" RESET);
	printf(GRN "=============================================================\n" RESET );
	printf(    "  Run ft_printf unit tests by name or number\n");
	printf("\n");
	printf(    "  \x1B[1;33mBasic Examples:\n" RESET);
	printf(    "    \x1B[0;36m./test mix       \x1B[0m (recommended usage)\n");
	printf(    "      \x1B[0m\x1B[2mRun all tests that start with a string, in this case \"mix\"\n" RESET);
	printf(    "    \x1B[0;36m./test 42 84\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun the 42nd through 84th tests (of those enabled)\n" RESET);
	printf(    "    \x1B[0;36m./test 42\n" RESET);
	if (SINGLE_NUMBER_SINGLE_TEST)
	{
		printf(    "      \x1B[0m\x1B[2mRun test 42%s\n" RESET,
			((SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE) ? " (Also turns on debug compatibility mode)" : ""));
	}
	else
	{
		printf(    "      \x1B[0m\x1B[2mRun all the enabled tests starting at the 42nd\n" RESET);
	}
	printf(    "    \x1B[0;36m./test\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun all the enabled tests\n" RESET);
	printf(    "    \x1B[0;36m./test -d \x1B[2;32m[any of the above queries]\n" RESET);
	printf(    "      \x1B[0m\x1B[2mRun the selected tests in debug compatibility mode\n" RESET);
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
	printf(    "  \x1B[1;33mRunning PFT with LLDB or other debuggers\n" RESET);
	printf(    "    PFT must run in debugger compatibility mode to work with debuggers.\n");
	printf(    "    The following works with your current configuration:\n");
	printf("\n");
	if (SINGLE_NUMBER_SINGLE_TEST && SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE)
	{
		printf(    "    \x1B[0;36mlldb ./test 42\n" RESET);
		printf(    "      \x1B[0m\x1B[2mDebug test 42\n" RESET);
	}
	printf(    "    \x1B[0;36mlldb ./test -d \x1B[2;32m[query]\n" RESET);
	printf(    "      \x1B[0m\x1B[2mDebugs the selected tests.\n" RESET);
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
	printf(    "  \x1B[1;33mAdvanced Options\n" RESET);
	printf(    "    See Readme for descriptions of these options and more.\n");
	printf(    "    The current configuration can be changed in the PFT Makefile.\n\n");
	if (USE_TIMEOUT)
	{
		printf(    "    current configuration: timeouts enabled\n");
		printf(    "    command line option:  \x1B[33m-T\x1B[0m turns off timeouts.\n");
	}
	else if (RUN_TESTS_AS_FORK)
	{
		printf(    "    current configuration: timeouts disabled but available\n");
		printf(    "    command line option:  \x1B[33m-t\x1B[0m turns on timeouts.\n");
	}
	else
	{
		printf(    "    current configuration: fork mode and timeouts are disabled\n");
		printf(    "    command line options: \x1B[33m-ft\x1B[0m turns on fork mode with timeouts.\n");
	}
	if (RUN_TESTS_AS_FORK)
	{
		printf(    "    current configuration: fork mode is enabled.\n");
		printf(    "    command line option:  \x1B[33m-F\x1B[0m turns off fork mode (also disables timeout).\n");
	}
	else
	{
		printf(    "    current configuration: fork mode is disabled.\n");
		printf(    "    command line option:  \x1B[33m-f\x1B[0m turns on fork mode.\n");
	}
	printf(    "    command line options: \x1B[33m-f\x1B[0m / \x1B[33m-t\x1B[0m force fork mode / timeout\n");
	printf(    "    and will override debug compatibility mode.\n");
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
	

