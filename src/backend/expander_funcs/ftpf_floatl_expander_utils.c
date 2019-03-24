/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_floatl_expander_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:27:58 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 21:03:50 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

unsigned long		ftpf_fltl_get_ipart(long double dbl)
{
	if (dbl < 0)
		dbl = -dbl;
	return (((unsigned long)dbl));
}

long double			ftpf_fltl_get_fpart(long double dbl)
{
	if (dbl < 0)
		dbl = -dbl;
	return (dbl - ftpf_fltl_get_ipart(dbl));
}

void				ftpf_fltl_get_fpul(t_ftpf_master_data *md,
						t_ftpf_fltl_hlpr *h)
{
	long double		mul;
	int				i;
	int				len;

	i = 0;
	mul = 10.0l;
	while (!(h->run_once) || i < md->ex->precision)
	{
		h->fpul = h->fpul * 10 + (((unsigned long)(h->fp_actual * mul)) % 10);
		i++;
		mul *= 10.0l;
		if (md->ex->precision != 0 && i == md->ex->precision &&
				(((unsigned long)(h->fp_actual * mul)) % 10) >= 5)
			h->fpul++;
		h->run_once = 1;
	}
	len = ftpf_flt_ul_len(h->fpul);
	if (md->ex->precision && len > md->ex->precision)
	{
		h->ip++;
		h->fpul = 0;
		len = 1;
	}
	else if (md->ex->precision == 0 && h->fpul >= 5)
		h->ip++;
}

t_ftpf_fltl_hlpr	*ftpf_fltl_hlpr_new(long double actual)
{
	t_ftpf_fltl_hlpr		*h;

	h = (t_ftpf_fltl_hlpr *)malloc(sizeof(t_ftpf_fltl_hlpr));
	h->actual = actual;
	h->fp_actual = ftpf_fltl_get_fpart(actual);
	h->ip = ftpf_fltl_get_ipart(actual);
	h->fpul = 0;
	h->run_once = 0;
	return (h);
}
