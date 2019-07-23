/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/05 10:05:11 by gfielder         ###   ########.fr       */
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

	run_init();
	if (clargs.args.argc > 0)
	{
		if (!(clargs.args.argv[0][0] >= '0' && clargs.args.argv[0][0] <= '9'))
		{
			//Search pattern
			init_args(&args, clargs.args.argv[0], 0, 2147483647, run_search_tests);
			print_configuration_info(get_options(), args);
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
						set_option_nohandlesignals();
						if (ft_issel(&clargs, 'x'))
							set_option_fork();
						if (ft_issel(&clargs, 't'))
							set_option_usetimeout();
						if (ft_issel(&clargs, 's'))
							set_option_handlesignals();
					}
					to = from;
				}
				else
					to = 2147483647;
			}
			init_args(&args, NULL, from, to, run_test_range);
			print_configuration_info(get_options(), args);
			run_test_range(&args);
		}
	}
	else
	{
		//No arguments. Run all tests
		from = 0;
		to = 2147483647;
		init_args(&args, NULL, from, to, run_test_range);
		print_configuration_info(get_options(), args);
		run_test_range(&args);
	}
}

void	handle_args(t_clopt *opt, int argc, char **argv)
{
	int i = 0;
	//First, set default behavior with Makefile defines
	while (DEFAULT_RUN_OPTIONS[i])
		i += parse_option(((char *)DEFAULT_RUN_OPTIONS) + i);
	//Next, get command line options and set the strip down to the query
	*opt = parse_and_strip_options(argc, argv);
	//Check the options to make sure they're coherent
	options_check();
}

int main(int argc, char **argv)
{
	t_clopt	clargs;
	handle_args(&clargs, argc, argv);

	init_printing();
	if (clargs.args.argc > 0 && strcmp(clargs.args.argv[0], "help") == 0)
	{
		if (clargs.args.argc > 1)
			help_index_search(argv[2]);
		else
			help_basic();
	}
	else
		unit_testing(clargs);
	return (0);
}
