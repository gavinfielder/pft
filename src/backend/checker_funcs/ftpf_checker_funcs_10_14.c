/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_10_14.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:33:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/17 18:39:30 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checker_funcs_10_14.c
** -----------------------------------------------------------------------------
**   Contains:   ftpf_check_precision_mod (10)
**               ftpf_check_shortshort_mod (11)
**               ftpf_check_short_mod (12)
**               ftpf_check_longlong_mod (13)
**               ftpf_check_long_mod (14)
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

int								ftpf_check_precision_mod(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) == '.')
	{
		ex->handled_len++;
		len = number_len(ex);
		ex->precision = (unsigned char)ft_atoi(ex->start + ex->handled_len);
		ex->handled_len += len;
		ex->check_flags &= 0xFFFFF980;
		return (1);
	}
	ex->check_flags &= ~(1 << 10);
	return (0);
}

int								ftpf_check_shortshort_mod(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'h') &&
		*(ex->start + ex->handled_len + 1) == 'h')
	{
		ex->handled_len += 2;
		ex->size_mod = FTPF_SIZEMOD_HH;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 11);
	return (0);
}

int								ftpf_check_short_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'h')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_H;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 12);
	return (0);
}

int								ftpf_check_longlong_mod(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'l') &&
		*(ex->start + ex->handled_len + 1) == 'l')
	{
		ex->handled_len += 2;
		ex->size_mod = FTPF_SIZEMOD_LL;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 13);
	return (0);
}

int								ftpf_check_long_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'l')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_L;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 14);
	return (0);
}
