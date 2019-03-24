/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_unsigned_int_expander.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:58:56 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 21:06:45 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"
#include <stdlib.h>

/*
** -----------------------------------------------------------------------------
**                             ftpf_unsigned_int_expander
** -----------------------------------------------------------------------------
**   specifier:    %u
**   description:  writes an unsigned integer
**   options:      0,-,field_width,.,hh,h,l,ll
**   notes:        none
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void					ftpf_handle_padding_uint(t_ftpf_master_data *md,
								char **str)
{
	size_t	str_len;

	str_len = ft_strlen(*str);
	if (md->ex->precision > 0)
	{
		ft_strinsert_nchr(str, '0', 0, md->ex->precision - str_len);
		str_len = ft_strlen(*str);
	}
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad && (md->ex->precision <= 0))
			ft_strinsert_nchr(str, '0', 0, md->ex->field_width - str_len);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ',
					0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ',
					str_len, md->ex->field_width - str_len);
	}
}

int							ftpf_unsigned_int_expander(t_ftpf_master_data *md)
{
	char		*str;
	t_ftuint8	value;
	int			i;

	value = 0ull;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	str = ft_luitoa(value);
	ftpf_handle_padding_uint(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
