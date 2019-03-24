/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_00-04.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:21:15 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 23:44:37 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checkerfuncs_00-04.c
** -----------------------------------------------------------------------------
**   Contains:   ftpf_check_percent (0)
**               ftpf_get_arg_num (1)
**               ftpf_check_zeropad_mod (2)
**               ftpf_check_spacepad_mod (3)
**               ftpf_check_alternate_form_mod (4)
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

int								ftpf_check_percent(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '%')
	{
		ex->check_flags &= 0x00000000;
		ex->handled_len++;
		ex->expand = ftpf_percent_expander;
		return (1);
	}
	return (0);
}

int								ftpf_get_arg_num(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) >= '1'
			&& *(ex->start + ex->handled_len) <= '9')
	{
		len = number_len(ex);
		if (*(ex->start + ex->handled_len + len) == '$')
		{
			ex->arg_num = (short)ft_atoi(ex->start + ex->handled_len);
			ex->handled_len += len + 1;
			ex->check_flags &= 0xFFFFFFFC;
			return (1);
		}
	}
	ex->check_flags &= ~(1 << 1);
	return (0);
}

int								ftpf_check_zeropad_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '0')
	{
		ex->check_flags &= 0xFFFFFFFD;
		ex->handled_len++;
		ex->zpad = 1;
		return (1);
	}
	return (0);
}

int								ftpf_check_spacepad_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == ' ')
	{
		ex->check_flags &= 0xFFFFFFFC;
		ex->handled_len++;
		ex->space = 1;
		return (1);
	}
	return (0);
}

int								ftpf_check_alternate_form_mod(
		t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '#')
	{
		ex->check_flags &= 0xFFFFFFFC;
		ex->handled_len++;
		ex->altform = 1;
		return (1);
	}
	return (0);
}
