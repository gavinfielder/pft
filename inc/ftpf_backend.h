/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_backend.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:54:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 23:35:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_BACKEND_H
# define FTPF_BACKEND_H

# include "libft.h"
# include <stdarg.h>

/*
** -----------------------------------------------------------------------------
**                               Library Constants
** -----------------------------------------------------------------------------
*/

/*
** The size_mod constants are used to index into arrays; do not change
*/
# define FTPF_SIZEMOD_HH   1
# define FTPF_SIZEMOD_H    2
# define FTPF_SIZEMOD_L    3
# define FTPF_SIZEMOD_LL   4
# define FTPF_SIZEMOD_BIGL 5
# define FTPF_SIZEMOD_B    6

# define FTPF_NUM_CHECKFLAGS 28
# define FTPF_CHECKFLAG_INIT 0x0FFFFE7F
# define FTPF_CHECKER_BEGIN 0
# define FTPF_CHECKER_END (FTPF_NUM_CHECKFLAGS - 1)

# define FTPF_UNLIMITED_LEN -1

# define FTPF_ERROR -1

/*
** -----------------------------------------------------------------------------
**                              From FTBF library
** -----------------------------------------------------------------------------
*/

typedef unsigned int	t_ui4;
typedef unsigned long	t_ui8;

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

/*
** -----------------------------------------------------------------------------
**                              Check Flags
** -----------------------------------------------------------------------------
*/

/*
** -----------------------------------------------------------------------------
**                        CHECK_FLAGS
** -----------------------------------------------------------------------------
**  bit        description                  masks      mask description
** -----------------------------------------------------------------------------
**   0   %%  : print a %                    0000.0000  (disallows all)
** -----------------------------------------------------------------------------
**   1   ##$ : choose argument number       FFFF.FFFC  (disallows self & prior)
** -----------------------------------------------------------------------------
**   2   0   : zero padding                 FFFF.FFFD  (prior groups exc. %)
**   3   ' ' : space before positive        FFFF.FFFC  (disallows prior groups)
**   4   #   : alternate format display     FFFF.FFFC  (disallows prior groups)
**   5   -   : left justify                 FFFF.FFFD  (prior groups exc. %)
**   6   +   : always put a sign            FFFF.FFFC  (disallows prior groups)
** -----------------------------------------------------------------------------
**   7       : UNUSED
**   8       : UNUSED
** -----------------------------------------------------------------------------
**   9   ##  : field width                  FFFF.FD81  (self & prior exc. pct)
** -----------------------------------------------------------------------------
**   10   .  : precision                    FFFF.F980  (disallows self & prior)
** -----------------------------------------------------------------------------
**   11  hh  : short short size modifier    FFFF.0000  (prior & same group)
**   12  h   : short size modifer           FFFF.0000  (prior & same group)
**   13  ll  : long long size modifier      FFFF.0000  (prior & same group)
**   14  l   : long size modifier           FFFF.0000  (prior & same group)
**   15  L   : long double size modifier    FFFF.0000  (prior & same group)
** -----------------------------------------------------------------------------
**   16  p   : ptr expansion                0000.0000  (disallows all)
**   17  di  : signed integer expansion     0000.0000  (disallows all)
**   18  b   : binary expansion             0000.0000  (disallows all)
**   19  u   : unsigned integer expansion   0000.0000  (disallows all)
**   20  x   : hex expansion lower          0000.0000  (disallows all)
**   21  X   : hex expansion upper          0000.0000  (disallows all)
**   22  f   : float expansion              0000.0000  (disallows all)
**   23  s   : string expansion             0000.0000  (disallows all)
**   24  c   : char expansion               0000.0000  (disallows all)
**   25  o   : octal expansion              0000.0000  (disallows all)
**   26  m   : memory expansion             0000.0000  (disallows all)
**   27  {   : extension                    0000.0000  (disallows all)
** -----------------------------------------------------------------------------
**   26 - 31   UNUSED
** -----------------------------------------------------------------------------
*/

