/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_memory_and_binary_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:22:52 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 21:58:02 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

const static char	g_base[] = "0123456789abcdef";

int		ftpf_guarantee_precision_memory(t_ftpf_master_data *md)
{
	const int	default_prec[8] = {4, 1, 2, 8, 8, 16, 0, 0};

	if (md->ex->precision < 0)
		return (default_prec[md->ex->size_mod]);
	else
		return (md->ex->precision);
}

void	ftpf_sbwrite_hexbyte(t_stringbuilder *sb, const void *loc)
{
	if (sb == NULL || loc == NULL)
		return ;
	if (*((unsigned char *)loc) < 16)
		ft_sbwrite(sb, "0");
	else
		ft_sbwriten(sb, g_base + *((unsigned char *)loc) / 16, 1);
	ft_sbwriten(sb, g_base + *((unsigned char *)loc) % 16, 1);
}

void	ftpf_sbputchar_np(t_stringbuilder *sb, char c, char c_if_np)
{
	if (sb == NULL)
		return ;
	if (c >= 32 && c <= 126)
		ft_sbwriten(sb, &c, 1);
	else
		ft_sbwriten(sb, &c_if_np, 1);
}

void	ftpf_sbwrite_bit(t_stringbuilder *sb, const void *loc, int i)
{
	int		byte;
	int		j;

	if (loc == NULL || sb == NULL || i < 0)
		return ;
	byte = i / 8;
	j = i % 8;
	if (((const unsigned char *)loc)[byte] & (1 << j))
		ft_sbwrite(sb, "1");
	else
		ft_sbwrite(sb, "0");
}
