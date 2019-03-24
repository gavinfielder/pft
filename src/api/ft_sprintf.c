/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:45:28 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 21:00:49 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"
#include "libftprintf.h"

int		ft_sprintf(char *buff, const char *fmt, ...)
{
	va_list			args;
	int				ret_val;

	if (buff == NULL)
		return (-1);
	va_start(args, fmt);
	ret_val = ft_vsprintf(buff, fmt, args);
	va_end(args);
	return (ret_val);
}
