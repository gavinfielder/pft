/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mswrite_nullterm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:09:29 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/24 14:32:08 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                             ft_multistringer.c
** ----------------------------------------------------------------------------
**      This file holds functions that write null terminators to multistringers
**      This is separate because it's not guaranteed to work as with normal
**      strings.
** ----------------------------------------------------------------------------
**      Multistringer is emulated polymorphism for various string printing
**      functionality. It has four subtypes:
**
**       (W)  ft_stringwriter       writes to an existing string buffer
**       (U)  ft_buffwriter         a stringwriter that does not null terminate
**       (F)  ft_fildeswriter       writes to a file descriptor
**       (B)  ft_stringbuilder      writes to a stringbuilder (t_stringbuilder)
**
**      Each structure (t_stringwriter, t_fdwriter, t_stringbuilder) has a
**      char 'type' as its first member. It is assigned on creation of any
**      of the above four subtypes. t_multistringer is a union of these four
**      subtypes. A subtype is guaranteed to have the following functions:
**          *write, *writen, *clear, *del
**      Multistringer functions read the type variable and route the function
**      call to the corresponding function of the proper subtype.
** ----------------------------------------------------------------------------
**      1. ft_mswrite_nullterm
**      2. ft_sbwrite_nullterm
**      3. ft_fdwwrite_nullterm
**      4. ft_swwrite_nullterm
**      5. ft_bwwrite_nullterm
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      TODO
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      TODO
** ----------------------------------------------------------------------------
*/

void	ft_mswrite_nullterm(t_multistringer *ms)
{
	if (ms == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwrite_nullterm((t_stringbuilder *)ms);
	else if (ms->sb.type == 'W')
		ft_swwrite_nullterm((t_stringwriter *)ms);
	else if (ms->sb.type == 'U')
		ft_bwwrite_nullterm((t_stringwriter *)ms);
	else if (ms->sb.type == 'F')
		ft_fdwwrite_nullterm((t_fdwriter *)ms);
}

void			ft_sbwrite_nullterm(t_stringbuilder *sb)
{
	char	*ptr;

	ptr = (char *)ft_hataccess(sb->hat, (int)sb->len);
	if (ptr == NULL)
		return ;
	*ptr = '\0';
	(sb->len)++;
}

void		ft_fdwwrite_nullterm(t_fdwriter *fdw)
{
	char	nt;

	nt = '\0';
	if (fdw == NULL)
		return ;
	write(fdw->fd, &nt, 1);
	fdw->len++;
}

void			ft_swwrite_nullterm(t_stringwriter *sw)
{
	if (sw == NULL || sw->buff == NULL)
		return ;
	if (sw->len >= sw->capacity)
	{
		sw->buff[sw->capacity - 1] = '\0';
		return ;
	}
	sw->buff[sw->len] = '\0';
	(sw->len)++;
	sw->buff[sw->len] = '\0';
}

void			ft_bwwrite_nullterm(t_stringwriter *sw)
{
	if (sw == NULL || sw->buff == NULL)
		return ;
	if (sw->len >= sw->capacity)
		return ;
	sw->buff[sw->len] = '\0';
	(sw->len)++;
}
