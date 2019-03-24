/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:27:59 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 19:08:45 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	len;
	int	match;
	int	i;

	match = 0;
	i = 0;
	len = ft_strlen(to_find);
	if (len == 0)
		return ((char *)str);
	while (str[i] != '\0' && match < len)
	{
		if (str[i] == to_find[match])
			match++;
		else
		{
			i = i - match;
			match = 0;
		}
		i++;
	}
	if (match == len)
		return ((char *)(str + i - match));
	else
		return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t max_len)
{
	size_t	len;
	size_t	match;
	size_t	i;

	match = 0;
	i = 0;
	len = ft_strlen(to_find);
	if (len == 0)
		return ((char *)str);
	while (str[i] != '\0' && match < len && i < max_len)
	{
		if (str[i] == to_find[match])
			match++;
		else
		{
			i = i - match;
			match = 0;
		}
		i++;
	}
	if (match == len)
		return ((char *)(str + i - match));
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
