/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatinslf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 09:35:54 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 18:10:58 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ----------------------------------------------------------------------------
**                              ft_hatinslf.c
** ----------------------------------------------------------------------------
**      This file contains the functions for inserting a hat leaf. It is not
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

static void	insert_first_leaf(t_hat *hat, t_hatlf *lf)
{
	hat->head = lf;
	hat->tail = lf;
	return ;
}

static void	insert_new_head(t_hat *hat, t_hatlf *lf)
{
	lf->next = hat->head;
	hat->head = lf;
}

static void	insert_middle_or_end(t_hat *hat, t_hatlf *lf)
{
	t_hatlf	*current;

	current = hat->head;
	while (current->next && current->next->start_index < lf->start_index)
		current = current->next;
	lf->next = current->next;
	lf->prev = current;
	if (current->next)
		current->next->prev = lf;
	else
		hat->tail = lf;
	current->next = lf;
}

void		ft_hatinslf(t_hat *hat, t_hatlf *lf)
{
	if (hat->head == NULL)
		insert_first_leaf(hat, lf);
	else if (hat->head->start_index > lf->start_index)
		insert_new_head(hat, lf);
	else
		insert_middle_or_end(hat, lf);
}
