/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 19:19:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <fcntl.h>

int main(void)
{
	int i;
	char *s;
	int fd;

	s = ft_strdup("123");
	i = ft_printf("%*.*d|%c|", 10, 5, -5, 0);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);
	i = printf("%*.*d|%c|", 10, 5, -5, 0);
	printf("\nres=%i=li\n", i);
	free(s);
/*
** test fail desc
*/
	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	ft_printf_fd(fd, "%*.*d|", 10, 5, -5);
	close(fd);
	return (0);
}