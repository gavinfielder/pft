/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_signed_int_expander.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:53:04 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 21:06:27 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"
#include <stdlib.h>

/*
** -----------------------------------------------------------------------------
**                             ftpf_signed_int_expander
** -----------------------------------------------------------------------------
**   specifier:    %d, %i
**   description:  writes a signed integer
**   options:      0,-,+,' ',field_width,.,hh,h,l,ll
**   notes:        precision means minimum digits (left pad with zero)
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len (+written) < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void					ftpf_handle_padding_sint(t_ftpf_master_data *md,
								char **str)
{
	size_t	str_len;
	int		sign;

	sign = (((*str)[0] == '-' || md->ex->allsign || md->ex->space) ? 1 : 0);
	if ((*str)[0] != '-' && sign)
		ft_strinsert_nchr(str, md->ex->allsign ? '+' : ' ', 0, 1);
	str_len = ft_strlen(*str);
	if (md->ex->precision > 0)
	{
		ft_strinsert_nchr(str, '0', sign, md->ex->precision - str_len + sign);
		str_len = ft_strlen(*str);
	}
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad && (md->ex->precision <= 0))
			ft_strinsert_nchr(str, '0', sign, md->ex->field_width - str_len);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ',
					0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ',
					str_len, md->ex->field_width - str_len);
	}
}

static int					ftpf_signed_int_expander_l(t_ftpf_master_data *md)
{
	char		*str;
	long long	value;
	int			i;

	value = 0ll;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	str = ft_litoa(value);
	ftpf_handle_padding_sint(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}

int							ftpf_signed_int_expander(t_ftpf_master_data *md)
{
	char		*str;
	int			value;
	int			i;

	if (md->ex->size_mod == FTPF_SIZEMOD_L
			|| md->ex->size_mod == FTPF_SIZEMOD_LL)
		return (ftpf_signed_int_expander_l(md));
	value = 0;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	str = ft_litoa(value);
	ftpf_handle_padding_sint(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
