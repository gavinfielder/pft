/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_20_24.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:43:38 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 16:42:27 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checker_funcs_20_24.c
** -----------------------------------------------------------------------------
**   Contains:   ftpf_check_hexlower_expansion (20)
**               ftpf_check_hexupper_expansion (21)
**               ftpf_check_float_expansion (22)
**               ftpf_check_string_expansion (23)
**               ftpf_check_char_expansion (24)
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

int		ftpf_check_hexlower_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'x')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_hexlower_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 20);
	return (0);
}

int		ftpf_check_hexupper_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'X')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_hexupper_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 21);
	return (0);
}

int		ftpf_check_float_expansion(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'f') ||
		(*(ex->start + ex->handled_len) == 'F'))
	{
		if (*(ex->start + ex->handled_len) == 'F')
			ex->size_mod = FTPF_SIZEMOD_L;
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_float_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 22);
	return (0);
}

int		ftpf_check_string_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 's')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_string_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 23);
	return (0);
}

int		ftpf_check_char_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'c')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_char_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 24);
	return (0);
}
