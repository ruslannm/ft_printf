/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2019/11/07 18:22:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_printf(const char * restrict format, ...)
{
	char	*first_agr;
	int	i;
	va_list type;

	first_agr = (char *)format;
	va_start(type, format);
	while (*first_agr)
	{
		if (*first_agr != '%')
		{
			ft_putchar(*first_agr);
			++first_agr;
		}
		else
		{
			if (*(++first_agr) == 'i')
			{
				i = va_arg(type, int);
				ft_putnbr(i);
				++first_agr;
			}
		}
	}
	va_end(type);
	return (0);
}