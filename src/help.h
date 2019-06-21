/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:14:31 by gfielder          #+#    #+#             */
/*   Updated: 2019/06/18 14:14:30 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
#define HELP_H

typedef void (*t_help_func) (void);

typedef struct		s_help_entry
{
	const char		*query;
	t_help_func		print;
}					t_help_entry;

extern const t_help_entry	help_index[];

void		help_index_search(char *str);
void		help_putchar(char c);
void		help_header(char *str);
void		help_example(char *str, int recommended);
void		help_example_explain(char *str);
void		help_paragraph(char *str);
void		help_list_item(char *bullet, char *str);
void		help_start_header(void);
void		help_basic(void);
void		help_naming_conventions(void);
void		help_debug(void);
void		help_adding_tests(void);
void		help_enabling_and_disabling(void);
void		help_return_value(void);
void		help_how_it_works(void);
void		help_contact(void);
void		help_options(void);
void		help_timeout(void);
void		help_test_history_logging(void);
void		help_include_disabled(void);
void		help_leaks_test(void);
void		help_fork_mode(void);
void		help_signal_handling(void);
void		help_print_info_option(void);
void		help_refresh_results(void);
void		help_default_run_options(void);
void		help_test_outdated_time(void);
void		help_remove_history_when_tests_new(void);
void		help_leaks_test_cmd(void);
void		help_test_fail_logging_maxbytes(void);
void		help_single_number_single_test(void);
void		help_single_test_turns_on_lldb_compat_mode(void);
void		help_libftprintf_dir(void);
void		help_troubleshooting(void);
void		help_conf(void);
void		help_list_index(void);
void		help_aux_filter_options(void);
void		help_wildcard_search(void);

#endif
