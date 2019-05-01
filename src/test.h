/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:10:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/01 05:37:43 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

#define LOG_FILE "log.txt"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define DIM   "\x1B[2m"
#define RESET "\x1B[0m"
#define FAULT "\x1B[0;31;43m"

#define DEBUG 0

#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

#define LDBL_INF   0x7FFF0000000000000000L
#define LDBL_NINF  0xFFFF0000000000000000L
#define LDBL_NAN   0x7FFF0000000001000000L
#define LDBL_PZERO 0x00000000000000000000L
#define LDBL_NZERO 0x80000000000000000000L

# define FTBF_MBITS_F 23
# define FTBF_MBITS_D 52
# define FTBF_MBITS_LD 64

# define FTBF_BIAS_F 127
# define FTBF_BIAS_D 1023
# define FTBF_BIAS_LD 16382

# define FTBFM1 0x000FFFFFFFFFFFFF
# define FTBF_MASK_SGN_D(x) ((*((long *)(&x))) & 0x8000000000000000)
# define FTBF_MASK_EXP_D(x) ((*((long *)(&x))) & 0x7FF0000000000000)
# define FTBF_MASK_MTS_D(x) (((*((t_ui8 *)(&x))) & FTBFM1) | (1ull << 52))
# define FTBF_RAW_MASK_MTS_D(x) ((*((t_ui8 *)(&x))) & FTBFM1)
# define FTBF_GET_SGN_D(x) (FTBF_MASK_SGN_D(x) ? 1 : 0)
# define FTBF_GET_EXP_D(x) ((FTBF_MASK_EXP_D(x) >> FTBF_MBITS_D) - FTBF_BIAS_D)

# define FTBF_MASK_SGN_LD(x) (((short *)(&x))[4] & 0x8000)
# define FTBF_MASK_EXP_LD(x) (((short *)(&x))[4] & 0x7FFF)
# define FTBF_MASK_MTS_LD(x) (*((unsigned long *)(&x)))
# define FTBF_GET_SGN_LD(x) (FTBF_MASK_SGN_LD(x) ? 1 : 0)
# define FTBF_GET_EXP_LD(x) (FTBF_MASK_EXP_LD(x) - FTBF_BIAS_LD)

# define FTPF_DBL_SIGN  0x8000000000000000
# define FTPF_LDBL_INF  0x8000000000000000
# define FTPF_DBL_IS_NEG(x) (*((unsigned long *)(&x)) & FTPF_DBL_SIGN ? 1 : 0)
# define FTPF_LDBL_SIGN 0x80000000000000000000L
# define FTPF_LDBL_NEG(x) (*((size_t *)(&x)) & FTPF_LDBL_SIGN ? 1 : 0)

# define FTPF_LDBL_BYTE5(x) ((short *)(&x))[4]
# define FTPF_LDBL_MANTS(x) *((unsigned long *)(&x))


/* ----------------------------------------------------------------------------
** Definitions
** --------------------------------------------------------------------------*/

typedef struct s_unit_tester_args t_unit_tester_args;

typedef void (*t_unit_tester_func) (t_unit_tester_args *);

struct s_unit_tester_args
{
	char	*pattern;
	int		from;
	int		to;
	int		current;
	int		num_fails;
	int		num_run;
	t_unit_tester_func	run;
	int		fd_stdout_dup;
};

typedef struct s_retvals
{
	int		ret_val_libc;
	int		ret_val_mine;
	int		stat_loc;
} t_retvals;

typedef struct s_timeout_args
{
	pid_t		pid;
	int			signal;
	pthread_t	mainthread;
} t_timeout_args;

typedef struct s_retval_pipe_args
{
	int			fd;
	t_retvals	retvals;
} t_retval_pipe_args;

typedef	int					(* t_unit_test) (void);
typedef int					(*printf_func) (const char *, ...);

typedef int					(*t_run_test_func) (int);

typedef struct	s_test_entry
{
	int			enabled;
	int			number;
	const char	*name;
	t_unit_test	test;
	t_unit_test	bench;
	const char	*first_line;
}				t_test_entry;

/* ----------------------------------------------------------------------------
** Globals
** --------------------------------------------------------------------------*/

extern t_unit_tester_args  *failsafe_args_recover;

extern const t_test_entry	g_unit_tests[];

extern const char			*g_signal_strings[];

/* ----------------------------------------------------------------------------
** The Victim
** --------------------------------------------------------------------------*/

int							ft_printf(const char *, ...);

/* ----------------------------------------------------------------------------
** Interface Functions
** --------------------------------------------------------------------------*/

void						run_test_range(t_unit_tester_args *args);
void						run_search_tests(t_unit_tester_args *args);

void						print_help(int extended);

void						set_option_fork(void);
void						set_option_nofork(void);
void						set_option_usetimeout(void);
void						set_option_notimeout(void);

/* ----------------------------------------------------------------------------
** Helper Functions
** --------------------------------------------------------------------------*/

void		log_msg(const char *msg);
void		print_test_start(int test_number);
void		print_test_end(int failed, int stat_loc, int timed_out);
void		print_end_test_message(int num_tests, int num_passed);
int			ft_match_helper(const char *s1, char *s2);
int			ft_match(const char *s1, char *s2);
void 		convert_nonalphanum_to_wildcard(char *str);
void		ft_putnbr_fd(int nb, int fd);


/* ----------------------------------------------------------------------------
** Args Array from Libft
** --------------------------------------------------------------------------*/
typedef struct			s_argsarr
{
	char				**argv;
	int					argc;
}						t_argsarr;

/* ----------------------------------------------------------------------------
** Command Line Options from Libft
** --------------------------------------------------------------------------*/

# define FTOPT_MAX_OPTIONS 63

typedef struct			s_clopt
{
	char				selected[FTOPT_MAX_OPTIONS + 1];
	int					num_sel;
	char				*program_name;
	t_argsarr			args;
}						t_clopt;

t_clopt					ft_optget(int argc, char **argv);
int						ft_issel(t_clopt *opt, char c);

#endif
