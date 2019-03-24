/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_memory_expander.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:01:15 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 21:05:47 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                             ftpf_memory_expander
** -----------------------------------------------------------------------------
**   specifier:    %m
**   description:  Writes (precision) bytes of the memory space
**   options:      ' ',#,-,field_width,.,hh,h,ll,l,L
**   notes:        altform prints in ascii/np with '.', else prints in hexlower
**                 default precision is 4 unless size_mod is given
**                 space padding puts spaces between each 2 bytes
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void				ftpf_handle_padding_memory(t_ftpf_master_data *md,
							char **str)
{
	size_t	str_len;

	str_len = ft_strlen(*str);
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ', str_len, md->ex->field_width - str_len);
	}
}

static char				*get_str(t_ftpf_master_data *md, void *start)
{
	t_stringbuilder	*sb;
	char			*str;
	int				i;

	sb = ft_sbnew();
	i = 0;
	while (i < md->ex->precision)
	{
		if (md->ex->altform)
			ftpf_sbputchar_np(sb, *((char *)(start + i)),
					FTPF_NONPRINTABLE_REPLACECHAR);
		else
			ftpf_sbwrite_hexbyte(sb, start + i);
		i++;
		if (i != md->ex->precision && md->ex->space && !(md->ex->altform)
				&& i % 2 == 0)
			ft_sbwrite(sb, " ");
	}
	str = ft_sbtostr(sb);
	ft_sbdel(&sb);
	return (str);
}

int						ftpf_memory_expander(t_ftpf_master_data *md)
{
	char			*str;
	void			*start;
	int				i;

	if (ftpf_getarg(md, &start) < 0 || start == NULL)
		return (0);
	md->ex->precision = ftpf_guarantee_precision_memory(md);
	str = get_str(md, start);
	ftpf_handle_padding_memory(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
