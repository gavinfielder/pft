/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_floatl_expander.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:31:53 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 20:58:05 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                             ftpf_float_expander
** -----------------------------------------------------------------------------
**   specifier:    %f
**   description:  Writes a double
**   options:      #,0,-,+,field_width,.,L
**   notes:        No precision is 6 precision; . appearing w/o ## means 0 prec.
**                 Zero precision shows no decimal, unless # altform.
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void		guarantee_precision(t_ftpf_master_data *md)
{
	if (md->ex->precision < 0)
		md->ex->precision = 6;
}

int				ftpf_floatl_expander(t_ftpf_master_data *md)
{
	char				*str;
	t_ftpf_fltl_hlpr	*h;
	long double			val;
	int					i;

	if (ftpf_getarg(md, &val) < 0)
		return (0);
	if ((str = ftpf_fltl_check_special(val)))
		return (ftpf_expand_special_float(md, str));
	guarantee_precision(md);
	h = ftpf_fltl_hlpr_new(val);
	ftpf_fltl_get_fpul(md, h);
	str = ftpf_flt_hlpr_get_str(md, FTBF_GET_SGN_LD(val), (t_ftpf_flt_hlpr *)h);
	free(h);
	ftpf_handle_padding_float(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	return (i);
}
