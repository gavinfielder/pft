/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:16:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/06/18 14:10:36 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/* ----------------------------------------------------------------------------
** Options that are set by Makefile and/or command line arguments
** --------------------------------------------------------------------------*/

t_pft_options	options = {
	run_test_fork,
	1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0
};

t_pft_options	get_options(void) { return options; }

/* ----------------------------------------------------------------------------
** Sets options
** --------------------------------------------------------------------------*/
void	set_option_fork(void) { options.run_test = run_test_fork; }
void	set_option_nofork(void) { options.run_test = run_test_nofork; }
void	set_option_notimeout(void) { options.use_timeout = 0; }
void	set_option_usetimeout(void) { options.use_timeout = 1; }
void	set_option_loghistory(void) { options.log_history = 1; }
void	set_option_nologhistory(void) { options.log_history = 0; }
void	set_option_filter_failingoff(void) { options.filter_run_failing = 0; }
void	set_option_filter_failingon(void) { options.filter_run_failing = 1; }
void	set_option_filter_passingoff(void) { options.filter_run_passing = 0; }
void	set_option_filter_passingon(void) { options.filter_run_passing = 1; }
void	set_option_filter_outdatedoff(void) { options.filter_run_outdated = 0; }
void	set_option_filter_outdatedon(void) { options.filter_run_outdated = 1; }
void	set_option_filter_nohistoryon(void) { options.filter_run_nohistory = 1; }
void	set_option_filter_nohistoryoff(void) { options.filter_run_nohistory = 0; }
void	set_option_rundisabled(void) { options.filter_run_disabled = 1; }
void	set_option_norundisabled(void) { options.filter_run_disabled = 0; }
void	set_option_leakstest(void)
{ options.run_leaks_test = 1; options.run_test = run_test_nofork; options.use_timeout = 0; }
void	set_option_noleakstest(void) { options.run_leaks_test = 0; }
void	set_option_handlesignals(void) { options.handle_signals = 1; }
void	set_option_nohandlesignals(void) { options.handle_signals = 0; }
void	set_option_nowritelog(void) { options.log_write_enabled = 0; }
void	set_option_writelog(void) { options.log_write_enabled = 1; }
void	set_option_noprintinfo(void) { options.print_info = 0; }
void	set_option_printinfo(void) { options.print_info = 1; }
void	set_option_printresponsive(void) { options.print_responsive = 1; }
void	set_option_noprintresponsive(void) { options.print_responsive = 0; }
void	set_option_cleanup(void) { options.cleanup = 1; }
void	set_option_nocleanup(void) { options.cleanup = 0; }
void	set_option_refreshresults(void) { options.refresh_results = 1; }
void	set_option_norefreshresults(void) { options.refresh_results = 0; }

/* ----------------------------------------------------------------------------
** Option accessors
** --------------------------------------------------------------------------*/
int		get_option_loghistory(void) { return options.log_history; }
int		get_option_writelog(void) { return options.log_write_enabled; }
int		get_option_printinfo(void) { return options.print_info; }

/* ----------------------------------------------------------------------------
** Checks options to make sure they're coherent
** --------------------------------------------------------------------------*/
void	options_check(void)
{
	if (options.run_leaks_test && options.run_test == run_test_fork)
	{
		dprintf(2, "leaks test (-k) must be run in non-forking mode (-X). Run with -kX.\n");
		exit(-1);
	}
	if (options.use_timeout && options.run_test == run_test_nofork)
	{
		dprintf(2, "Notice: timeout (-t) is only available in forking mode (-x).\n");
		fflush(stdout);
	}

	if (DEBUG)
	{
		printf("Options selected:\n");
		if (options.run_test == run_test_nofork)
			printf("   options.run_test = run_test_nofork\n");
		else if (options.run_test == run_test_fork)
			printf("   options.run_test = run_test_fork\n");
		else
			printf("   options.run_test = %p\n", options.run_test);
		printf("   options.use_timeout = %i\n", options.use_timeout);
		printf("   options.log_history = %i\n", options.log_history);
		printf("   options.filter_run_failing = %i\n", options.filter_run_failing);
		printf("   options.filter_run_passing = %i\n", options.filter_run_passing);
		printf("   options.filter_run_outdated = %i\n", options.filter_run_outdated);
		printf("   options.filter_run_nohistory = %i\n", options.filter_run_nohistory);
		printf("   options.filter_run_disabled = %i\n", options.filter_run_disabled);
		printf("   options.run_leaks_test = %i\n", options.run_leaks_test);
		printf("   options.handle_signals = %i\n", options.handle_signals);
		printf("\n");
		fflush(stdout);
	}
}

