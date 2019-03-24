/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistringer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:50:08 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/24 14:09:00 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                             ft_multistringer.c
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
**      1. ft_mswrite      writes a string to the multistringer
**      2. ft_mswriten     writes up to n characters of a string
**      3. ft_msclear      clears the multistringer
**      4. ft_msdel        deletes the multistringer
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      Safety is guaranteed provided the subtypes are created with their
**      respective 'new' functions and the 'type' member variable is not
**      changed subsequent to creation. If 'type' variable does not refer to
**      a valid subtype, nothing will be attempted.
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_stringwriter, ft_stringbuilder, ft_fildeswriter,
**      ft_buffwriter, ft_hat, ft_bzero //TODO: any more?
** ----------------------------------------------------------------------------
*/

void	ft_mswrite(t_multistringer *ms, const char *str)
{
	if (ms == NULL || str == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwrite((t_stringbuilder *)ms, str);
	else if (ms->sb.type == 'W')
		ft_swwrite((t_stringwriter *)ms, str);
	else if (ms->sb.type == 'U')
		ft_bwwrite((t_stringwriter *)ms, str);
	else if (ms->sb.type == 'F')
		ft_fdwwrite((t_fdwriter *)ms, str);
}

void	ft_mswriten(t_multistringer *ms, const char *str, size_t n)
{
	if (ms == NULL || str == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwriten((t_stringbuilder *)ms, str, n);
	else if (ms->sb.type == 'W')
		ft_swwriten((t_stringwriter *)ms, str, n);
	else if (ms->sb.type == 'U')
		ft_bwwriten((t_stringwriter *)ms, str, n);
	else if (ms->sb.type == 'F')
		ft_fdwwriten((t_fdwriter *)ms, str, n);
}

void	ft_msclear(t_multistringer *ms)
{
	if (ms == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbclear((t_stringbuilder *)ms);
	else if (ms->sb.type == 'W')
		ft_swclear((t_stringwriter *)ms);
	else if (ms->sb.type == 'U')
		ft_bwclear((t_stringwriter *)ms);
	else if (ms->sb.type == 'F')
		ft_fdwclear((t_fdwriter *)ms);
}

void	ft_msdel(t_multistringer **ms)
{
	if (ms == NULL || *ms == NULL)
		return ;
	if ((*ms)->sb.type == 'B')
		ft_sbdel((t_stringbuilder **)ms);
	else if ((*ms)->sb.type == 'W')
		ft_swdel((t_stringwriter **)ms);
	else if ((*ms)->sb.type == 'U')
		ft_swdel((t_stringwriter **)ms);
	else if ((*ms)->sb.type == 'F')
		ft_fdwdel((t_fdwriter **)ms);
}

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
