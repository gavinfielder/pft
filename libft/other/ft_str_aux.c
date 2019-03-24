/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:20:15 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 19:22:23 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	ft_strdel(char **as)
{
	if (as == NULL || *as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strwrite_nchar(char *str, char c, int n)
{
	int		i;

	if (str && n > 0)
	{
		i = 0;
		while (str[i] && n--)
			str[i++] = c;
	}
}

void	ft_strinsert_nchr(char **str, char c, int index, int n)
{
	size_t	len;
	char	*new_str;
	int		i;

	if (str == NULL || *str == NULL || n <= 0 ||
			index < 0 || (size_t)index > (len = ft_strlen(*str)))
		return ;
	if (!(new_str = ft_strnew(len + n)))
		return ;
	i = -1;
	while (++i < index)
		new_str[i] = (*str)[i];
	i--;
	while (++i < index + n)
		new_str[i] = c;
	i--;
	while ((*str)[++i - n] != '\0')
		new_str[i] = (*str)[i - n];
	free(*str);
	*str = new_str;
}

void	ft_strclr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		*s = 0;
		s++;
	}
}
