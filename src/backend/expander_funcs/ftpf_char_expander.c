/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_char_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 11:26:43 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 15:22:36 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                           ftpf_char_expander.c
** -----------------------------------------------------------------------------
**   specifier:    %c
**   description:  writes a character
**   options:      0,-,field_width
**   notes:        Prints unsigned char, but converts from signed int
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

static void					ftpf_handle_padding_char(t_ftpf_master_data *md,
								char **str)
{
	int		len;

	len = (int)ft_strlen(*str);
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad)
			ft_strinsert_nchr(str, '0', 0, md->ex->field_width - 1);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - 1);
		else if (len == 0)
			ft_strinsert_nchr(str, ' ', len, md->ex->field_width);
		else
			ft_strinsert_nchr(str, ' ', len, md->ex->field_width - 1);
	}
}

static int					write_null_terminator(t_ftpf_master_data *md,
								int i)
{
	if (md->max_len < 0 || md->len + i < md->max_len)
	{
		ft_mswrite_nullterm(md->ms);
		return (1);
	}
	return (0);
}

int							ftpf_char_expander(t_ftpf_master_data *md)
{
	char			*str;
	int				value;
	int				i;

	i = 0;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	if (value == 0 && md->ex->lfjusty)
	{
		i += write_null_terminator(md, i);
		str = ft_strdup("");
	}
	else
	{
		str = ft_strnew(1);
		str[0] = (unsigned char)value;
	}
	ftpf_handle_padding_char(md, &str);
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	if (value == 0 && !(md->ex->lfjusty))
		i += write_null_terminator(md, i);
	return (i);
}