/* ----------------------------------------------------------------------------
** Parses a filter option (an option starting with =, +, -)
** --------------------------------------------------------------------------*/
int		parse_filter_option(char *str)
{
	int i;

	if (DEBUG) printf("entering parse_filter_option\n");
	if (str[1] == '\0')
		return (1);
	if (str[0] == '=')
	{
		if (DEBUG) printf("found =\n");
		set_option_filter_outdatedoff();
		set_option_filter_nohistoryoff();
		set_option_filter_passingoff();
		set_option_filter_failingoff();
		i = 1;
		while (1)
		{
			if (DEBUG) printf("   = : parsing %c\n", str[i]);
			if (str[i] == 'p')
				set_option_filter_passingon();
			else if (str[i] == 'f')
				set_option_filter_failingon();
			else if (str[i] == 'o')
				set_option_filter_outdatedon();
			else if (str[i] == 'n')
				set_option_filter_nohistoryon();
			else
			{
				if (DEBUG) printf("parse_filter_option returning %i\n", i);
				return (i);
			}
			i++;
		}
	}
	else if (str[0] == '+')
	{
		if (DEBUG) printf("found +\n");
		i = 1;
		while (1)
		{
			if (DEBUG) printf("   + : parsing %c\n", str[i]);
			if (str[i] == 'p')
				set_option_filter_passingon();
			else if (str[i] == 'f')
				set_option_filter_failingon();
			else if (str[i] == 'o')
				set_option_filter_outdatedon();
			else if (str[i] == 'n')
				set_option_filter_nohistoryon();
			else
			{
				if (DEBUG) printf("parse_filter_option returning %i\n", i);
				return (i);
			}
			i++;
		}
	}
	else if (str[0] == '-')
	{
		if (DEBUG) printf("found -\n");
		i = 1;
		while (1)
		{
			if (DEBUG) printf("   - : parsing %c\n", str[i]);
			if (str[i] == 'p')
				set_option_filter_passingoff();
			else if (str[i] == 'f')
				set_option_filter_failingoff();
			else if (str[i] == 'o')
				set_option_filter_outdatedoff();
			else if (str[i] == 'n')
				set_option_filter_nohistoryoff();
			else
			{
				if (DEBUG) printf("parse_filter_option returning %i\n", i);
				return (i);
			}
			i++;
		}
	}
	if (DEBUG) printf("parse_filter_option found nothing, returning 1\n");
	return (1);
}

/* ----------------------------------------------------------------------------
** Parses a single option
** --------------------------------------------------------------------------*/
int		parse_option(char *str)
{
	if (DEBUG) printf("parsing option: %c\n", *str);
	switch (*str)
	{
		case 'd':
			set_option_notimeout();
			set_option_nofork();
			set_option_nohandlesignals();
			return (1);
		case 'k':
			set_option_leakstest();
			return (1);
		case 'K':
			set_option_noleakstest();
			return (1);
		case '=':
		case '+':
		case '-':
			return (parse_filter_option(str));
		case 't':
			set_option_usetimeout();
			return (1);
		case 'T':
			set_option_notimeout();
			return (1);
		case 'x':
			set_option_fork();
			return (1);
		case 'X':
			set_option_nofork();
			return (1);
		case 'i':
			set_option_printinfo();
			return (1);
		case 'I':
			set_option_noprintinfo();
			return (1);
		case 'l':
			set_option_loghistory();
			return (1);
		case 'L':
			set_option_nologhistory();
			return (1);
		case 'a':
			set_option_rundisabled();
			return (1);
		case 'A':
			set_option_norundisabled();
			return (1);
		case 'c':
			set_option_printresponsive();
			return (1);
		case 'C':
			set_option_noprintresponsive();
			return (1);
		case 'g':
			set_option_cleanup();
			return (1);
		case 'G':
			set_option_nocleanup();
			return (1);
		case 's':
			set_option_handlesignals();
			return (1);
		case 'S':
			set_option_nohandlesignals();
			return (1);
		case 'W':
			set_option_nowritelog();
			return (1);
		case 'w':
			set_option_writelog();
			return (1);
		case 'r':
			set_option_refreshresults();
			return (1);
		case 'R':
			set_option_norefreshresults();
			return (1);
		case ' ':
		case '\t':
			return (1);
		default:
			dprintf(2, "Unrecognized option '%c'; ignoring\n", *str);
	}
	return (1);
}

/* ----------------------------------------------------------------------------
** Reads the argc,argv into a t_clopt and parses all options
** --------------------------------------------------------------------------*/
t_clopt		parse_and_strip_options(int argc, char **argv)
{
	t_clopt		opt;
	int			i;
	int			j;
	int			option_size;

	bzero(&opt, sizeof(t_clopt));
	opt.program_name = argv[0];
	i = 1;
	while (i < argc &&
			(argv[i][0] == '-' || argv[i][0] == '=' || argv[i][0] == '+')
			&& opt.num_sel < FTOPT_MAX_OPTIONS)
	{
		j = ((argv[i][0] == '-'
				&& argv[i][1] != 'f'
				&& argv[i][1] != 'o'
				&& argv[i][1] != 'n'
				&& argv[i][1] != 'p')
			? 1 : 0);
		while (argv[i][j])
		{
			option_size = parse_option(argv[i] + j);
			strncpy(opt.selected + opt.num_sel, argv[i] + j, (size_t)option_size);
			opt.num_sel += option_size;
			j += option_size;
		}
		i++;
	}
	if (i < argc)
	{
		opt.args.argv = argv + i;
		opt.args.argc = argc - i;
	}
	return (opt);
}

/* ----------------------------------------------------------------------------
** Returns whether an option is selected
** --------------------------------------------------------------------------*/
int			ft_issel(t_clopt *opt, char c)
{
	int		i;

	if (!opt)
		return (-1);
	i = 0;
	while (opt->selected[i])
	{
		if (opt->selected[i] == c)
			return (1);
		i++;
	}
	return (0);
}
