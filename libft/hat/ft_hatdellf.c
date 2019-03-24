/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatdellf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:19:14 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 17:53:29 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ----------------------------------------------------------------------------
**                              ft_hatdellf.c
** ----------------------------------------------------------------------------
**      This file contains the functions for deleting a hat leaf. It is not
**      a part of the public interface for ft_hat, and should not be called
**      outside of the ft_hat section of this library.
** ----------------------------------------------------------------------------
**      Hashed Array Table is a dynamically growing collection implemented
**      as a doubly linked list of arrays. It can store up to uint_max items
**      of the same size. The space allocated for each index is determined on
**      calling ft_hatnew. Data can then be set for any desired index.
**
**      t_hatlf ('hat leaf') wraps an array and is the node of the doubly
**      linked list.
**      Operations on ft_hat are not O(1), but O(number of leaves). The number
**      of leaves is affected by the leaf_capacity decided by the user when
**      invoking ft_hatnew, and, of course, the amount of data the user adds,
**      as well as the distribution of the indices the user adds data at.
**
**      For further explanation:
**      ft_hat only creates leaves as necessary, and can leave gaps between
**      allocated indices. For example, a t_hat with leaf capacity 10 will
**      have no leaves on creation, then on accessing index 27 will have leaf
**      [20,29], then on accessing index -54 will have the two leaves
**      [-60,-51]<=>[20,29]. No intermediate leaves are created until needed.
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      none specific to this file
** ----------------------------------------------------------------------------
*/

static void	delete_the_only_leaf(t_hat *hat, t_hatlf **lf)
{
	hat->head = NULL;
	hat->tail = NULL;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

static void	delete_head(t_hat *hat, t_hatlf **lf)
{
	hat->head = hat->head->next;
	hat->head->prev = NULL;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

static void	delete_tail(t_hat *hat, t_hatlf **lf)
{
	hat->tail = hat->tail->prev;
	hat->tail->next = NULL;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

static void	delete_middle(t_hatlf **lf)
{
	(*lf)->next->prev = (*lf)->prev;
	(*lf)->prev->next = (*lf)->next;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

void		ft_hatdellf(t_hat *hat, t_hatlf **lf)
{
	if (hat == NULL || lf == NULL || *lf == NULL)
		return ;
	if (*lf == hat->head && *lf == hat->tail)
		delete_the_only_leaf(hat, lf);
	else if (*lf == hat->head)
		delete_head(hat, lf);
	else if (*lf == hat->tail)
		delete_tail(hat, lf);
	else
		delete_middle(lf);
}
