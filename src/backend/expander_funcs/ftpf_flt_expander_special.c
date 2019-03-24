/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_flt_expander_special.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:46:42 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/19 21:56:30 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

char		*ftpf_flt_check_special(double dbl)
{
	if ((FTBF_MASK_EXP_D(dbl) >> FTBF_MBITS_D) == 0x7FF)
	{
		if ((FTBF_RAW_MASK_MTS_D(dbl)) == 0)
			return (ft_strdup(FTBF_MASK_SGN_D(dbl) ? "-inf" : "inf"));
		else
			return (ft_strdup("nan"));
	}
	return (NULL);
}

char		*ftpf_fltl_check_special(long double dbl)
{
	if (FTBF_MASK_EXP_LD(dbl) == 0x7FFF)
	{
		if ((FTBF_MASK_MTS_LD(dbl)) == 0x8000000000000000ull)
			return (ft_strdup(FTBF_MASK_SGN_LD(dbl) ? "-inf" : "inf"));
		else
			return (ft_strdup("nan"));
	}
	return (NULL);
}

int			ftpf_expand_special_float(t_ftpf_master_data *md, char *str)
{
	int		i;

	md->ex->zpad = 0;
	if (str[0] == 'i' && (md->ex->space || md->ex->allsign))
		ft_strinsert_nchr(&str, md->ex->allsign ? '+' : ' ', 0, 1);
	ftpf_handle_padding_float(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	return (i);
}
