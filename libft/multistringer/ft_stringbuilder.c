/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringbuilder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:31:40 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 15:58:04 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                            ft_stringbuilder.c
** ----------------------------------------------------------------------------
**      Stringbuilder maintains a dynamically growing string. Writing to a
**      stringbuilder appends to the string without copying existing memory.
**      Stringbuilder is a member of the ft_multistringer family. Its type is B
**      ft_sbprintf is printf functionality for printing to stringbuilder.
** ----------------------------------------------------------------------------
**      1. ft_sbnew       create a new stringbuilder
**      2. ft_sbwrite     Writes a string to a stringbuilder
**      3. ft_sbwriten    Writes up to n characters of a string
**      4. ft_sbclear     Clears stringbuilder to equivalent of empty string
**      5. ft_sbdel       Deletes a stringbuilder
**
**      ft_sbtostr is provided in another file and converts the stringbuilder
**      to string.
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_sbnew returns NULL on malloc failure.
**      ft_stringbuilder is built on top of ft_hat, which is implemented using
**      a doubly linked list of arrays. calls to ft_hataccess will return
**      NULL on malloc failure, in which case nothing will be done.
**      If the stringbuilder is allocated, the t_hat is guaranteed to also be
**      allocated.
**      Otherwise safety is guaranteed provided only the provided functions
**      are used to manage the stringbuilder.
**
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_hat
**
** ----------------------------------------------------------------------------
*/

t_stringbuilder	*ft_sbnew(void)
{
	t_stringbuilder	*sb;

	sb = (t_stringbuilder *)malloc(sizeof(t_stringbuilder));
	if (sb == NULL)
		return (NULL);
	sb->hat = ft_hatnew(FT_STRINGBUILDER_LEAFSIZE, 1);
	if (sb->hat == NULL)
	{
		free(sb);
		return (NULL);
	}
	sb->len = 0;
	sb->type = 'B';
	return (sb);
}

void			ft_sbwrite(t_stringbuilder *sb, const char *str)
{
	char	*ptr;

	ptr = NULL;
	if (str == NULL)
		return ;
	while (*str)
	{
		if (ptr == NULL || sb->len % sb->hat->leaf_capacity == 0)
			ptr = (char *)ft_hataccess(sb->hat, (int)sb->len);
		if (ptr == NULL)
			return ;
		*ptr = *str;
		ptr++;
		str++;
		(sb->len)++;
	}
}

void			ft_sbwriten(t_stringbuilder *sb, const char *str, size_t n)
{
	char	*ptr;

	ptr = NULL;
	if (str == NULL)
		return ;
	while (*str && n)
	{
		if (ptr == NULL || sb->len % sb->hat->leaf_capacity == 0)
			ptr = (char *)ft_hataccess(sb->hat, (int)(sb->len));
		if (ptr == NULL)
			return ;
		*ptr = *str;
		ptr++;
		str++;
		(sb->len)++;
		n--;
	}
}

void			ft_sbdel(t_stringbuilder **sb)
{
	if (sb == NULL || *sb == NULL)
		return ;
	ft_hatdel(&(((*sb)->hat)));
	free(*sb);
	*sb = NULL;
}

void			ft_sbclear(t_stringbuilder *sb)
{
	t_hatlf *tmp;

	if (sb == NULL)
		return ;
	while (sb->hat->head->next)
	{
		tmp = sb->hat->head->next;
		ft_hatdellf(sb->hat, &tmp);
	}
	ft_bzero(sb->hat->head->data, sb->hat->leaf_capacity);
	sb->len = 0;
}
