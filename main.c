/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 20:08:10 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <fcntl.h>

int	main(void)
{
	int		i;
	char	*s;

	s = ft_strdup("123");
	i = ft_printf("{%.*d}", -5, 42);
	write(1, "\nres=", 5);
	ft_putnbr(i);
	write(1, "=my\n", 4);
	i = printf("{%.*d}", -5, 42);
	printf("\nres=%i=li\n", i);
	free(s);
	return (0);
}

/*
**	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
**	ft_printf_fd(fd, "%*.*d|", 10, 5, -5);
**	close(fd);
*/
