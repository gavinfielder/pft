/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_getarg_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:49:28 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 20:11:40 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                            ftpf_getarg_[other]
** -----------------------------------------------------------------------------
**   description:
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An argument getter function retrieves the next argument from the va_list
**   passed as a pointer. If void *dst is not null, it assigns to the memory
**   address pointed to by dst the value of the argument it retrieved from
**   the va_list.
** -----------------------------------------------------------------------------
*/

void		ftpf_getarg_null(void *dst, va_list *args)
{
	dst = NULL;
	args = NULL;
}

void		ftpf_getarg_ptr(void *dst, va_list *args)
{
	void	*ret;

	ret = va_arg((*args), void *);
	if (dst)
		*((void **)dst) = ret;
}

void		ftpf_getarg_float(void *dst, va_list *args)
{
	double	ret;

	ret = va_arg((*args), double);
	if (dst)
		*((double *)dst) = ret;
}

void		ftpf_getarg_floatl(void *dst, va_list *args)
{
	long double		ret;

	ret = va_arg((*args), long double);
	if (dst)
		*((long double *)dst) = ret;
}
