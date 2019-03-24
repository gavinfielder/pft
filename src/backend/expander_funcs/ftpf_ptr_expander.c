/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_ptr_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:58:55 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 21:06:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                             ftpf_ptr_expander.c
** -----------------------------------------------------------------------------
**   specifier:    %p
**   description:  writes a memory address in hexadecimal
**   options:      0,-,field_width
**   notes:        Same as %#lx
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len + written < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

int			ftpf_ptr_expander(t_ftpf_master_data *md)
{
	md->ex->altform = 1;
	md->ex->size_mod = FTPF_SIZEMOD_L;
	md->ex->precision = -1;
	return (ftpf_hexlower_expander(md));
}
