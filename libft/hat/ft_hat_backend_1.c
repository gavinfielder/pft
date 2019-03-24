/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_backend_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:27:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 17:35:22 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ----------------------------------------------------------------------------
**                                  ft_hat.c
** ----------------------------------------------------------------------------
**      This file contains backend functions for ft_hat. They are not
**      intended to be called by any function other than those in ft_hat.
** ----------------------------------------------------------------------------
**      1. ft_hat_get_end_index       gets a leaf's ending index from index
**      2. ft_hat_get_start_index     gets a leaf's starting index from index
**      3. ft_hatlfnew                creates a new t_hatlf structure
**      4. ft_hatdeltolf              deletes hat memory to a specified leaf
** ----------------------------------------------------------------------------
*/

int			ft_hat_get_end_index(t_hat *hat, int index)
{
	return (ft_hat_get_start_index(hat, index) + hat->leaf_capacity - 1);
}

int			ft_hat_get_start_index(t_hat *hat, int index)
{
	if (index < 0)
	{
		index -= ((int)(hat->leaf_capacity) - 1);
		return (((index / (int)(hat->leaf_capacity))
					* (int)(hat->leaf_capacity)));
	}
	return ((index / hat->leaf_capacity) * hat->leaf_capacity);
}

t_hatlf		*ft_hatlfnew(size_t leaf_capacity, size_t atom_size,
				int start_index)
{
	t_hatlf	*lf;

	lf = (t_hatlf *)malloc(sizeof(t_hatlf));
	if (lf == NULL)
		return (NULL);
	lf->data = malloc(leaf_capacity * atom_size);
	if (lf->data == NULL)
	{
		free(lf);
		return (NULL);
	}
	ft_bzero(lf->data, leaf_capacity * atom_size);
	lf->next = NULL;
	lf->prev = NULL;
	lf->start_index = start_index;
	return (lf);
}

void		ft_hatdeltolf(t_hat *hat, t_hatlf *lf)
{
	t_hatlf	*tmp;

	while (lf->prev)
	{
		tmp = lf->prev;
		ft_hatdellf(hat, &tmp);
	}
	while (lf->next)
	{
		tmp = lf->next;
		ft_hatdellf(hat, &tmp);
	}
}
