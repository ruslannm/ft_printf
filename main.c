/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 16:41:04 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <math.h>
#include <float.h>

int main(void)
{
	int i;
	//struct lconv *lc;
	setlocale(LC_NUMERIC, "en_US"); //for check '
	//lc = localeconv();
	//lc->thousands_sep = "f[";//lc->thousands_sep;
	
//	printf("printf position %%1$i=%%i");
char *s;
s = ft_strdup("123");
i = ft_printf("%d, %u, %o, %x, %X, %s, %p, %f", 50, 50, 50, 50, 50, s, s, 50.1);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);
	i = printf("%d, %u, %o, %x, %X, %s, %p, %f", 50, 50, 50, 50, 50, s, s, 50.1);
printf("\nres=%i=li\n", i);
	free(s);
	//setlocale (LC_ALL,"");
	return (0);
}