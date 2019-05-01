/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/27 18:10:21 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_unit_tester_args		*failsafe_args_recover;

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

static void		unit_testing(t_clopt clargs)
{
	t_unit_tester_args		args;
	failsafe_args_recover = &args;
	int from, to;

	if (clargs.args.argc > 0)
	{
		if (!(clargs.args.argv[0][0] >= '0' && clargs.args.argv[0][0] <= '9'))
		{
			//Search pattern
			init_args(&args, clargs.args.argv[0], 0, 2147483647, run_search_tests);
			run_search_tests(&args);
		}
		else
		{
			from = atoi(clargs.args.argv[0]);
			if (clargs.args.argc > 1)
				to = atoi(clargs.args.argv[1]);
			else
			{
				if (SINGLE_NUMBER_SINGLE_TEST)
				{
					//Single test selected. Select lldb debugging mode unless overridden
					if (SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE)
					{
						set_option_notimeout();
						set_option_nofork();
						if (ft_issel(&clargs, 'f'))
							set_option_fork();
						if (ft_issel(&clargs, 't'))
							set_option_usetimeout();
					}
					to = from;
				}
				else
					to = 2147483647;
			}
			init_args(&args, NULL, from, to, run_test_range);
			run_test_range(&args);
		}
	}
	else
	{
		//No arguments. Run all tests
		from = 0;
		to = 2147483647;
		init_args(&args, NULL, from, to, run_test_range);
		run_test_range(&args);
	}
}

void	handle_args(t_clopt *opt, int argc, char **argv)
{
	//First, set default behavior with Makefile defines
	if (USE_TIMEOUT)
		set_option_usetimeout();
	else
		set_option_notimeout();
	if (RUN_TESTS_AS_FORK)
		set_option_fork();
	else
		set_option_nofork();
	//Next, get command line options
	*opt = ft_optget(argc, argv);
	for (int i = 0; i < opt->num_sel; i++)
	{
		switch (opt->selected[i])
		{
			case 'd':
				set_option_notimeout();
				set_option_nofork();
				break ;
			case 't':
				set_option_usetimeout();
				break ;
			case 'T':
				set_option_notimeout();
				break ;
			case 'f':
				set_option_fork();
				break ;
			case 'F':
				set_option_nofork();
				break ;
		}
	}
}

int main(int argc, char **argv)
{
	t_clopt	clargs;
	handle_args(&clargs, argc, argv);

	if (clargs.args.argc > 0 && strcmp(clargs.args.argv[0], "help") == 0)
	{
		if (clargs.args.argc == 2 && strcmp(clargs.args.argv[1], "all") == 0)
			print_help(1);
		else
			print_help(0);
	}
	else
		unit_testing(clargs);
	return (0);
}
