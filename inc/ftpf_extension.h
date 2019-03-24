/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_extension.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:03:48 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 22:28:12 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_EXTENSION_H
# define FTPF_EXTENSION_H

typedef struct						s_ftpf_ext_dict_entry
{
	const char						directive[32];
	const int						position;
	const int						code;
}									t_ftpf_ext_dict_entry;

extern const t_ftpf_ext_dict_entry	g_ftpf_ext_dict[];

typedef struct						s_ftpf_extension_spec
{
	int								codes[3];
}									t_ftpf_extension_spec;

#endif
