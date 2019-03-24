/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:15 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 16:31:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ----------------------------------------------------------------------------
**                                  ft_hat.c
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
**      1. ft_hatnew      creates a new t_hat
**      2. ft_hatset      sets the requested index to be a copy of pointed data
**      3. ft_hataccess   returns a pointer to a requested index, first
**                        creating a new leaf if necessary
**      4. ft_hatdel      deletes a t_hat.
**
**      Also included in the public interface is ft_hat_toarr, ft_hatreindex,
**      and ft_hatprint, all of which are included in another file.
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_hat is designed to only hold one data type, and it is recommended
**      to use sizeof(type) when invoking ft_hatnew. Storing multiple data
**      types in a single t_hat does not guarantee safety for any operation.
**      ft_hatnew and ft_hataccess both return NULL on malloc failure.
**      ft_hatset relies on ft_hataccess, and if ft_hataccess fails, nothing
**      will be done.
**      Otherwise safety is guaranteed provided only the public interface
**      functions are used to manage t_hat structures.
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_memcpy, ft_bzero
** ----------------------------------------------------------------------------
*/

t_hat	*ft_hatnew(size_t leaf_capacity, size_t atom_size)
{
	t_hat	*hat;

	hat = (t_hat *)malloc(sizeof(t_hat));
	if (hat == NULL)
		return (NULL);
	hat->leaf_capacity = leaf_capacity;
	hat->atom_size = atom_size;
	hat->head = NULL;
	hat->tail = NULL;
	return (hat);
}

void	ft_hatset(t_hat *hat, int index, void *data)
{
	void	*ptr;

	ptr = ft_hataccess(hat, index);
	if (ptr == NULL)
		return ;
	ft_memcpy(ptr, data, hat->atom_size);
}

void	*ft_hataccess(t_hat *hat, int index)
{
	int		start_index;
	t_hatlf	*lf;
	t_hatlf	*current;

	if (hat == NULL)
		return (NULL);
	current = hat->head;
	start_index = ft_hat_get_start_index(hat, index);
	while (current && current->start_index < start_index)
		current = current->next;
	if (!current || current->start_index != start_index)
	{
		lf = ft_hatlfnew(hat->leaf_capacity, hat->atom_size, start_index);
		if (lf == NULL)
			return (NULL);
		ft_hatinslf(hat, lf);
		return (lf->data + ((index - start_index) * (hat->atom_size)));
	}
	return (current->data + ((index - start_index) * (hat->atom_size)));
}

void	ft_hatdel(t_hat **hat)
{
	t_hatlf	*tmp;

	while ((*hat)->head)
	{
		tmp = (*hat)->head;
		ft_hatdellf(*hat, &tmp);
	}
	free(*hat);
	*hat = NULL;
}
