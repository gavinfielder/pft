/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/24 15:55:09 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DBL_MANTISSA 0x000FFFFFFFFFFFFFlu
#define DBL_EXPONENT 0x7FF0000000000000lu
#define DBL_SIGNBIT  0x8000000000000000lu
#define DBL_IMPLCT_1 0x0010000000000000lu


void		print_bits(unsigned long *p, unsigned long start,
				unsigned long stop, int dot);
double		make_dbl(unsigned long mantissa, int exponent, int sign);
int			get_exp(double dbl);

void		float_freeform_test(int argc, char **argv)
{
	double dbl = 1.5;
	printf("Handling the double: %.18f\n", dbl);
	usleep(100000);
	ft_printf("Output: \"%f\"\n", dbl);

	(void)argc;
	(void)argv;
}

void 		freeform_test(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	ft_printf("%%d \t == |%d|\n", '\t');
	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
}

void	unit_testing(int argc, char **argv)
{
	int from, to;
	if (argc > 1)
	{
		if ((argv[1][0] >= 'a' && argv[1][0] <= 'z') || (argv[1][0] >= 'A' && argv[1][0] <= 'Z'))
		{
			run_search_tests(argv[1]);
		}
		else
		{
			from = atoi(argv[1]);
			if (argc > 2)
				to = atoi(argv[2]);
			else
				to = -1;
			run_test_range(from, to);
		}
	}
	else
	{
		run_all_tests();
	}
}

int main(int argc, char **argv)
{
	unit_testing(argc, argv);
	//float_freeform_test(argc, argv);
	//freeform_test(argc, argv);
	return (0);
}




/*
const static unsigned long	prec_upper_limits[20] =
{
	0u,
	9u,
	99u,
	999u,
	9999u,
	99999u,
	999999u,
	9999999u,
	99999999u,
	999999999u,
	9999999999u,
	99999999999u,
	999999999999u,
	9999999999999u,
	99999999999999u,
	999999999999999u,
	9999999999999999u,
	99999999999999999u,
	999999999999999999u,
	9999999999999999999u
};
*/


void		print_bits(unsigned long *p, unsigned long start, unsigned long stop, int dot)
{
	unsigned long mask;

	mask = 1lu << (unsigned long)(stop);
	for (unsigned long i = start; i <= stop; i++)
	{
		if ((*p) & mask)
			printf("1");
		else
			printf("0");
		if (dot && (i + 1) % 4 == 0)
			printf(".");
		mask >>= 1;
	}
}

double	make_dbl(unsigned long mantissa, int exponent, int sign)
{
	unsigned long	dbl;
	unsigned long	exp;

	dbl = mantissa;
	exp = ((unsigned long)(exponent + 1023));
	dbl |= (exp << 52);
	if (sign)
		dbl |= (1lu << 63);
	return (*((double *)(&dbl)));
}

int		get_exp(double dbl)
{
	unsigned long	exp;

	exp = (*((unsigned long *)(&dbl))) & DBL_EXPONENT;
	return ((exp >> 52) - 1023);
}
