/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:54:40 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 23:49:57 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checker_funcs_index.c
** -----------------------------------------------------------------------------
**   Contains:   g_checkfuncs[]
**               number_len
** -----------------------------------------------------------------------------
**                            general reminders
** -----------------------------------------------------------------------------
**   A checker function checks for only one possibility.
**   A checker function will only be called when its respective bit in
**   ex->checkflags is set.
**   It begins checking at the char pointer (ex->start + ex->handled_len)
**   It returns 1 if matched, 0 if not matched
**   Upon matching, it will increment ex->handled_len for the number of
**   characters it matched.
**   A checker function manages ex->check_flags. Usually this means clearing
**   its own bit after not matching, and usually, upon matching, clearing
**   multiple bits that refer to newly invalid options.
**   If a checker function matches a final specifier (d,u,s,c,x, etc)
**   then it must fill ex->expand with the appropriate expander function
** -----------------------------------------------------------------------------
*/

const	t_ftpf_checker_func		g_checkfuncs[FTPF_NUM_CHECKFLAGS] =
{
	ftpf_check_percent,
	ftpf_get_arg_num,
	ftpf_check_zeropad_mod,
	ftpf_check_spacepad_mod,
	ftpf_check_alternate_form_mod,
	ftpf_check_leftjustify_mod,
	ftpf_check_alwayssign_mod,
	NULL,
	NULL,
	ftpf_check_fieldwidth_mod,
	ftpf_check_precision_mod,
	ftpf_check_shortshort_mod,
	ftpf_check_short_mod,
	ftpf_check_longlong_mod,
	ftpf_check_long_mod,
	ftpf_check_longdouble_mod,
	ftpf_check_ptr_expansion,
	ftpf_check_signed_int_expansion,
	ftpf_check_binary_expansion,
	ftpf_check_unsigned_int_expansion,
	ftpf_check_hexlower_expansion,
	ftpf_check_hexupper_expansion,
	ftpf_check_float_expansion,
	ftpf_check_string_expansion,
	ftpf_check_char_expansion,
	ftpf_check_octal_expansion,
	ftpf_check_memory_expansion,
	ftpf_check_extension_expansion,
};

int						number_len(t_ftpf_expandler *ex)
{
	int		i;
	char	c;

	i = 0;
	c = *(ex->start + ex->handled_len + i);
	while (1)
	{
		if (!(c >= '0' && c <= '9'))
			return (i);
		i++;
		c = *(ex->start + ex->handled_len + i);
	}
	return (0);
}
