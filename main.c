/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2020/01/11 16:12:51 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
//#include <limits.h>

int main(void)
{
	int i;
	//struct lconv *lc;
	setlocale(LC_NUMERIC, "en_US"); //for check '
	//lc = localeconv();
	//lc->thousands_sep = "f[";//lc->thousands_sep;
	
//	printf("printf position %%1$i=%%i");
/*
	trace.txt
	KO
	line 4580
*/

//	i = ft_printf("%#1.o|%01.o", 0U, 0U);
	i = ft_printf("%#.x|", 0U);

	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);

	i = printf("%#.x|", 0U);
	printf("\nres=%i=li\n", i);

/*
	i = ft_printf("int(o)=%#-15.10o, int(o)=%#15.10o, int(x)=%#15.10x=my", 55555, 77777, 77777);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);

	i = printf("int(o)=%#-15.10o, int(o)=%#15.10o, int(x)=%#15.10x=li", 55555, 77777, 77777);
	printf("\nres=%i=lib\n", i);

//
	char *s = "test";

	i = ft_printf("int(c)=%-15c, int(c)=%15c, char(s)=%-15s, char(p)=%-15p=my", 70, 70, "test", s);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);

	i = printf("int(c)=%-15c, int(c)=%15c, char(s)=%-15s, char(p)=%-15p=li", 70, 70, "test", s);
	printf("\nres=%i=lib\n", i);

*/
/*double d = 123.14f;

	i = ft_printf("f(f)=%f=my", d);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);

	i = printf("f(f)=%f=li", d);
	printf("\nres=%i=lib\n", i);
*/
/*	printf(", res=%i\nlib:\n", i);
	i = printf("int(i)=%i,int(d)=%d,char(c)=%c, str(c)=%s", 15, 25, 'a', "str");
	printf(", res=%i\nlib:\n", i);
	printf("\n");
	printf ("\n5. Вывод строки 'abc':\n");
 { char d1[4]="abc";
   printf ("%s\n",d1);
 }
 printf ("\n6. Вывод указателя:\n");
 { char d1[4]="abc";
   printf ("%p\n",d1);
 }

// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");
*/

	//setlocale (LC_ALL,"");
	return (0);
}