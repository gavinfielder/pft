/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_and_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:08:06 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/03 01:31:38 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include "test.h"

/* ----------------------------------------------------------------------------
** For responsive window size
** --------------------------------------------------------------------------*/

static uint16_t	window_width = 0;
static const char *test_start_fmt_str = "Test %4i:  %-42s [";
static const char *test_history_fmt_str = "   \x1B[2mPrev: %s\x1B[0m";

uint16_t		tty_get_window_width(void)
{
	struct ttysize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ts_cols);
}

void			init_printing(void)
{
	window_width = tty_get_window_width();
	if (DEBUG)
		printf("window width: %hu\n", window_width);
	if (window_width < 74)
	{
		test_start_fmt_str = "%4i: %-42s [";
		if (window_width < 68)
		{
			test_history_fmt_str = "\n    \x1B[2m Previous result: %s\x1B[0m";
			if (window_width < 55)
			{
				test_start_fmt_str = "%4i: %30.30s... [";
			}
		}
	}
}

/* ----------------------------------------------------------------------------
** Prints information about the current test run
** --------------------------------------------------------------------------*/

void		print_configuration_info(const t_pft_options options,
				const t_unit_tester_args args)
{
	int		num;
	time_t	now;
	char	date_and_time[27];

	if (!get_option_printinfo())
		return ;
	bzero(date_and_time, 27);
	now = time(NULL);
	ctime_r(&now, date_and_time);
	int max_eq = (((int)(window_width)) - 30) / 2;
	printf("%.*s PFT Run: %19.19s %.*s\n",
		max_eq,                      "================",
		date_and_time,
		max_eq + (window_width % 2), "================");
	//Line 1: First print the query
	printf("  ");
	if (args.run == run_test_range && args.from == args.to)
		printf("Running test %i", args.from);
	else if (args.run == run_test_range && args.to == 2147483647)
		printf("Running test %i to end", args.from);
	else if (args.run == run_test_range)
		printf("Running test %i to %i", args.from, args.to);
	else if (args.run == run_search_tests)
		printf("Running \"%s*\" tests", args.pattern);
	else
		printf("Unknown query type. Contact gfielder about this error.");
	//Next print the filters
	if (options.log_history)
	{
		num = 0;
		printf(" with history:");
		if (options.filter_run_passing)
		{
			printf("pass");
			num++;
		}
		if (options.filter_run_failing)
			printf("%sfail", ((num++) ? "," : ""));
		if (options.filter_run_outdated)
			printf("%soutdated", ((num++) ? "," : ""));
		if (options.filter_run_nohistory)
			printf("%snone", ((num++) ? "," : ""));
		printf("");
	}
	if (options.filter_run_disabled)
		printf(" include disabled");
	printf("\n");
	//Line 2: print the execution mode
	printf("  ");
	if (options.run_test == run_test_fork)
	{
		printf("Running in fork mode");
		if (options.use_timeout)
			printf(" with timeout enabled");
		else
			printf(" with timeout disabled");
		printf("\n");
	}
	else if (options.run_test == run_test_nofork)
	{
		printf("Running in non-fork mode");
		if (options.handle_signals)
			printf(" with signal handling");
		printf("\n");
	}
	else
		printf("Unknown execution mode. Contact gfielder about this error.\n");
	//Line 3: optional print test history logging configuration
	if (options.log_history)
	{
		printf("  Test history log open for reading");
		if (options.log_write_enabled)
			printf(" and writing");
		printf("\n");
	}
	//Line 4: optional leaks test
	if (options.run_leaks_test)
		printf("  Leaks test enabled\n");

	max_eq = ((int)(window_width));
	printf("%.*s\n", max_eq,
		"==============================================================");
}

/* ----------------------------------------------------------------------------
** Begins a test run line by printing the test number and name
** --------------------------------------------------------------------------*/
void		print_test_start(int test_number)
{
	printf(test_start_fmt_str, test_number, g_unit_tests[test_number].name);
}

