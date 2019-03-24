/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_getarg_ints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:36:46 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 20:09:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                       ftpf_getarg_[s|u]int_[bytes]
** -----------------------------------------------------------------------------
**   description:  pulls integers (signed and unsigned, 4 bytes and 8 bytes)
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An argument getter function retrieves the next argument from the va_list
**   passed as a pointer. If void *dst is not null, it assigns to the memory
**   address pointed to by dst the value of the argument it retrieved from
**   the va_list.
** -----------------------------------------------------------------------------
*/

void		ftpf_getarg_uint4(void *dst, va_list *args)
{
	unsigned int	ret;

	ret = va_arg((*args), unsigned int);
	if (dst)
		*((unsigned int *)dst) = ret;
}

void		ftpf_getarg_uint8(void *dst, va_list *args)
{
	unsigned long long	ret;

	ret = va_arg((*args), unsigned long long);
	if (dst)
		*((unsigned long long *)dst) = ret;
}

void		ftpf_getarg_sint4(void *dst, va_list *args)
{
	int	ret;

	ret = va_arg((*args), int);
	if (dst)
		*((int *)dst) = ret;
}

void		ftpf_getarg_sint8(void *dst, va_list *args)
{
	long long	ret;

	ret = va_arg((*args), long long);
	if (dst)
		*((long long *)dst) = ret;
}
