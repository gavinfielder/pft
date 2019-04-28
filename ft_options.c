/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:16:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/27 17:53:40 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_clopt		ft_optget(int argc, char **argv)
{
	t_clopt		opt;
	int			i;
	int			j;

	bzero(&opt, sizeof(t_clopt));
	opt.program_name = argv[0];
	i = 1;
	while (i < argc && argv[i][0] == '-' && opt.num_sel < FTOPT_MAX_OPTIONS)
	{
		j = 1;
		while (argv[i][j])
		{
			opt.selected[opt.num_sel] = argv[i][j];
			opt.num_sel++;
			j++;
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