typedef long long						t_ftint8;
typedef int								t_ftint4;
typedef short							t_ftint2;
typedef char							t_ftint1;
typedef unsigned long long				t_ftuint8;
typedef unsigned int					t_ftuint4;
typedef unsigned short					t_ftuint2;
typedef unsigned char					t_ftuint1;

typedef struct s_ftpf_master_data		t_ftpf_master_data;
typedef struct s_ftpf_expandler			t_ftpf_expandler;
typedef	int		(*t_ftpf_expander_func)	(t_ftpf_master_data *);
typedef int		(*t_ftpf_checker_func)	(t_ftpf_expandler *);
typedef	t_ftint8	(*t_ftpf_sint_ga)	(t_ftpf_master_data *);
typedef	t_ftuint8	(*t_ftpf_uint_ga)	(t_ftpf_master_data *);
typedef char		*(*t_ftpf_fptstr)	(t_ftpf_master_data *);
typedef void	(*t_ftpf_getarg_func)	(void *, va_list *);

struct									s_ftpf_expandler
{
	const char							*start;
	unsigned int						check_flags;
	unsigned char						handled_len;
	unsigned char						total_specifier_len;
	unsigned char						zpad;
	unsigned char						space;
	unsigned char						altform;
	unsigned char						lfjusty;
	unsigned char						allsign;
	unsigned short						field_width;
	int									precision;
	unsigned char						size_mod;
	short								arg_num;
	t_ftpf_expander_func				expand;
};

struct									s_ftpf_master_data
{
	int									max_len;
	int									len;
	va_list								args;
	t_ftpf_expandler					*ex;
	t_multistringer						*ms;
	short								next_arg_num;
	t_hat								*arg_getters;
};

/*
** -----------------------------------------------------------------------------
**              Specific expansion helper functions and structures
** -----------------------------------------------------------------------------
*/

/*
** ------------ doubles --------------
*/

typedef struct							s_ftpf_flt_hlpr
{
	unsigned long						fpul;
	int									run_once;
	unsigned long						ip;
	double								actual;
	double								fp_actual;
}										t_ftpf_flt_hlpr;

t_ftpf_flt_hlpr							*ftpf_flt_hlpr_new(double actual);
unsigned long							ftpf_flt_get_ipart(double dbl);
double									ftpf_flt_get_fpart(double dbl);
void									ftpf_flt_get_fpul(
											t_ftpf_master_data *md,
											t_ftpf_flt_hlpr *h);
char									*ftpf_flt_check_special(double dbl);

/*
** ---------- long doubles -----------
*/

typedef struct							s_ftpf_fltl_hlpr
{
	unsigned long						fpul;
	int									run_once;
	unsigned long						ip;
	long double							actual;
	long double							fp_actual;
}										t_ftpf_fltl_hlpr;

t_ftpf_fltl_hlpr						*ftpf_fltl_hlpr_new(long double actual);
unsigned long							ftpf_fltl_get_ipart(long double dbl);
long double								ftpf_fltl_get_fpart(long double dbl);
void									ftpf_fltl_get_fpul(
											t_ftpf_master_data *md,
											t_ftpf_fltl_hlpr *h);
char									*ftpf_fltl_check_special
											(long double dbl);

/*
** ------------- binary --------------
*/

void									ftpf_sbwrite_bit(t_stringbuilder *sb,
											const void *loc, int i);

/*
** ------------- memory --------------
*/

void									ftpf_sbwrite_hexbyte
											(t_stringbuilder *sb,
											const void *loc);
void									ftpf_sbputchar_np
											(t_stringbuilder *sb,
											char c, char c_if_np);

/*
** ------------ shared ---------------
*/

void									ftpf_handle_padding_float
											(t_ftpf_master_data *md,
											char **str);
