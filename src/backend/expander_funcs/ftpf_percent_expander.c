/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_percent_expander.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:26:59 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 23:57:55 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                             ftpf_percent_expander
** -----------------------------------------------------------------------------
**   specifier:    %%
**   description:  writes a '%'
**   options:      0,-,field_width
**   notes:        Uses no arguments from the va_list args.
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void						ftpf_handle_padding_pct(t_ftpf_master_data *md,
									char **str)
{
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad)
			ft_strinsert_nchr(str, '0', 0, md->ex->field_width - 1);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - 1);
		else
			ft_strinsert_nchr(str, ' ', 1, md->ex->field_width - 1);
	}
}

int								ftpf_percent_expander(
									t_ftpf_master_data *md)
{
	char	*str;
	int		i;

	str = ft_strdup("%");
	ftpf_handle_padding_pct(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
