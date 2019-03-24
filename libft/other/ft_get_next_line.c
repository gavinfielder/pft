/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:05:27 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/24 14:30:25 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

const char			g_init[] =
"\0\0\0\0\0\0\0\0\xff\xff\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

static size_t		get_leaf_size(void)
{
	size_t	leaf_size;

	leaf_size = GNL_BUFF_SIZE;
	while (leaf_size < MIN_LEAF_SIZE)
	{
		leaf_size <<= 1;
	}
	return (leaf_size);
}

static t_fdhandler	*access_fdhandler(t_fdhandler **of, int fd,
						int action, t_fdhandler_u *current)
{
	current = (t_fdhandler_u *)(*of);
	while (current && current->a.fd != fd && current->a.next)
		current = (t_fdhandler_u *)(current->a.next);
	if (current == NULL || current->a.fd != fd)
	{
		MALLOC_GUARDN(current = (t_fdhandler_u *)malloc(sizeof(t_fdhandler)));
		ft_memcpy(current->i.nums, g_init, 28);
		current->a.fd = fd;
		current->a.hat = ft_hatnew(get_leaf_size(), 1);
		current->a.next = (*of);
		if (*of)
			(*of)->prev = (t_fdhandler *)current;
		*of = (t_fdhandler *)current;
		return ((t_fdhandler *)current);
	}
	else if (action == FDH_GET)
		return ((t_fdhandler *)current);
	ft_hatdel(&(current->a.hat));
	if (*of == (t_fdhandler *)current)
		*of = current->a.next;
	if (current->a.prev)
		current->a.prev->next = current->a.next;
	if (current->a.next)
		current->a.next->prev = current->a.prev;
	return (ft_memdelr((void *)(&current)));
}

static int			hat_getline(t_fdhandler *h)
{
	while ((!(h->found)) && (h->bytes_to_eof))
	{
		if (h->index % GNL_BUFF_SIZE == 0 && h->bytes_to_eof != 0)
		{
			h->check = (char *)ft_hataccess(h->hat, h->index);
			MALLOC_GUARD(h->check);
			h->bytes = read(h->fd, h->check, GNL_BUFF_SIZE);
			if (h->bytes < 0)
				return (GNL_ERROR);
			if (h->bytes < GNL_BUFF_SIZE)
				h->bytes_to_eof = h->bytes;
			if (h->bytes_to_eof == 0)
				return (GNL_OK);
		}
		if (h->bytes && *(h->check) == '\n')
			h->found = 1;
		else
			h->total_bytes++;
		h->check++;
		h->index++;
		if (h->bytes_to_eof)
			h->bytes_to_eof--;
	}
	return (GNL_OK);
}

static void			hat_cleanup(t_fdhandler *h)
{
	t_hatlf	*tmp;

	while (h->hat->tail->prev)
	{
		tmp = h->hat->tail->prev;
		ft_hatdellf(h->hat, &tmp);
	}
	h->line_start -= h->hat->head->start_index;
	h->hat->head->start_index = 0;
	if (h->hat->head->next)
		h->hat->head->next->start_index = h->hat->leaf_capacity;
}

int					ft_get_next_line(const int fd, char **line)
{
	static t_fdhandler	*of = NULL;
	t_fdhandler_u		*current;
	t_fdhandler			*h;

	current = NULL;
	MALLOC_GUARD(h = access_fdhandler(&of, fd, FDH_GET, current));
	if (!(h->bytes_to_eof) && !(access_fdhandler(&of, fd, FDH_RMV, current)))
		return (GNL_EOF);
	h->found = 0;
	h->total_bytes = h->index - h->line_start;
	if (hat_getline(h) == GNL_ERROR)
		return (GNL_ERROR);
	if (h->found || h->index != h->line_start)
	{
		MALLOC_GUARD(*line = ft_hat_toarr(h->hat, h->line_start,
					h->total_bytes));
		h->line_start = h->index;
		hat_cleanup(h);
		h->index = h->line_start;
		return (GNL_OK);
	}
	if (h->bytes_to_eof == 0)
		return (GNL_EOF);
	return (GNL_ERROR);
}
