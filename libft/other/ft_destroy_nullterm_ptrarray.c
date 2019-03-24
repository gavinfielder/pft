/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_nullterm_ptrarray.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:30:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/07 23:37:35 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_destroy_nullterm_ptrarray(void ***arr)
{
	int		i;

	if (arr == NULL || *arr == NULL)
		return ;
	i = 0;
	while ((*arr)[i] != NULL)
	{
		free(((*arr)[i]));
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
