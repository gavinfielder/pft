/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:42:52 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 21:00:21 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"
#include "libftprintf.h"

int		ft_sbprintf(t_stringbuilder *sb, const char *fmt, ...)
{
	va_list		args;
	int			ret;

	va_start(args, fmt);
	ret = ft_vsbprintf(sb, fmt, args);
	va_end(args);
	return (ret);
}
