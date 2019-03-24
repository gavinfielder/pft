/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fildeswriter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:26:26 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 21:06:09 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                              ft_fildeswriter.c
** ----------------------------------------------------------------------------
**      Fildeswriter writes to a file descriptor.
**      Fildeswriter is a member of the ft_multistringer family. Its type is F.
** ----------------------------------------------------------------------------
**      1. ft_fdwnew       create a new fildeswriter
**      2. ft_fdwwrite     write a string to the file descriptor
**      3. ft_fdwwriten    write up to n characters to the file descriptor
**      4. ft_fdwclear     clears the fildeswriter (sets length to 0)
**      5. ft_fdwdel       deletes the fildeswriter (does not manage the fd)
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_fdwnew returns NULL on malloc failure. Everything else is guaranteed
**      provided the file descriptor provided remains open and writeable.
**
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      none
** ----------------------------------------------------------------------------
*/

t_fdwriter	*ft_fdwnew(int fd)
{
	t_fdwriter	*fdw;

	fdw = (t_fdwriter *)malloc(sizeof(t_fdwriter));
	if (fdw == NULL)
		return (NULL);
	fdw->type = 'F';
	fdw->len = 0;
	fdw->fd = fd;
	return (fdw);
}

void		ft_fdwwrite(t_fdwriter *fdw, const char *str)
{
	if (fdw == NULL || str == NULL)
		return ;
	while (*str)
	{
		write(fdw->fd, str, 1);
		str++;
		fdw->len++;
	}
}

void		ft_fdwwriten(t_fdwriter *fdw, const char *str, size_t n)
{
	if (fdw == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		write(fdw->fd, str, 1);
		str++;
		fdw->len++;
		n--;
	}
}

void		ft_fdwclear(t_fdwriter *fdw)
{
	fdw->len = 0;
}

void		ft_fdwdel(t_fdwriter **fdw)
{
	if (fdw == NULL || *fdw == NULL)
		return ;
	free(*fdw);
	*fdw = NULL;
}
