/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:45 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/08 14:49:53 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"

int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list args)
{
	t_multistringer	*ms;
	int				ret_val;

	ms = (t_multistringer *)ft_swnew(str, size);
	if (!ms)
		return (FTPF_ERROR);
	ret_val = ftpf_master(ms, fmt, size, args);
	ft_swdel((t_stringwriter **)(&ms));
	return (ret_val);
}
