/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2019/11/10 13:20:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

char	ft_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '`')
		return (c);
	return (0);
}

int		ft_width(char **s)
{
	int	ret;

	ret = ft_atoi(*s);
	if (ret > 0)
		while (*(*s) >= '0' && *(*s) <= '9')
			(*s)++;
	return (ret);
}

t_spec *ft_conversion(char *s)
{
	t_spec	*ret;

	if (!(ret = (t_spec *)malloc(sizeof(t_spec))))
		return (NULL);
	if ((ret->flag = ft_flag(*s)))
		s++;
	printf("ret->flad=%c\n", ret->flag);
	ret->width = ft_width(&s);
	printf("ret->width=%i\n", ret->width);
	printf("after ret->width=%s\n", s);
	return (ret);
}



int ft_printf(const char * restrict format, ...)
{
	char	*first_agr;
	int	i;
	va_list type;
	t_spec	*spec;

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
			if (*(++first_agr) == '%')
			{
				ft_putchar(*first_agr);
				++first_agr;
			}
			else
			{
				spec = ft_conversion(first_agr);
				i = va_arg(type, int);
				ft_putnbr(i);
				++first_agr;
			}
		}
	}
	va_end(type);
	return (0);
}