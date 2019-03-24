/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:42:28 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 19:27:03 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

const static char	g_base_l[] = "0123456789abcdef";
const static char	g_base_u[] = "0123456789ABCDEF";

static char	*format_return(char *buff, int len)
{
	int		i;
	char	*ret;

	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = buff[len - i - 1];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

char		*ft_litoa(long long value)
{
	int		negative;
	char	buff[22];
	int		len;

	negative = 0;
	if (value < 0)
		negative = 1;
	len = 0;
	while (value || len == 0)
	{
		buff[len] = '0' + ABS(value % 10);
		len++;
		value /= 10;
	}
	if (negative)
	{
		buff[len] = '-';
		len++;
	}
	return (format_return(buff, len));
}

char		*ft_luitoa(unsigned long long value)
{
	char	buff[22];
	int		len;

	len = 0;
	while (value || len == 0)
	{
		buff[len] = '0' + ABS(value % 10);
		len++;
		value /= 10;
	}
	return (format_return(buff, len));
}

char		*ft_luitoa_base_lower(unsigned long long value, int base)
{
	char	buff[65];
	int		len;

	len = 0;
	while (value || len == 0)
	{
		buff[len] = g_base_l[value % base];
		len++;
		value /= base;
	}
	return (format_return(buff, len));
}

char		*ft_luitoa_base_upper(unsigned long long value, int base)
{
	char	buff[65];
	int		len;

	len = 0;
	while (value || len == 0)
	{
		buff[len] = g_base_u[value % base];
		len++;
		value /= base;
	}
	return (format_return(buff, len));
}
