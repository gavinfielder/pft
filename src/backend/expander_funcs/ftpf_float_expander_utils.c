/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_float_expander_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:27:58 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 19:33:28 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

unsigned long		ftpf_flt_get_ipart(double dbl)
{
	if (dbl < 0)
		dbl = -dbl;
	return ((unsigned long)dbl);
}

double				ftpf_flt_get_fpart(double dbl)
{
	if (dbl < 0)
		dbl = -dbl;
	return (dbl - ftpf_flt_get_ipart(dbl));
}

int					ftpf_flt_ul_len(unsigned long n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void				ftpf_flt_get_fpul(t_ftpf_master_data *md,
						t_ftpf_flt_hlpr *h)
{
	double	mul;
	int		i;
	int		len;

	i = 0;
	mul = 10.0;
	while (!(h->run_once) || i < md->ex->precision)
	{
		h->fpul = h->fpul * 10 + (((unsigned long)(h->fp_actual * mul)) % 10);
		i++;
		mul *= 10.0;
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

t_ftpf_flt_hlpr		*ftpf_flt_hlpr_new(double actual)
{
	t_ftpf_flt_hlpr		*h;

	h = (t_ftpf_flt_hlpr *)malloc(sizeof(t_ftpf_flt_hlpr));
	h->actual = actual;
	h->fp_actual = ftpf_flt_get_fpart(actual);
	h->ip = ftpf_flt_get_ipart(actual);
	h->fpul = 0;
	h->run_once = 0;
	return (h);
}
