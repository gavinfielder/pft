/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistringer_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:17:06 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 15:19:22 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                           ft_multistringer_aux.c
** ----------------------------------------------------------------------------
**      Some additional useful functions for ft_multistringer
** ----------------------------------------------------------------------------
**      1. ft_ms_put_ul         writes an unsigned long to a multistringer
**      2. ft_msputnchar        writes n char c's to a multistringer
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_multistringer
** ----------------------------------------------------------------------------
*/

void	ft_ms_put_ul(t_multistringer *ms, unsigned long nb)
{
	char	c;

	c = '0' + (nb % 10);
	if (nb >= 10)
	{
		ft_ms_put_ul(ms, nb / 10);
		ft_mswriten(ms, &c, 1);
	}
	else
		ft_mswriten(ms, &c, 1);
}

void	ft_msputnchar(t_multistringer *ms, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_mswriten(ms, &c, 1);
		i++;
	}
}
