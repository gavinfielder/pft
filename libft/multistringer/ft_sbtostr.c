/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbtostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:03:09 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/26 16:46:01 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sbtostr(t_stringbuilder *sb)
{
	char	*str;

	str = (char *)ft_hat_toarr(sb->hat, 0, sb->len);
	return (str);
}
