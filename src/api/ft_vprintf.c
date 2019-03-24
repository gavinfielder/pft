/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:31:05 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 20:31:37 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"
#include "libftprintf.h"

int		ft_vprintf(const char *fmt, va_list args)
{
	int				ret_val;

	ret_val = ft_vdprintf(1, fmt, args);
	return (ret_val);
}
