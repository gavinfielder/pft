/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_expandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:53:17 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 00:14:43 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"
#include <stdarg.h>

void						ftpf_expandler_init(t_ftpf_expandler *ex,
						const char *start)
{
	ft_bzero(ex, sizeof(t_ftpf_expandler));
	ex->start = start;
	ex->arg_num = -1;
	ex->check_flags = FTPF_CHECKFLAG_INIT;
	ex->handled_len = 1;
	ex->total_specifier_len = 1;
	ex->precision = -1;
}

void						ftpf_read_specifier(t_ftpf_expandler *ex)
{
	int			i;

	i = 0;
	while (ex->check_flags)
	{
		if (ex->check_flags & (1 << (i % FTPF_NUM_CHECKFLAGS)))
		{
			if (g_checkfuncs[i % FTPF_NUM_CHECKFLAGS](ex))
				i = 0;
		}
		i++;
		if (i >= FTPF_NUM_CHECKFLAGS + 1)
			break ;
	}
	ex->total_specifier_len = ex->handled_len;
}

static t_ftpf_getarg_func	ftpf_get_which_getter_sint(t_ftpf_expandler *ex)
{
	return ((ex->size_mod == FTPF_SIZEMOD_L
					|| ex->size_mod == FTPF_SIZEMOD_LL)
				? ftpf_getarg_sint8 : ftpf_getarg_sint4);
}

static t_ftpf_getarg_func	ftpf_get_which_getter_uint(t_ftpf_expandler *ex)
{
	return ((ex->size_mod == FTPF_SIZEMOD_L
					|| ex->size_mod == FTPF_SIZEMOD_LL)
				? ftpf_getarg_uint8 : ftpf_getarg_uint4);
}

t_ftpf_getarg_func			ftpf_get_which_getter(t_ftpf_expandler *ex)
{
	if (ex->expand == NULL || ex->expand == ftpf_extension_expander
			|| ex->expand == ftpf_percent_expander)
		return (ftpf_getarg_null);
	if (ex->expand == ftpf_char_expander)
		return (ftpf_getarg_sint4);
	if (ex->expand == ftpf_ptr_expander
			|| ex->expand == ftpf_string_expander
			|| ex->expand == ftpf_memory_expander
			|| ex->expand == ftpf_binary_expander)
		return (ftpf_getarg_ptr);
	if (ex->expand == ftpf_signed_int_expander)
		return (ftpf_get_which_getter_sint(ex));
	if (ex->expand == ftpf_unsigned_int_expander
			|| ex->expand == ftpf_hexlower_expander
			|| ex->expand == ftpf_hexupper_expander
			|| ex->expand == ftpf_octal_expander)
		return (ftpf_get_which_getter_uint(ex));
	if (ex->expand == ftpf_float_expander)
		return (ex->size_mod == FTPF_SIZEMOD_BIGL ?
			ftpf_getarg_floatl : ftpf_getarg_float);
	else
		return (ftpf_getarg_null);
}