/* ----------------------------------------------------------------------------
** Ends a test run line by printing pass or fail
** --------------------------------------------------------------------------*/
void		print_test_end(int test_number, int failed,
				int stat_loc, int timed_out, int leak_found)
{
	if (timed_out)
		printf(FAULT "TIMEOUT" RESET);
	else if (leak_found)
		printf(FAULT "LEAK" RESET);
	else if (WIFSIGNALED(stat_loc))
		printf(FAULT "%s" RESET, g_signal_strings[WTERMSIG(stat_loc)]);
	else if (failed)
		printf(RED "FAIL" RESET);
	else
		printf(GRN "PASS" RESET);
	printf("]");
	if (get_option_loghistory()
			&& test_history[test_number] != NO_HISTORY
			/*&& test_history[test_number] != OUTDATED*/)
	{
		if (test_history[test_number] == RECENTLY_PASSED)
			printf(test_history_fmt_str, "pass");
		else if (test_history[test_number] == RECENTLY_FAILED)
			printf(test_history_fmt_str, "fail");
		else if (test_history[test_number] == OUTDATED && window_width > 60)
			printf(DIM "   was outdated" RESET);
	}
	printf("\n");
}

/* ----------------------------------------------------------------------------
** Prints a message at the end of all the tests
** --------------------------------------------------------------------------*/
void		print_end_test_message(int num_tests, int num_passed)
{
	printf("Tests completed. %i/%i tests passed.\n",
			num_passed, num_tests);
	if (num_passed != num_tests)
		printf("See %s for details.\n", TEST_OUTPUT_FILENAME);
}

/* ----------------------------------------------------------------------------
** Appends a string to the log
** --------------------------------------------------------------------------*/

void		log_msg(const char *msg)
{
	time_t	t;
	char	timestr[27];
	FILE	*fp;

	bzero(timestr, 27);
	t = time(NULL);
	ctime_r(&t, timestr);
	for (int i = 26; i >= 0; i--)
		if (timestr[i] == '\n' || timestr[i] == '\r')
			timestr[i] = ' ';
	fp = fopen(LOG_FILE, "a");
	if (fp)
	{
		fprintf(fp, "%-27s: %s\n", timestr, msg);
		fclose(fp);
	}
}

/* ----------------------------------------------------------------------------
** The ft_match function is used for wildcard-based searches
** s2 has an indeterminate number of *, s1 is the function name to test.
** --------------------------------------------------------------------------*/
int			ft_match_helper(const char *s1, char *s2)
{
	int		i;
	char	next;
	int		found;

	i = 0;
	next = *(s2 + 1);
	found = 0;
	if (next == '\0')
		return (1);
	if (next == '*')
		return (ft_match(s1, s2 + 1));
	while (1)
	{
		if (s1[i] == next)
			found = (ft_match(s1 + i, s2 + 1));
		if (found)
			return (found);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (-1);
}
int			ft_match(const char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 != '*' && (*s1 != *s2))
		return (0);
	if (*s2 == '*')
		return (ft_match_helper(s1, s2));
	else if (*s1 == *s2)
		return (ft_match(s1 + 1, s2 + 1));
	return (-1);
}


/* ----------------------------------------------------------------------------
** Converts all invalid characters for function names into wildcards
** --------------------------------------------------------------------------*/
void 		convert_nonalphanum_to_wildcard(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z')
				|| (*str >= 'A' && *str <= 'Z')
				|| (*str >= '0' && *str <= '9')
				|| *str == '_'))
			*str = '*';
		str++;
	}
}

/* ----------------------------------------------------------------------------
** Some libft functions
** --------------------------------------------------------------------------*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			ft_putchar_fd('2', fd);
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd('0' + (nb % 10), fd);
	}
	else
		ft_putchar_fd('0' + nb, fd);
}
