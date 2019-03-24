/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:33:12 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 19:05:38 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int	value;
	int i;

	value = 0;
	i = 0;
	while (value == 0 && (s1[i] || s2[i]))
	{
		value += ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (value);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		value;
	size_t	i;

	value = 0;
	i = 0;
	while (value == 0 && i < n && (s1[i] || s2[i]))
	{
		value += ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (value);
}

int		ft_strequ(char const *s1, char const *s2)
{
	int	value;
	int i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	value = 0;
	i = 0;
	while (value == 0 && (s1[i] || s2[i]))
	{
		value += ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (value)
		return (0);
	else
		return (1);
}

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int		value;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	value = 0;
	i = 0;
	while (value == 0 && i < n && (s1[i] || s2[i]))
	{
		value += ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if (value)
		return (0);
	else
		return (1);
}
