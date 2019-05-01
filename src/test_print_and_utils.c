/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_and_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:08:06 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/01 05:49:21 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/* ----------------------------------------------------------------------------
** Begins a test run line by printing the test number and name
** --------------------------------------------------------------------------*/
void		print_test_start(int test_number)
{
	printf("Test %4i:  %-42s [",test_number, g_unit_tests[test_number].name);
}

/* ----------------------------------------------------------------------------
** Ends a test run line by printing pass or fail
** --------------------------------------------------------------------------*/
void		print_test_end(int failed, int stat_loc, int timed_out)
{
	if (timed_out)
		printf(FAULT "TIMEOUT" RESET);
	else if (WIFSIGNALED(stat_loc))
		printf(FAULT "%s" RESET, g_signal_strings[WTERMSIG(stat_loc)]);
	else if (failed)
		printf(RED "FAIL" RESET);
	else
		printf(GRN "PASS" RESET);
	printf("]\n");
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
