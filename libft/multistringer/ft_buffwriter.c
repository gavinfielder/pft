/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffwriter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:07:13 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 14:35:50 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                                ft_buffwriter.c
** ----------------------------------------------------------------------------
**      Buffwriter writes to an existing string buffer.
**      Buffwriter is a member of the ft_multistringer family. Its type is U.
**      It is a variant of Stringwriter--It is identical except that buffwriter
**      never null terminates its string, whereas stringwriter always null
**      terminates its string.
**      Both stringwriter and buffwriter maintain a capacity, and will not
**      write once that capacity has been reached.
** ----------------------------------------------------------------------------
**      1. ft_bwnew       create a new buffwriter
**      2. ft_bwwrite     write a string to the buffwriter
**      3. ft_bwwriten    write up to n characters to the buffwriter
**      4. ft_bwclear     clears the buffer
**      5. ft_bwdel       deletes the buffwriter (does not delete the buffer)
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_bwnew returns NULL on malloc failure. Everything else is guaranteed
**      provided the buff_location and capacity passed to ft_bwnew refer to
**      a properly allocated writeable memory space.
**
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_bzero
**
** ----------------------------------------------------------------------------
*/

t_stringwriter	*ft_bwnew(char *buff_location, size_t capacity)
{
	t_stringwriter	*sw;

	sw = (t_stringwriter *)malloc(sizeof(t_stringwriter));
	if (sw == NULL)
		return (NULL);
	sw->type = 'U';
	sw->buff = buff_location;
	sw->capacity = capacity;
	sw->len = 0;
	return (sw);
}

void			ft_bwwrite(t_stringwriter *sw, const char *str)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str)
	{
		if (sw->len >= sw->capacity)
			return ;
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
	}
}

void			ft_bwwriten(t_stringwriter *sw, const char *str, size_t n)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		if (sw->len >= sw->capacity)
			return ;
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
		n--;
	}
}

void			ft_bwclear(t_stringwriter *sw)
{
	ft_swclear(sw);
}

void			ft_bwdel(t_stringwriter **sw)
{
	ft_swdel(sw);
}
