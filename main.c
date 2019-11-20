/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2019/11/20 17:55:52 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i;

	printf("printf position %%1$i=%%i");
	i = ft_printf("int(i)=%1$#0i", 15);
/*
	printf("printf(int(i)=%%i,int(d)=%%d,char(c)=%%c', 15, 25);\nMy\n");
	i = ft_printf("int(i)=%i,int(d)=%d,char(c)=%c, str(c)=%s", 15, 25, 'a', "str");
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
	return (0);
}