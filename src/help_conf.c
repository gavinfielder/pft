/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:02:15 by gfielder          #+#    #+#             */
/*   Updated: 2019/06/18 14:14:04 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"
#include "test.h"

# define BLI_ACTION_NEW 0
# define BLI_ACTION_APPEND 1
# define BLI_ACTION_PRINT 2

void	build_list_item(int action, char *new_bullet, char *str)
{
	static char *bullet;
	static char buff[512];
	static size_t len = 0;

	if (action == BLI_ACTION_NEW)
	{
		bzero(buff, 512);
		len = 0;
		bullet = new_bullet;
		strcpy(buff, str);
		len += strlen(str);
	}
	else if (action == BLI_ACTION_APPEND)
	{
		strcpy(buff + len, str);
		len += strlen(str);
	}
	else if (action == BLI_ACTION_PRINT)
	{
		help_list_item(bullet, buff);
	}
}

/* ----------------------------------------------------------------------------
** Parses a filter option (an option starting with =, +, -)
** --------------------------------------------------------------------------*/
int		help_conf_parse_filter_option(char *str)
{
	int i;

	if (str[1] == '\0')
		return (1);
	if (str[0] == '=')
		build_list_item(BLI_ACTION_NEW, "=", "Filtering only: {");
	else if (str[0] == '+')
		build_list_item(BLI_ACTION_NEW, "=", "Including: {");
	else if (str[0] == '-')
		build_list_item(BLI_ACTION_NEW, "=", "Excluding: {");
	else
		return (1);
	i = 1;
	while (1)
	{
		if (str[i] == 'p')
			build_list_item(BLI_ACTION_APPEND, NULL, "p (recently passed), ");
		else if (str[i] == 'f')
			build_list_item(BLI_ACTION_APPEND, NULL, "f (recently failed), ");
		else if (str[i] == 'o')
			build_list_item(BLI_ACTION_APPEND, NULL, "o (outdated), ");
		else if (str[i] == 'n')
			build_list_item(BLI_ACTION_APPEND, NULL, "n (no history), ");
		else
		{
			build_list_item(BLI_ACTION_APPEND, NULL, "}");
			build_list_item(BLI_ACTION_PRINT, NULL, NULL);
			return (i);
		}
		i++;
	}
	return (1);
}

/* ----------------------------------------------------------------------------
** Parses a single option
** --------------------------------------------------------------------------*/
int		help_conf_parse_option(char *str)
{
	char tmp[2];
	tmp[1] = '\0';

	if (DEBUG) printf("parsing option: %c\n", *str);
	switch (*str)
	{
		case 'd':
			help_list_item("d", "debug compatibility mode enabled");
			return (1);
		case 'k':
			help_list_item("k", "leaks test enabled");
			return (1);
		case 'K':
			help_list_item("K", "leaks test disabled");
			return (1);
		case '=':
		case '+':
		case '-':
			return (help_conf_parse_filter_option(str));
		case 't':
			help_list_item("t", "timeout enabled");
			return (1);
		case 'T':
			help_list_item("T", "timeout disabled");
			return (1);
		case 'x':
			help_list_item("x", "fork mode enabled");
			return (1);
		case 'X':
			help_list_item("X", "fork mode disabled");
			return (1);
		case 'i':
			help_list_item("i", "run info displayed before each run");
			return (1);
		case 'I':
			help_list_item("I", "run info header disabled");
			return (1);
		case 'l':
			help_list_item("l", "test history logging enabled");
			return (1);
		case 'L':
			help_list_item("L", "test history logging disabled");
			return (1);
		case 'W':
			help_list_item("W", "new test history will not be written");
			return (1);
		case 'w':
			help_list_item("w", "new test history will be written");
			return (1);
		case 'a':
			help_list_item("a", "run disabled tests");
			return (1);
		case 'A':
			help_list_item("A", "ignore disabled tests");
			return (1);
		case 'c':
			help_list_item("c", "Print responsive to window width");
			return (1);
		case 'C':
			help_list_item("C", "print standardized output");
			return (1);
		case 'g':
			help_list_item("g", "Remove temporary files after run");
			return (1);
		case 'G':
			help_list_item("G", "Leave temporary files after run");
			return (1);
		case 's':
			help_list_item("s", "signal handling enabled");
			return (1);
		case 'S':
			help_list_item("S", "signal handling disabled");
			return (1);
		case 'r':
			help_list_item("r", "test results refreshed each run");
			return (1);
		case 'R':
			help_list_item("R", "test results appended each run");
			return (1);
		case ' ':
		case '\t':
			return (1);
		default:
			tmp[0] = *str;
			help_list_item(tmp, "Unrecognized option");
	}
	return (1);
}

/* ----------------------------------------------------------------------------
** Prints the user's current default configuration
** --------------------------------------------------------------------------*/
void		help_conf(void)
{
	help_header("Current Configuration");
	help_paragraph("This is the contents of the DEFAULT_RUN_OPTIONS variable in `options-config.ini`. They will be overridden by any command line options given at execution time:");
	printf("\n");
	help_example(DEFAULT_RUN_OPTIONS, 0);
	printf("\n");
	help_header("Explanation of each selection:");
	int i = 0;
	while (DEFAULT_RUN_OPTIONS[i])
		i += help_conf_parse_option(((char *)DEFAULT_RUN_OPTIONS) + i);
	printf("\n");
	help_header("See Also");
	help_example("./test help options", 0);
}

