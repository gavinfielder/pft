/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_extension_expander.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:05:56 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 20:53:33 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"
#include "ftpf_extension.h"
#include "libftprintf.h"

/*
** -----------------------------------------------------------------------------
**                             ftpf_extension_expander
** -----------------------------------------------------------------------------
**   specifier:    %{...}
**   description:  specifies any range of extended functionality
**   options:      no options
**   notes:        No extended functionality may use arguments from md->args
** -----------------------------------------------------------------------------
**                             general reminders
** -----------------------------------------------------------------------------
**   An expander function writes with ft_mswriten(md->ms, "...", 1)
**   and returns the number of characters written.
**   It writes one character at a time only if md->len (+written) < md->max_len
**   md->ex is the expandler that holds all the option flags.
** -----------------------------------------------------------------------------
*/

const t_ftpf_ext_dict_entry	g_ftpf_ext_dict[] =
{
	{"", 0, 0},
	{"red", 1, 31},
	{"green", 1, 32},
	{"yellow", 1, 33},
	{"blue", 1, 34},
	{"magenta", 1, 35},
	{"cyan", 1, 36},
	{"white", 1, 37},
	{"bright", 0, 1},
	{"dim", 0, 2},
	{"italic", 0, 3},
	{"underline", 0, 4},
	{"reverse", 0, 5},
	{"hidden", 0, 6},
	{"black", 1, 30},
	{"black-background", 2, 40},
	{"red-background", 2, 41},
	{"green-background", 2, 42},
	{"yellow-background", 2, 43},
	{"blue-background", 2, 44},
	{"magenta-background", 2, 45},
	{"cyan-background", 2, 46},
	{"white-background", 3, 47},
	{"", -1, -1}
};

static t_ftpf_extension_spec	ftpf_extension_read(char **words)
{
	t_ftpf_extension_spec	spec;
	int						i;
	int						j;

	i = 3;
	while (i > 0)
		spec.codes[--i] = -1;
	while (words[i] != NULL)
	{
		j = 0;
		while (g_ftpf_ext_dict[j].code >= 0)
		{
			if (ft_strequ(g_ftpf_ext_dict[j].directive, words[i]))
			{
				spec.codes[g_ftpf_ext_dict[j].position] =
					g_ftpf_ext_dict[j].code;
				break ;
			}
			j++;
		}
		i++;
	}
	return (spec);
}

static char						*format_output(t_ftpf_extension_spec spec)
{
	char	*str;
	char	*tmp;
	int		valid;
	int		i;

	valid = 0;
	str = ft_strdup("\x1B[");
	i = 0;
	while (i < 3)
	{
		valid |= (spec.codes[i] >= 0);
		if (spec.codes[i] >= 0)
		{
			ft_asprintf(&tmp, "%s%i", valid ? ";" : "", spec.codes[i]);
			ft_strjoin_inplace(&str, tmp);
			free(tmp);
		}
		i++;
	}
	if (!valid)
		ft_strjoin_inplace(&str, "0");
	ft_strjoin_inplace(&str, "m");
	return (str);
}

int								ftpf_extension_expander(
									t_ftpf_master_data *md)
{
	char					*str;
	char					**words;
	t_ftpf_extension_spec	spec;
	int						i;

	str = ft_strsub(md->ex->start, 2, md->ex->total_specifier_len - 3);
	words = ft_strsplit(str, ' ');
	spec = ftpf_extension_read(words);
	ft_destroy_nullterm_ptrarray((void ***)(&words));
	free(str);
	str = format_output(spec);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	return (i);
}
