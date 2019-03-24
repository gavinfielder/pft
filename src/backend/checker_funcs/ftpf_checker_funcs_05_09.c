/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_05_09.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:29:01 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 23:46:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checkerfuncs_05_09.c
** -----------------------------------------------------------------------------
**   Contains:   ftpf_check_leftjustify_mod (5)
**               ftpf_check_alwayssign_mod (6)
**               (NULL) (7)
**               (NULL) (8)
**               ftpf_check_fieldwidth_mod (9)
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

int								ftpf_check_leftjustify_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '-')
	{
		ex->check_flags &= 0xFFFFFFFD;
		ex->handled_len++;
		ex->lfjusty = 1;
		return (1);
	}
	return (0);
}

int								ftpf_check_alwayssign_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '+')
	{
		ex->check_flags &= 0xFFFFFFFC;
		ex->handled_len++;
		ex->allsign = 1;
		return (1);
	}
	return (0);
}

int								ftpf_check_fieldwidth_mod(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) >= '1'
			&& *(ex->start + ex->handled_len) <= '9')
	{
		len = number_len(ex);
		ex->field_width = (unsigned short)ft_atoi(ex->start + ex->handled_len);
		ex->handled_len += len;
		ex->check_flags &= 0xFFFFFD81;
		return (1);
	}
	ex->check_flags &= ~(1 << 9);
	return (0);
}
