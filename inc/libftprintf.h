/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:49:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 20:32:11 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

/*
** -----------------------------------------------------------------------------
**                                 User Options
** -----------------------------------------------------------------------------
*/

# define FTPF_NONPRINTABLE_REPLACECHAR '.'

/*
** -----------------------------------------------------------------------------
**                               Library Functions
** -----------------------------------------------------------------------------
*/

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_sprintf(char *str, const char *fmt, ...);
int		ft_asprintf(char **ret, const char *fmt, ...);
int		ft_sbprintf(t_stringbuilder *sb, const char *fmt, ...);
int		ft_snprintf(char *str, size_t size, const char *fmt, ...);

/*
** -----------------------------------------------------------------------------
**                            Variadic List ft_printf
** -----------------------------------------------------------------------------
*/

int		ft_vsbprintf(t_stringbuilder *sb, const char *fmt, va_list args);
int		ft_vdprintf(int fd, const char *fmt, va_list args);
int		ft_vsprintf(char *str, const char *fmt, va_list args);
int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list args);
int		ft_vprintf(const char *fmt, va_list args);

#endif
