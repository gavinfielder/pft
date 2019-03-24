/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:14:06 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:43:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int			is_ws(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static unsigned int	get_ws_leading(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] && is_ws(s[i]))
		i++;
	return (i);
}

static unsigned int	get_ws_trailing(char const *s, unsigned int len_s)
{
	unsigned int	ws_trailing;

	if (len_s == 0)
		return (0);
	ws_trailing = 0;
	while (is_ws(s[len_s - 1 - ws_trailing]))
	{
		ws_trailing++;
		if (ws_trailing == len_s)
			break ;
	}
	return (ws_trailing);
}

char				*ft_strtrim(char const *s)
{
	char			*r;
	unsigned int	ws_leading;
	unsigned int	ws_trailing;
	unsigned int	len_s;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	ws_leading = get_ws_leading(s);
	if (ws_leading == len_s)
		return (ft_strdup(""));
	ws_trailing = get_ws_trailing(s, len_s);
	r = ft_strnew(len_s - ws_leading - ws_trailing);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len_s - ws_leading - ws_trailing)
	{
		r[i] = s[i + ws_leading];
		i++;
	}
	return (r);
}
