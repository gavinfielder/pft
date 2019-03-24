/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringwriter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:34:16 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 14:48:49 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                              ft_stringwriter.c
** ----------------------------------------------------------------------------
**      Stringwriter writes to an existing string buffer.
**      Stringwriter is a member of the ft_multistringer family. Its type is W.
**      Stringwriter always null terminates its string.
**      Both stringwriter and buffwriter maintain a capacity, and will not
**      write once that capacity has been reached.
** ----------------------------------------------------------------------------
**      1. ft_swnew       create a new stringwriter
**      2. ft_swwrite     write a string to the stringwriter
**      3. ft_swwriten    write up to n characters to the stringwriter
**      4. ft_swclear     clears the string
**      5. ft_swdel       deletes the stringwriter (does not delete the buffer)
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_swnew returns NULL on malloc failure. Everything else is guaranteed
**      provided the buff_location and capacity passed to ft_swnew refer to
**      a properly allocated writeable memory space.
**
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_bzero
**
** ----------------------------------------------------------------------------
*/

t_stringwriter	*ft_swnew(char *buff_location, size_t capacity)
{
	t_stringwriter	*sw;

	sw = (t_stringwriter *)malloc(sizeof(t_stringwriter));
	if (sw == NULL)
		return (NULL);
	sw->type = 'W';
	sw->buff = buff_location;
	sw->capacity = capacity;
	sw->len = 0;
	return (sw);
}

void			ft_swwrite(t_stringwriter *sw, const char *str)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str)
	{
		if (sw->len >= sw->capacity)
		{
			sw->buff[sw->capacity - 1] = '\0';
			return ;
		}
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
	}
	sw->buff[sw->len] = '\0';
}

void			ft_swwriten(t_stringwriter *sw, const char *str, size_t n)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		if (sw->len >= sw->capacity)
		{
			sw->buff[sw->capacity - 1] = '\0';
			return ;
		}
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
		n--;
	}
	sw->buff[sw->len] = '\0';
}

void			ft_swclear(t_stringwriter *sw)
{
	if (sw == NULL)
		return ;
	sw->len = 0;
	if (sw->buff == NULL)
		return ;
	ft_bzero(sw->buff, sw->capacity);
}

void			ft_swdel(t_stringwriter **sw)
{
	if (sw == NULL || *sw == NULL)
		return ;
	free(*sw);
	*sw = NULL;
}
