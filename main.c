/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 12:28:08 by rgero            ###   ########.fr       */
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
i = ft_printf("%Z");
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);
	i = printf("%Z");
	printf("\nres=%i=li\n", i);
	
	//setlocale (LC_ALL,"");
	return (0);
}