int										ftpf_flt_ul_len(unsigned long n);
char									*ftpf_flt_hlpr_get_str
											(t_ftpf_master_data *md,
											int neg, t_ftpf_flt_hlpr *h);
int										ftpf_guarantee_precision_memory
											(t_ftpf_master_data *md);
int										ftpf_expand_special_float
											(t_ftpf_master_data *md, char *str);
int										number_len(t_ftpf_expandler *ex);

/*
** -----------------------------------------------------------------------------
**                             Primary Functions
** -----------------------------------------------------------------------------
*/

void									ftpf_expandler_init
										(t_ftpf_expandler *ex,
										const char *start);

void									ftpf_read_specifier
										(t_ftpf_expandler *ex);

int										ftpf_master(t_multistringer *ms,
										const char *fmt, int max_len,
										va_list args);

t_ftpf_getarg_func						ftpf_get_which_getter(
											t_ftpf_expandler *ex);

/*
** -----------------------------------------------------------------------------
**                             Checker Functions
** -----------------------------------------------------------------------------
*/

extern const	t_ftpf_checker_func		g_checkfuncs[FTPF_NUM_CHECKFLAGS];

int										ftpf_check_percent
										(t_ftpf_expandler *expandler);
int										ftpf_get_arg_num
										(t_ftpf_expandler *expandler);
int										ftpf_check_zeropad_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_spacepad_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_alternate_form_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_negativepad_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_alwayssign_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_bignumber_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_leftjustify_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_fieldwidth_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_precision_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_shortshort_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_short_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_long_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_longlong_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_longdouble_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_ptr_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_signed_int_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_binary_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_unsigned_int_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_hexlower_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_hexupper_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_float_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_string_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_char_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_octal_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_memory_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_extension_expansion
										(t_ftpf_expandler *expandler);

/*
** -----------------------------------------------------------------------------
**                            Expander Functions
** -----------------------------------------------------------------------------
*/

int										ftpf_percent_expander(
											t_ftpf_master_data *md);
int										ftpf_ptr_expander(
											t_ftpf_master_data *md);
int										ftpf_signed_int_expander(
											t_ftpf_master_data *md);
int										ftpf_binary_expander(
											t_ftpf_master_data *md);
int										ftpf_unsigned_int_expander(
											t_ftpf_master_data *md);
int										ftpf_hexlower_expander(
											t_ftpf_master_data *md);
int										ftpf_hexupper_expander(
											t_ftpf_master_data *md);
int										ftpf_float_expander(
											t_ftpf_master_data *md);
int										ftpf_string_expander(
											t_ftpf_master_data *md);
int										ftpf_char_expander(
											t_ftpf_master_data *md);
int										ftpf_octal_expander(
											t_ftpf_master_data *md);
int										ftpf_memory_expander(
											t_ftpf_master_data *md);
int										ftpf_extension_expander(
											t_ftpf_master_data *md);

/*
** ----------- Delegate expanders -----------
*/

int										ftpf_bigint_expander(
											t_ftpf_master_data *md);
int										ftpf_bigfloat_expander(
											t_ftpf_master_data *md);
int										ftpf_floatl_expander(
											t_ftpf_master_data *md);

/*
** -----------------------------------------------------------------------------
**                          Argument Getter Functions
** -----------------------------------------------------------------------------
*/

int										ftpf_getarg(t_ftpf_master_data *md,
											void *dst);

void									ftpf_getarg_null(
											void *dst, va_list *args);
void									ftpf_getarg_uint4(
											void *dst, va_list *args);
void									ftpf_getarg_uint8(
											void *dst, va_list *args);
void									ftpf_getarg_sint4(
											void *dst, va_list *args);
void									ftpf_getarg_sint8(
											void *dst, va_list *args);
void									ftpf_getarg_ptr(
											void *dst, va_list *args);
void									ftpf_getarg_float(
											void *dst, va_list *args);
void									ftpf_getarg_floatl(
											void *dst, va_list *args);

#endif
