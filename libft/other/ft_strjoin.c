/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:01:30 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 19:11:17 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*r;
	unsigned int	i;
	size_t			len_s1;
	size_t			len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r = ft_strnew(len_s1 + len_s2);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		r[i] = s1[i];
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		r[i] = s2[i - len_s1];
		i++;
	}
	return (r);
}

void	ft_strjoin_inplace(char **s1, char const *s2)
{
	char *r;

	if (s1 == NULL || *s1 == NULL || s2 == NULL)
		return ;
	r = ft_strjoin(*s1, s2);
	if (!r)
		return ;
	free(*s1);
	*s1 = r;
}

void	ft_strjoin_inplace_rev(const char *s1, char **s2)
{
	char *r;

	if (s1 == NULL || s2 == NULL || *s2 == NULL)
		return ;
	r = ft_strjoin(s1, *s2);
	if (!r)
		return ;
	free(*s2);
	*s2 = r;
}
