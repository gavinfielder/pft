/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_hexlower_expander.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:11:00 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 00:10:08 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                           ftpf_hexlower_expander.c
** -----------------------------------------------------------------------------
**   specifier:    %x
**   description:  Prints an unsigned integer in lowercase hexadecimal
**   options:      #,0,-,hh,h,l,ll,.
**   notes:        # prints leading 0x
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswrite(md->ms, "...")
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void					ftpf_handle_padding_hexl(t_ftpf_master_data *md,
								char **str, int is_zero)
{
	size_t	str_len;

	str_len = ft_strlen(*str);
	if (md->ex->precision > 0)
	{
		ft_strinsert_nchr(str, '0', 0, md->ex->precision - str_len);
	}
	if ((md->ex->altform && !is_zero) || (md->ex->expand == ftpf_ptr_expander))
		ft_strjoin_inplace_rev("0x", str);
	str_len = ft_strlen(*str);
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad && (md->ex->precision <= 0))
			ft_strinsert_nchr(str, '0', (md->ex->altform * 2) * (!(is_zero)),
					md->ex->field_width - str_len);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ',
					0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ',
					str_len, md->ex->field_width - str_len);
	}
}

int							ftpf_hexlower_expander(t_ftpf_master_data *md)
{
	char		*str;
	t_ftuint8	value;
	int			i;

	value = 0ull;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	str = ft_luitoa_base_lower(value, 16);
	ftpf_handle_padding_hexl(md, &str, value == 0);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
