/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:30:36 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/23 16:03:06 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftpf_backend.h"
#include <stdarg.h>

static t_ftpf_getarg_func	ftpf_preprocess_helper(t_ftpf_master_data *md, int *j)
{
	void				*hatptr;
	t_ftpf_getarg_func	f;

	f = ftpf_get_which_getter(md->ex);
	if (f != NULL && f != ftpf_getarg_null)
	{
		if (md->ex->arg_num > 0)
			*j = md->ex->arg_num;
		if ((hatptr = ft_hataccess(md->arg_getters, *j)) == NULL)
			return (NULL);
		*((t_ftpf_getarg_func *)(hatptr)) = f;
	}
	return (f);
}

static int					ftpf_preprocess(const char *fmt, t_ftpf_master_data *md)
{
	int					i;
	int					j;
	t_ftpf_getarg_func	f;

	i = 0;
	j = 1;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ftpf_expandler_init(md->ex, fmt + i);
			ftpf_read_specifier(md->ex);
			if ((f = ftpf_preprocess_helper(md, &j)) == NULL)
				return (FTPF_ERROR);
			i += md->ex->total_specifier_len;
			if (f != ftpf_getarg_null)
				j++;
		}
		else
			i++;
	}
	return (i);
}

static int					ftpf_master_helper(const char *fmt, t_ftpf_master_data *md)
{
	int		i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ftpf_expandler_init(md->ex, fmt + i);
			ftpf_read_specifier(md->ex);
			if (md->ex->expand)
				(md->len) += md->ex->expand(md);
			i += md->ex->total_specifier_len;
		}
		else
		{
			if (md->max_len < 0 || md->len < md->max_len)
				ft_mswriten(md->ms, fmt + i, 1);
			(md->len)++;
			i++;
		}
	}
	return (md->len);
}

int							ftpf_master(t_multistringer *ms, const char *fmt,
								int max_len, va_list args)
{
	t_ftpf_master_data	md;
	t_ftpf_expandler	ex;
	int					ret;

	md.next_arg_num = 1;
	md.ms = ms;
	md.len = 0;
	md.max_len = max_len;
	va_copy(md.args, args);
	md.ex = &ex;
	md.arg_getters = ft_hatnew(16, sizeof(t_ftpf_getarg_func));
	if ((ret = ftpf_preprocess(fmt, &md)) < 0)
		return (ret);
	ret = ftpf_master_helper(fmt, &md);
	ft_hatdel(&(md.arg_getters));
	return (ret);
}
