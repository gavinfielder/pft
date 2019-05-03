/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:16:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/02 22:01:17 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

int		parse_option(char *str)
{
	if (DEBUG) printf("parsing option: %c\n", *str);
	switch (*str)
	{
		case 'd':
			set_option_notimeout();
			set_option_nofork();
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
		case 's':
			set_option_handlesignals();
			return (1);
		case 'S':
			set_option_nohandlesignals();
			return (1);
		case 'W':
			set_option_nowritelog();
			return (1);
		case ' ':
		case '\t':
			return (1);
		default:
			dprintf(2, "Unrecognized option '%c'; ignoring\n", *str);
	}
	return (1);
}

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
