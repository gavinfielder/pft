/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/25 16:35:42 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void	unit_testing(int argc, char **argv)
{
	int from, to;
	if (argc > 1)
	{
		if ((argv[1][0] == '*') || (argv[1][0] >= 'a' && argv[1][0] <= 'z') || (argv[1][0] >= 'A' && argv[1][0] <= 'Z'))
		{
			run_search_tests(argv[1]);
		}
		else
		{
			from = atoi(argv[1]);
			if (argc > 2)
				to = atoi(argv[2]);
			else
				to = -1;
			run_test_range(from, to);
		}
	}
	else
	{
		run_all_tests();
	}
}

int main(int argc, char **argv)
{
	unit_testing(argc, argv);
	return (0);
}
