/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_25_29.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:45:40 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/07 12:51:16 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                          ftpf_checker_funcs_25_29.c
** -----------------------------------------------------------------------------
**   Contains:   ftpf_check_octal_expansion (25)
**               ftpf_check_memory_expansion (26)
**               ftpf_check_extension_expansion (27)
**               (NULL) (28)
**               (NULL) (29)
** -----------------------------------------------------------------------------
**   NOTE: ftpf_check_extension_expansion (27) can potentially invalidate
**         the expansion entirely by setting check_flags to 0 without
**         specifying an expander function. This happens on unclosed
**         {... brackets in the format string.
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

int		ftpf_check_octal_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'o')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_octal_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 25);
	return (0);
}

int		ftpf_check_memory_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'm')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_memory_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 26);
	return (0);
}

int		ftpf_check_extension_expansion(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) == '{')
	{
		len = 1;
		while (*(ex->start + ex->handled_len + len) != '\0' &&
				*(ex->start + ex->handled_len + len) != '}')
			len++;
		if (*(ex->start + ex->handled_len + len) == '}')
		{
			ex->handled_len += len + 1;
			ex->expand = ftpf_extension_expander;
			ex->check_flags = 0;
			return (1);
		}
		ex->handled_len = 2;
		ex->check_flags = 0;
		return (0);
	}
	ex->check_flags &= ~(1 << 27);
	return (0);
}
