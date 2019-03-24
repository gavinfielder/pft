/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_getarg_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:53:37 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 19:57:14 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

/*
** -----------------------------------------------------------------------------
**                                 ftpf_getarg
** -----------------------------------------------------------------------------
**   description:  Loops through md->arg_getters until reaching desired index
**                 Sets void *dst to the requested argument.
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An argument getter function retrieves the next argument from the va_list
**   passed as a pointer. If void *dst is not null, it assigns to the memory
**   address pointed to by dst the value of the argument it retrieved from
**   the va_list.
** -----------------------------------------------------------------------------
*/

int			ftpf_getarg(t_ftpf_master_data *md, void *dst)
{
	void					*hatptr;
	va_list					args_copy;
	short					arg_num;
	short					i;
	t_ftpf_getarg_func		f;

	va_copy(args_copy, md->args);
	arg_num = (md->ex->arg_num < 0 ? md->next_arg_num : md->ex->arg_num);
	md->next_arg_num = arg_num + 1;
	i = 1;
	while (i < arg_num)
	{
		if (((hatptr = ft_hataccess(md->arg_getters, i)) == NULL)
				|| ((f = *((t_ftpf_getarg_func *)hatptr)) == NULL))
			return (FTPF_ERROR);
		f(NULL, &(args_copy));
		i++;
	}
	if (((hatptr = ft_hataccess(md->arg_getters, i)) == NULL)
			|| ((f = *((t_ftpf_getarg_func *)hatptr)) == NULL))
		return (FTPF_ERROR);
	f(dst, &(args_copy));
	va_end(args_copy);
	return (1);
}
