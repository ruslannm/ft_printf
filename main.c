/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2019/11/29 17:45:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i;

//	printf("printf position %%1$i=%%i");
	i = ft_printf("int(i)=%-10.7i, int(i)=%10.7i=my", 55555, 77777);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);
//
	i = printf("int(i)=%-10.7i, int(i)=%10.7i=lib", 55555, 77777);
	printf("res=%i=lib\n", i);
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
	return (0);
}