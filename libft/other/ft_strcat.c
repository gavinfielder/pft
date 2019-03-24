/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:48:21 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 19:02:29 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (1)
	{
		dest[i + j] = src[j];
		if (dest[i + j] == '\0')
			break ;
		j++;
	}
	return (dest);
}

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_initial_size;
	size_t j;
	size_t src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	dest_initial_size = 0;
	while (dest[dest_initial_size] != '\0')
		dest_initial_size++;
	if (dest_initial_size < size)
	{
		j = 0;
		while (dest_initial_size + j < size - 1 && j < src_size)
		{
			dest[dest_initial_size + j] = src[j];
			j++;
		}
		dest[dest_initial_size + j] = '\0';
	}
	if (size < dest_initial_size)
		return (size + src_size);
	else
		return (dest_initial_size + src_size);
}

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
