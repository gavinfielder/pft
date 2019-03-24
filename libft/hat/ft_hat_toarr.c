/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_toarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:51:16 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 18:11:24 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ----------------------------------------------------------------------------
**                               ft_hat_toarr.c
** ----------------------------------------------------------------------------
**      This file contains the function that copies subsets of t_hat memory
**      into a contiguous memory space. It is a part of the public interface
**      for ft_hat.
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
**      1. ft_hat_toarr     Returns an array populated with a copy of a subset
**                          of the memory contained in the t_hat. The array
**                          will have a copy of the data starting at the given
**                          hat index, contain the specified number of
**                          elements, and be null terminated with a zero of
**                          the same size as the elements in the t_hat.
**
**                          If not all of the requested range of indices exist,
**                          the function will abort and return NULL.
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_hat_toarr returns NULL on malloc failure as well as returning NULL
**      if a leaf is missing in the requested interval of indices.
**      Safety is otherwise guaranteed provided only ft_hat public interface
**      funtions were used to manage the t_hat structure.
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_memcpy, ft_memalloc, ft_bzero (via ft_memalloc)
** ----------------------------------------------------------------------------
*/

static int	initial_error_checks(t_hat *hat, int index,
				t_hatlf **current, int *local)
{
	if (hat == NULL || hat->head == NULL)
		return (0);
	*current = hat->head;
	while ((int)((*current)->start_index + hat->leaf_capacity) - 1 < index)
		*current = (*current)->next;
	*local = index - (*current)->start_index;
	if (*local < 0 || *local >= (int)(hat->leaf_capacity))
		return (0);
	return (1);
}

static void	*abort_copy(void *arr)
{
	free(arr);
	return (NULL);
}

void		*ft_hat_toarr(t_hat *hat, int index, size_t count)
{
	void	*arr;
	t_hatlf	*cur;
	int		i;
	int		local;

	if (count == 0)
		return (ft_strdup(""));
	if (initial_error_checks(hat, index, &cur, &local) == 0 ||
			(!((arr = ft_memalloc(((count + 1) * hat->atom_size))))))
		return (NULL);
	i = 0;
	while (count--)
	{
		ft_memcpy(arr + i++, cur->data + local, hat->atom_size);
		index++;
		local++;
		if (local == (int)(hat->leaf_capacity))
		{
			cur = cur->next;
			local = 0;
			if ((!cur && count) || (cur != NULL && index != cur->start_index))
				return (abort_copy(arr));
		}
	}
	return (arr);
}
