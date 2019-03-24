/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_15_19.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:38:53 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 16:41:24 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checker_funcs_15_19.c
** -----------------------------------------------------------------------------
**   Contains:   ftpf_check_longdouble_mod (15)
**               ftpf_check_ptr_expansion (16)
**               ftpf_check_signed_int_expansion (17)
**               ftpf_check_binary_expansion (18)
**               ftpf_check_unsigned_int_expansion (19)
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

int		ftpf_check_longdouble_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'L')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_BIGL;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 15);
	return (0);
}

int		ftpf_check_ptr_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'p')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_ptr_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 16);
	return (0);
}

int		ftpf_check_signed_int_expansion(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'd') ||
		(*(ex->start + ex->handled_len) == 'i') ||
		(*(ex->start + ex->handled_len) == 'D'))
	{
		if (*(ex->start + ex->handled_len) == 'D')
			ex->size_mod = FTPF_SIZEMOD_L;
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_signed_int_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 17);
	return (0);
}

int		ftpf_check_binary_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'b')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_binary_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 18);
	return (0);
}

int		ftpf_check_unsigned_int_expansion(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'u') ||
		(*(ex->start + ex->handled_len) == 'U'))
	{
		if (*(ex->start + ex->handled_len) == 'U')
			ex->size_mod = FTPF_SIZEMOD_L;
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_unsigned_int_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 19);
	return (0);
}
