/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsbprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:36:51 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 19:48:28 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"

int		ft_vsbprintf(t_stringbuilder *sb, const char *fmt, va_list args)
{
	t_multistringer	*ms;

	ms = (t_multistringer *)sb;
	return (ftpf_master(ms, fmt, FTPF_UNLIMITED_LEN, args));
}
