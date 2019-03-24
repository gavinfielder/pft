/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:54:18 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 20:59:47 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"
#include "ftpf_backend.h"

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list			args;
	t_stringbuilder	*sb;
	int				ret_val;

	if (ret == NULL)
		return (-1);
	sb = ft_sbnew();
	if (sb == NULL)
		return (-1);
	va_start(args, fmt);
	ret_val = ft_vsbprintf(sb, fmt, args);
	*ret = ft_sbtostr(sb);
	if (*ret == NULL)
		return (-1);
	ft_sbdel(&sb);
	va_end(args);
	return (ret_val);
}
