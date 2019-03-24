/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:37:27 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 18:12:17 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

/*
** ----------------------------------------------------------------------------
**                                ft_hat_aux.c
** ----------------------------------------------------------------------------
**      This file holds additional useful function for ft_hat.
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
**      1. ft_hatprint    prints a hat structure (mostly for debug purposes)
**                        options for print mode are:
**                            FT_HAT_PRINTMODE_HEX
**                            FT_HAT_PRINTMODE_ASC
**      2. ft_hatreindex  reindexes a hat starting at the head. This changes
**                        the index of all slots and returns the difference.
** ----------------------------------------------------------------------------
**                                    Safety
** ----------------------------------------------------------------------------
**      ft_hatprint guarantees safety provided only provided public interface
**      funtions were used to manage the t_hat.
**
**      ft_hatreindex does not guarantee safety, and can break the t_hat
**      structure for all future operations on it if the new start index is
**      neither 0 nor a multiple of leaf_capacity. It was designed with
**      reindexing to zero in mind, and is reasonably safe in this case.
**      Otherwise use with caution. If reindexing to a number that is not a
**      multiple of leaf_capacity, it is recommended to not perform further
**      operations on the t_hat.
** ----------------------------------------------------------------------------
**                                 Dependencies
** ----------------------------------------------------------------------------
**      ft_putnbr, ft_printhexbyte, ft_putchar_np
** ----------------------------------------------------------------------------
*/

static void		print_leaf_data(const t_hat *hat, t_hatlf *lf,
		int data_display_format)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < hat->leaf_capacity)
	{
		j = 0;
		while (j < hat->atom_size)
		{
			if (data_display_format == FT_HAT_PRINTMODE_HEX)
				ft_printhexbyte(lf->data + hat->atom_size * i + j);
			else if (data_display_format == FT_HAT_PRINTMODE_ASC)
				ft_putchar_np(*((char *)(lf->data + hat->atom_size * i + j)),
						'@');
			j++;
		}
		if (i != hat->leaf_capacity - 1)
			write(1, ".", 1);
		i++;
	}
}

static void		print_leaf(const t_hat *hat, t_hatlf *lf,
					int data_display_format)
{
	write(1, "  index ", 8);
	ft_putnbr(lf->start_index);
	write(1, "\t[", 2);
	print_leaf_data(hat, lf, data_display_format);
	write(1, "]\n", 2);
}

void			ft_hatprint(t_hat *hat, int data_display_format)
{
	t_hatlf	*current;

	if (hat == NULL)
	{
		write(1, "(NULL)\n", 7);
		return ;
	}
	if (hat->head == NULL)
	{
		write(1, "(empty hat)\n", 12);
		return ;
	}
	current = hat->head;
	while (current)
	{
		print_leaf(hat, current, data_display_format);
		current = current->next;
	}
}

int				ft_hatreindex(t_hat *hat, int head_index)
{
	int		prev_old_index;
	int		prev_new_index;
	int		difference;
	t_hatlf	*current;

	if (hat == NULL || hat->head == NULL)
		return (0);
	current = hat->head;
	prev_old_index = current->start_index;
	current->start_index = head_index;
	prev_new_index = head_index;
	difference = prev_new_index - prev_old_index;
	current = current->next;
	while (current)
	{
		current->start_index += difference;
		current = current->next;
	}
	return (difference);
}
