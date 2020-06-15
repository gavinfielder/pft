/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:57:57 by gfielder          #+#    #+#             */
/*   Updated: 2020/06/15 16:49:15 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

const t_help_entry	help_index[] = {
	{"basic", help_basic},

	{"tests", help_naming_conventions},
	{"test-naming-conventions", help_naming_conventions},
	{"test_naming_conventions", help_naming_conventions},
	{"test naming conventions", help_naming_conventions},
	{"name", help_naming_conventions},
	{"naming", help_naming_conventions},

	{"d", help_debug},
	{"debug", help_debug},
	{"debugging", help_debug},
	{"lldb", help_debug},
	{"db", help_debug},
	{"debugger-compatibility-mode", help_debug},
	{"debugger_compatibility_mode", help_debug},
	{"debugger compatibility mode", help_debug},

	{"add", help_adding_tests},
	{"adding", help_adding_tests},
	{"adding-tests", help_adding_tests},
	{"adding_tests", help_adding_tests},
	{"adding tests", help_adding_tests},
	{"new", help_adding_tests},
	{"writing tests", help_adding_tests},
	{"writing-tests", help_adding_tests},
	{"writing_tests", help_adding_tests},

	{"wildcard", help_wildcard_search},
	{"wildcard-search", help_wildcard_search},
	{"wildcard_search", help_wildcard_search},
	{"wildcard search", help_wildcard_search},
	{"search", help_wildcard_search},

	{"enable", help_enabling_and_disabling},
	{"disable", help_enabling_and_disabling},
	{"enabling", help_enabling_and_disabling},
	{"disabling", help_enabling_and_disabling},
	{"enabling-tests", help_enabling_and_disabling},
	{"disabling-tests", help_enabling_and_disabling},
	{"enabling tests", help_enabling_and_disabling},
	{"disabling tests", help_enabling_and_disabling},
	{"enabling_tests", help_enabling_and_disabling},
	{"disabling_tests", help_enabling_and_disabling},

	{"options", help_options},
	{"opt", help_options},
	{"-", help_options},

	{"retval", help_return_value},
	{"return", help_return_value},
	{"return-value", help_return_value},
	{"return_value", help_return_value},
	{"return value", help_return_value},
	{"disable-return-value", help_return_value},
	{"disable_return_value", help_return_value},
	{"disable return value", help_return_value},
	{"disabling-return-value", help_return_value},
	{"disabling_return_value", help_return_value},
	{"disabling return value", help_return_value},

	{"how", help_how_it_works},
	{"how-it-works", help_how_it_works},
	{"how_it_works", help_how_it_works},
	{"how it works", help_how_it_works},
	
	{"contact", help_contact},
	{"help", help_contact},
	{"support", help_contact},
	
	{"t", help_timeout},
	{"T", help_timeout},
	{"timeout", help_timeout},
	{"TIMEOUT_SECONDS", help_timeout},

	{"l", help_test_history_logging},
	{"L", help_test_history_logging},
	{"history", help_test_history_logging},
	{"history.csv", help_test_history_logging},
	{"test-history-logging", help_test_history_logging},
	{"test_history_logging", help_test_history_logging},
	{"test history logging", help_test_history_logging},

	{"a", help_include_disabled},
	{"A", help_include_disabled},
	{"include-disabled", help_include_disabled},
	{"include_disabled", help_include_disabled},
	{"include disabled", help_include_disabled},

	{"k", help_leaks_test},
	{"K", help_leaks_test},
	{"leak", help_leaks_test},
	{"leaks", help_leaks_test},
	{"leaks-test", help_leaks_test},
	{"leaks_test", help_leaks_test},
	{"leaks test", help_leaks_test},

	{"x", help_fork_mode},
	{"X", help_fork_mode},
	{"fork", help_fork_mode},
	{"fork-mode", help_fork_mode},
	{"fork_mode", help_fork_mode},
	{"fork mode", help_fork_mode},

	{"s", help_signal_handling},
	{"S", help_signal_handling},
	{"signal", help_signal_handling},
	{"signals", help_signal_handling},
	{"signal-handling", help_signal_handling},
	{"signal_handling", help_signal_handling},
	{"signal handling", help_signal_handling},

	{"i", help_print_info_option},
	{"I", help_print_info_option},
	{"info", help_print_info_option},

	{"r", help_refresh_results},
	{"R", help_refresh_results},
	{"refresh", help_refresh_results},

	{"DEFAULT_RUN_OPTIONS", help_default_run_options},
	{"default", help_default_run_options},
	{"default-run-options", help_default_run_options},
	{"default_run_options", help_default_run_options},
	{"default run options", help_default_run_options},

	{"TEST_OUTDATED_TIME", help_test_outdated_time},
	{"outdated", help_test_outdated_time},
	{"outdated-time", help_test_outdated_time},
	{"outdated_time", help_test_outdated_time},
	{"outdated time", help_test_outdated_time},
	{"test-outdated-time", help_test_outdated_time},
	{"test_outdated_time", help_test_outdated_time},
	{"test outdated time", help_test_outdated_time},

	{"REMOVE_HISTORY_WHEN_TESTS_NEW", help_remove_history_when_tests_new},

	{"LEAKS_TEST_CMD", help_leaks_test_cmd},

	{"TEST_FAIL_LOGGING_MAXBYTES", help_test_fail_logging_maxbytes},

	{"SINGLE_NUMBER_SINGLE_TEST", help_single_number_single_test},

	{"LIBFTPRINTF_DIR", help_libftprintf_dir},

	{"troubleshooting", help_troubleshooting},
	{"troubleshoot", help_troubleshooting},
	{"trouble", help_troubleshooting},

	{"conf", help_conf},
	{"config", help_conf},
	{"current-configuration", help_conf},
	{"current_configuration", help_conf},
	{"current configuration", help_conf},

	{"index", help_list_index},

	{NULL, NULL}
};

void		help_index_search(char *str)
{
	int i = 0;
	while (help_index[i].query != NULL)
	{
		if (strcmp(help_index[i].query, str) == 0)
		{
			help_index[i].print();
			return ;
		}
		i++;
	}
	printf("No help section was found for \"%s\"\n", str);
}

void		help_putchar(char c)
{
	static int code_fmt = 0;

	if (c == '`')
	{
		if (code_fmt == 1)
		{
			printf("\x1B[0m");
			code_fmt = 0;
		}
		else
		{
			printf("\x1B[33m");
			code_fmt = 1;
		}
	}
	else
		printf("%c", c);
}

void		help_header(char *str)
{
	printf(    "  \x1B[1;33m%s\x1B[0m\n" RESET, str);
}

void		help_example(char *str, int recommended)
{
	printf(    "    \x1B[0;36m%s\x1B[0m%s\n", str, (recommended ? "     (recommended usage)" : ""));
}

void		help_example_explain(char *str)
{
	const int	left_indent = 6;
	char	*next;
	char	*tmp;
	int		chars_in_line;
	int		i = 0;

	while (str)
	{
		for (i = 0; i < left_indent; i++)
			printf(" ");
		printf("\x1B[0;2m");
		next = str;
		tmp = str;
		while (next && ((size_t)next - (size_t)str) + left_indent < window_width)
		{
			tmp = next;
			next = strchr(next + 1, ' ');
		}
		chars_in_line = (int)((size_t)tmp - (size_t)str);
		if (next == NULL)
		{
			next = str + strlen(str);
			if (((size_t)next - (size_t)str) + left_indent < window_width)
				chars_in_line = (int)((size_t)next - (size_t)str);
		}
		if (chars_in_line == 0)
			break ;
		for (i = 0; i < chars_in_line; i++)
			help_putchar(str[i]);
		printf("\x1B[0m\n");
		str += chars_in_line;
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
	}
}


void		help_paragraph(char *str)
{
	const int	left_indent = 4;
	char	*next;
	char	*tmp;
	int		chars_in_line;
	int		i = 0;

	while (str)
	{
		for (i = 0; i < left_indent; i++)
			printf(" ");
		next = str;
		tmp = str;
		while (next && ((size_t)next - (size_t)str) + left_indent < window_width)
		{
			tmp = next;
			next = strchr(next + 1, ' ');
		}
		chars_in_line = (int)((size_t)tmp - (size_t)str);
		if (next == NULL)
		{
			next = str + strlen(str);
			if (((size_t)next - (size_t)str) + left_indent < window_width)
				chars_in_line = (int)((size_t)next - (size_t)str);
		}
		if (chars_in_line == 0)
			break ;
		for (i = 0; i < chars_in_line; i++)
			help_putchar(str[i]);
		printf("\n");
		str += chars_in_line;
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
	}
}

void		help_list_item(char *bullet, char *str)
{
	const int left_indent_bullet = 4;
	const int left_indent_str = 8;
	char	*next;
	char	*tmp;
	int		chars_in_line;
	int		i;
	int		bullet_len;
	int		first_line = 1;

	for (i = 0; i < left_indent_bullet; i++)
		printf(" ");
	bullet_len = printf("%s", bullet);
	for (i = 0; i < left_indent_str - left_indent_bullet - bullet_len; i++)
		printf(" ");
	while (str)
	{
		if (!first_line)
		{
			for (i = 0; i < left_indent_str; i++)
				printf(" ");
		}
		next = str;
		tmp = str;
		while (next && ((size_t)next - (size_t)str) + left_indent_str < window_width)
		{
			tmp = next;
			next = strchr(next + 1, ' ');
		}
		chars_in_line = (int)((size_t)tmp - (size_t)str);
		if (next == NULL)
		{
			next = str + strlen(str);
			if (((size_t)next - (size_t)str) + left_indent_str < window_width)
				chars_in_line = (int)((size_t)next - (size_t)str);
		}
		if (chars_in_line == 0)
			break ;
		for (i = 0; i < chars_in_line; i++)
			help_putchar(str[i]);
		printf("\n");
		str += chars_in_line;
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
		first_line = 0;
	}
}

void		help_start_header(void)
{
	printf(GRN "\x1B[32m%.*s\x1B[0m\n", window_width,
			"=============================================================");
	printf("\x1B[32m%.*s\x1B[0m - \x1B[2m%.*s\x1B[0m\n",
			window_width, "  printftester2000 (aka PFT)",
			(window_width - 31 > 0 ? window_width - 31 : 0),
			"made by gfielder@42.us.org");
	printf(GRN "\x1B[32m%.*s\x1B[0m\n", window_width,
			"=============================================================");
}

void		help_basic(void)
{
	help_start_header();
	printf("\n");
	help_header("tl;dr - the simplest way to use PFT");
	printf("\n");
	help_paragraph("To run all '`%s`' tests, run `./test s`");
	printf("\n");
	help_paragraph("You can repeat this for all the specifiers you implement.");
	printf("\n");
	help_header("Usage - Basic Examples");
	help_example("./test mix", 1);
	help_example_explain("Run all tests that start with a string, in this case \"mix\"");
	help_example("./test 42 84", 0);
	help_example_explain("Run the 42nd through 84th tests (of those enabled)");
	help_example("./test 42", 0);
	if (SINGLE_NUMBER_SINGLE_TEST && SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE)
		help_example_explain("Run test 42 (Also turns on debugger compatibility mode)");
	else if (SINGLE_NUMBER_SINGLE_TEST)
		help_example_explain("Run test 42");
	else
		help_example_explain("Run all enabled tests starting at the 42nd");
	help_example("./test", 0);
	help_example_explain("Run all the enabled tests");
	help_example("./test -d \x1B[2;32m[any of the above queries]", 0);
	help_example_explain("Run the selected tests in debugger compatibility mode");
	printf("\n");
	help_header("See Also");
	help_example("./test help tests", 0);
	help_example_explain("View information about the available tests");
	help_example("./test help wildcard-search", 0);
	help_example("./test help debugging", 0);
	help_example("./test help adding-tests", 0);
	help_example("./test help options", 0);
	help_example("./test help enabling-tests", 0);
	help_example("./test help disabling-tests", 0);
	help_example("./test help conf", 0);
	help_example_explain("Display details of your current configuration");
	help_example("./test help index", 0);
	help_example_explain("Show all possible help queries");

}

void		help_wildcard_search(void)
{
	help_header("Wildcard Search");
	help_paragraph("All alphabetic queries have an implicit wildcard at the end");
	printf("\n");
	help_example("./test \"*af\"", 0);
	help_example_explain("Run all the tests that have 'af' in the test name");
	help_example("./test \"*null*prec\"", 0);
	help_example_explain("Run tests that have a 'null' followed by a 'prec' in the name");
	help_example("./test \"s_*prec\"", 0);
	help_example_explain("Run tests that start with 's_' and have a 'prec' in the name");
	printf("\n");
	help_paragraph("The double quotes are for escaping the *. If your shell does not escape the * inside double quotes, you can either escape it manually, or use any other character that is not alphanumeric or underscore as the wildcard character.");
	printf("\n");
	help_example("./test s_@prec", 0);
	help_example_explain("Run tests that start with 's_' and have a 'prec' in the name");
}

void		help_naming_conventions(void)
{
	help_header("Test Naming Conventions");
    help_paragraph("This help section is out of date. `Please see https://github.com/gavinfielder/pft/wiki/Test-Naming-Conventions` for the latest information.");
	//help_list_item("-", "d, i, o, u, x, X, c, s, p, f tests start with `d_`, `i_`, `o_`, etc.");
	//help_list_item("-", "Tests of strings with no specifiers start with `nospec_`");
	//help_list_item("-", "%% tests start with `pct_`");
	//help_list_item("-", "hh, h, l, ll tests usually have '`size`' in the name");
	//help_list_item("-", "L (long double) tests start with `f_L_`");
	//help_list_item("-", "# tests usually have '`af`' in the name");
	//help_list_item("-", "0 (zero padding) tests usually have '`zp`' in the name");
	//help_list_item("-", "- (left justify) tests usually have '`lj`' in the name");
	//help_list_item("-", "+ tests usually have '`as`' in the name");
	//help_list_item("-", "' ' (space padding) tests usually have '`sp`' in the name");
	//help_list_item("-", "Precision tests usually have '`prec`' in the name");
	//help_list_item("-", "Field width tests usually have '`width`' or just '`w`' in the name");
	//help_list_item("-", "Simple tests usually have '`basic`' in the name");
	//help_list_item("-", "Tests taken from moulinette files start with `moul_`");
	//help_list_item("-", "The `moul_` block has subgroups `moul_d_`, `moul_i_`, `moul_o_`, etc.");
	//help_list_item("-", "Tests adapated from 42FileChecker or moulitest have '`ftfc`' in the name");
	//help_list_item("-", "Tests that throw a '...flag is ignored when...' have `_ignoreflag`");
	//help_list_item("-", "Tests that throw some other warning have `_throwswarning`");
	//help_list_item("-", "* tests have `star` in the name.");


	//printf("\n");
	//help_header("Other Specific Test Blocks");
	//help_list_item("-", "`mix_` are tests that combine multiple specifiers at random");
	//help_list_item("-", "`f_stress_` and `f_L_stress_` are float stress tests. Don't worry if you don't pass some of these.");
	//help_list_item("-", "`f_reserved_values_` and `f_L_reserved_values_` are tests of special floating-point values (inf, -inf, NaN, negative zero). As of the time of writing this, they are not mandatory. They are disabled by default.");
	//help_list_item("-", "`nocrash_` is a specially-handled prefix. `nocrash_` tests will pass as long as ft_printf doesn't crash while executing them. They are disabled by default");
	//help_list_item("-", "`argnum_` are tests for the arbitrary argument selector '$'. They are disabled by default");
	//help_list_item("-", "`moul_notmandatory_` are moulinette tests that used to be mandatory but are now bonuses. They are disabled by default.");
	//help_list_item("-", "`moul_D` and `moul_F` are also tests that used to be mandatory but are now bonuses. They are disabled by default.");
	//printf("\n");
	//help_header("See Also");
	//help_example("./test help enabling-tests", 0);
	//help_example("./test help disabling-tests", 0);
}

void		help_debug(void)
{
	help_header("Running PFT with LLDB or other debuggers");
	help_paragraph("PFT must run in debugger compatibility mode to work with debuggers. You must also include the -g flag in your own Makefile. The following works with your current configuration:");
	printf("\n");
	if (SINGLE_NUMBER_SINGLE_TEST && SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE)
	{
		help_example("lldb ./test 42", 0);
		help_example_explain("Debug test 42");
	}
	help_example("lldb ./test -d [query]", 0);
	help_example_explain("Debug the selected tests");
}

void		help_adding_tests(void)
{
	help_header("Adding Tests");
	help_paragraph("All tests are located in `unit_tests.c`. You can add your own tests to this file, followng the same format as the existing tests. A valid unit test has the prototype:");
	help_paragraph("    `int   foo(void)`");
	help_paragraph("and includes a call to the function:");
	help_paragraph("    `int   test(const char *fmt, ...)`");
	help_paragraph("You do not have to do anything except write the test in unit_tests.c and re-make. The new tests will be included in the test index, and can be queried the same way.");
	printf("\n");
	help_paragraph("If you need variables, you must either declare them as static outside the function or declare them as NOT static inside the function. Any variable declaration outside this guideline will likely cause compile errors.");
}

void		help_enabling_and_disabling(void)
{
	help_header("Enabling and Disabling Tests");
	help_paragraph("Scripts are provided to enable and disable tests. These use the same format as `./test [query]`");
	printf("\n");
	help_example("./enable-test nocrash", 0);
	help_example_explain("Enables all the tests that start with 'nocrash'");
	help_example("./disable-test \"f_L*prec\"", 0);
	help_example_explain("Disables tests that start with 'f_L' and includes 'prec'");
	help_example("./disable-test 42 84", 0);
	help_example_explain("Disables tests 42 to 84");
}

void		help_return_value(void)
{
	help_header("The Return Value (aka Why are all my tests failing?)");
	help_paragraph("By default, this tester first checks your ft_printf return value. As of the time of writing this, moulinette does not check the ft_printf return value. `options-config.ini` has an option for disabling this behavior and only checking output, if you want to ignore the return value. I do not endorse it, but it's an option.");
}

void		help_how_it_works(void)
{
	help_header("How it Works, in Brief");
	help_paragraph("The Makefile creates two copies of unit_tests.c, one that uses ft_printf, and one that uses printf. For each test, it calls both functions and tests their return value and output.");
}

void		help_contact(void)
{
	help_header("Contact, Support, Feedback");
	help_paragraph("   intra & slack: \x1B[1;36mgfielder\x1B[0m");
	help_paragraph("If you have any problems using this tester, let me know. I highly appreciate knowing how to make it easier to use.");
}

void		help_options(void)
{
	help_header("Run Options");
	help_paragraph("Run `./test help [option]` for more information.");
	help_list_item("-d","debugger compatibility mode");
	help_list_item("-t","timeout on");
	help_list_item("-T","timeout off");
	help_list_item("-l","test history logging on");
	help_list_item("-L","test history logging off");
	help_list_item("-a","include disabled tests");
	help_list_item("-A","do not include disabled tests");
	help_list_item("-k","leaks test (BETA) on");
	help_list_item("-K","leaks test (BETA) off");
	help_list_item("-x","fork mode on");
	help_list_item("-X","fork mode off");
	help_list_item("-s","signal handling on");
	help_list_item("-S","signal handling off");
	help_list_item("-i","print run info before tests");
	help_list_item("-I","do not print run info before tests");
	help_list_item("-r","refresh test results each run");
	help_list_item("-R","append to existing test results each run");
	printf("\n");
	help_header("Additional options when test history logging is enabled");
	help_aux_filter_options();
	printf("\n");
	help_header("Options in the PFT Config File");
	help_paragraph("These options are available in `options-config.ini`:");
	help_list_item("IGNORE_RETURN_VALUE", "  whether to ignore the ft_printf return value in testing.");
	help_list_item("TIMEOUT_SECONDS", "  the timeout duration in seconds.");
	help_list_item("DEFAULT_RUN_OPTIONS", "  the options selected as the default program behavior");
	help_list_item("TEST_OUTDATED_TIME", "  the number of seconds for a test history to become outdated");
	printf("\n");
	help_paragraph("See `options-config.ini` and/or readme for more advanced options.");
	printf("\n");
	help_header("See Also");
	help_example("./test help conf", 0);
}

void		help_aux_filter_options(void)
{
	help_list_item("-=...", " select only the following");
	help_list_item("--...", " exclude the following");
	help_list_item("-+...", " include the following");
	help_paragraph("Where '...' is one or more of:");
	help_list_item("f","recently failed tests");
	help_list_item("p", "recently passed tests");
	help_list_item("o", "outdated tests");
	help_list_item("n", "tests with no history");
}

void		help_timeout(void)
{
	help_header("Timeout");
	help_paragraph("  on: `-t`   off: `-T`");
	help_paragraph("This optional feature fails tests after a specified interval of time. The timeout period can be specified in `options-config.ini`. Only available in fork mode.");
}

void		help_test_history_logging(void)
{
	help_header("Test History Logging");
	help_paragraph("  on: `-l`   off: `-L`");
	help_paragraph("By default, PFT will track the last time each test passes and fails, and print information about the most recent run of each test. Tests' history will also become 'outdated' if their age exceeds the value set in `options-config.ini`. This feature also allows selecting tests to run by whether they have recently passed or failed.");
	printf("\n");
	help_paragraph("By default, the PFT Makefile removes the test history whenever unit_tests.c is strictly newer. This prevents the test history from becoming corrupted when you add your own tests (potentially changing the test numbers). By default the enable-test and disable-test scripts, as they modify unit_tests.c, will trigger such removal of history.csv. There is an option in `options-config.ini` to disable the history removal behavior, as well as an option in each of these scripts to touch history.csv to prevent the removal trigger. Use these options at your own discretion.");
	printf("\n");
	help_header("Filtering Tests by History");
	help_aux_filter_options();
	printf("\n");
	help_header("Examples:");
	printf("\n");
	help_example("./test --p x", 0);
	help_example_explain("Run tests that start with 'x', but exclude tests that recently passed");
	help_example("./test -d=po nocrash", 0);
	help_example_explain("Run tests in debug mode that start with 'nocrash' that either recently passed or are outdated");
	help_example("./test -=f s", 0);
	help_example_explain("Run only recently failed tests that start with 's'");
}

void		help_include_disabled(void)
{
	help_header("Include Disabled Tests");
	help_paragraph("  on: `-a`   off: `-A`");
	help_paragraph("When this option is on, disabled tests will be treated as if they are enabled.");
}

void		help_leaks_test(void)
{
	help_header("Leaks Test (BETA)");
	help_paragraph("  on: `-k`   off: `-K`");
	help_paragraph("When this option is on, a leaks test command will run after all tests are completed. This disables fork mode. Leaks test will not run when any test segfaulted or otherwise terminated abnormally (as in this case leaks can come from PFT).");
	printf("\n");
	help_paragraph("The default leaks testing method is to call `leaks(1)` via `system(3)`. You can specify a different method with the `LEAKS_TEST_CMD` option in `options-config.ini`.");
	printf("\n");
	help_paragraph("This feature is still being tested. Do not rely on it completely.");
}

void		help_fork_mode(void)
{
	help_header("Fork Mode");
	help_paragraph("  on: `-x`   off: `-X`");
	help_paragraph("By default, PFT calls ft_printf only on forked child processes to improve stability. Turning this option off means that tests will run in a single process and a single thread. Timeout is not available when fork mode is off.");
}

void		help_signal_handling(void)
{
	help_header("Signal Handling");
	help_paragraph("  on: `-s`   off: `-S`");
	help_paragraph("(only applies to non-fork mode) When this option is off, signals will not be caught by PFT and PFT will stop immediately when a test aborts abnormally. When this option is on, abnormal terminations by certain signals will be caught by PFT and tests will continue running.");
}

void		help_print_info_option(void)
{
	help_header("Print Run Info");
	help_paragraph("  on: `-i`   off: `-I`");
	help_paragraph("When this option is on, information about the current run, configuration, and options will be shown before each test run.");
}

void		help_refresh_results(void)
{
	help_header("Print Run Info");
	help_paragraph("  on: `-r`   off: `-R`");
	help_paragraph("When this option is on, the test results file will be deleted before each new test run and thus only show results of any failed tests in the most recent run. When this option is off, new test results will be appended to any existing test results.");
}

void		help_default_run_options(void)
{
	help_header("DEFAULT_RUN_OPTIONS");
	help_paragraph("This option in `options-config.ini` determines the default program behavior. Running `./test [query]` with no command line options will run with the default run options selected using this variable. Any options given as command line options at program execution will override the relevant options set as the default. Options are processed from left to right.");
	printf("\n");
	help_header("See Also");
	help_example("./test help options", 0);
}

void		help_test_outdated_time(void)
{
	help_header("TEST_OUTDATED_TIME");
	help_paragraph("This option in `options-config.ini` determines the number of seconds before a test result timestamp in the history log becomes 'outdated' instead of recently passed or recently failed. The default is 900 (15 minutes). You can set this value to 0 to always consider tests results outdated, or to 9999999 to never consider test results outdated, or anything in between.");
	printf("\n");
	help_header("See Also");
	help_example("./test help history", 0);
}

void		help_remove_history_when_tests_new(void)
{
	help_header("REMOVE_HISTORY_WHEN_TESTS_NEW");
	help_paragraph("This option in `options-config.ini` determines whether the Makefile will remove the history log whenever unit_tests.c is strictly newer. There are also options in the enable-test and disable-test scripts that can prevent the removal trigger when these scripts are used.");
	printf("\n");
	help_header("See Also");
	help_example("./test help history", 0);
}

void		help_leaks_test_cmd(void)
{
	help_header("LEAKS_TEST_CMD");
	help_paragraph("This option in `options-config.ini` is the C macro that will run whenever the leaks test (`-k`) is slected. You may modify this command to use a different leaks testing method.");
	printf("\n");
	help_header("See Also");
	help_example("./test help leaks", 0);
}

void		help_test_fail_logging_maxbytes(void)
{
	help_paragraph("You have reached a help section that has not yet been written. Please refer to the readme");
}

void		help_single_number_single_test(void)
{
	help_paragraph("You have reached a help section that has not yet been written. Please refer to the readme");
}

void		help_single_test_turns_on_lldb_compat_mode(void)
{
	help_paragraph("You have reached a help section that has not yet been written. Please refer to the readme");
}

void		help_libftprintf_dir(void)
{
	help_header("LIBFTPRINTF_DIR");
	help_paragraph("This option in `options-config.ini` allows for nonstandard installations. You can specify the path in which your ft_printf project can be found.");
}

void		help_troubleshooting(void)
{
	help_header("My test results show the same string and the same return value. Why am I failing this test?");
	help_paragraph("Some text editors don't show you nonprintable characters. Open results.txt in vim first. If it still shows identical in vim, let me know because it could be a bug.");
	help_header("Help! Wildcard search isn't working!");
	help_paragraph("For almost all shell terminals, the `*` needs to be escaped--usually, putting a string in double quotes is sufficient, but some terminals still treat it as a shell `*` even then. You can either escape it manually '`\\*`', or, to make this feature compatible with all shells, I've made any character not valid for a C function name (alphanumeric + underscore) is now considered a wildcard. This means instead of `\\*`, you can also use `@`, or anything else your terminal doesn't recognize as a special character. The same is true for the enable-test and disable-test scripts.");
	printf("\n");
	help_header("Other Issues");
	help_paragraph("If something goes wrong--slack me @gfielder. I like testing, like people using good testing, and want to make this easier to use, so don't hesitate to contact me.");
}

void		help_list_index(void)
{
	help_header("All Possible Help Queries");
	int i = 0;
	while (help_index[i].query != NULL)
	{
		help_paragraph((char *)(help_index[i].query));
		i++;
	}
}














