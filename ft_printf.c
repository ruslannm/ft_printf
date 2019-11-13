/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2019/11/13 16:32:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

char	ft_flag(char **s)
{
	char	*flags;
	char	ret;

	ret = 0;
	flags = ft_strdup("#0- +'");
	if (ft_strchr(flags, *(*s)))
	{
		ret = *(*s);
		(*s)++;
	}
	free(flags);
	return (ret);
}

int		ft_width(char **s)
{
	int	ret;

   	ret = 0;
	if (ft_isdigit(*(*s)))
	{
		ret = ft_atoi(*s);
		if (ret > 0)
			while (ft_isdigit(*(*s)))
				(*s)++;
	}
	return (ret);
}

int		ft_precision(char **s)
{
	int	ret;

	ret = -1;
	if (*(*s) == '.' && ft_isdigit(*(*s + 1)))
	{
		(*s)++;
		ret = ft_atoi(*s);
		if (ret > 0)
			while (ft_isdigit(*(*s)))
				(*s)++;
	}
	return (ret);
}



char	ft_modifier(char **s)
{
	char	ret;

	ret = 0;
	if (*(*s) == 'h' && *(*(s + 1)) == 'h')
		ret =  'H';
	else if (*(*s) == 'l' && *(*s + 1) == 'l')
		ret = '1';
	else if (*(*s) == 'h' || *(*s) == 'l' || *(*s) == 'L')
		ret = *(*s);
	if (ret == 'H' || ret == '1')
		*s = *s + 2;
	else if (ret > 0)	
			(*s)++;
	return (ret);
}

char	ft_conversion(char **s)
{
	char	ret;
	char *conversion;

	ret = 0;
	conversion = ft_strdup("cspdiouxXf");
	if (ft_strchr(conversion, *(*s)))
	{
		ret = *(*s);
		(*s)++;
	}
	free(conversion);
	return (ret);
}

void	ft_factor(t_spec *spec)
{
	if (spec->conversion == 'c')
		spec->type = strdup("char");
	else if (spec->conversion == 's')
		spec->type = strdup("char*");
	else if (spec->conversion == 'i')
		spec->type = strdup("int");
}

t_spec *ft_specification(char **s)
{
	t_spec	*ret;

	if (!(ret = (t_spec *)malloc(sizeof(t_spec))))
		return (NULL);
	(*s)++;
	ret->flag = ft_flag(s);
	ret->width = ft_width(s);
	ret->precision = ft_precision(s);
	ret->modifier = ft_modifier(s);
	ret->conversion = ft_conversion(s);
	ft_factor(ret);
	return (ret);
}

void	ft_print_arg(va_list factor, t_spec *spec)
{
	int	i;

	if (!strcmp(spec->type, "int"))
	{
		i = va_arg(factor, int);
		ft_putnbr(i);
	}
}

void	ft_flags_int(va_list args, int *p)
{
	int output;

	output = va_arg(args, int);
	ft_putnbr(output);
	if (output == -2147483648)
		*p += 12;
	else 
	{
		if (output < 0)
		{
			*p = *p + 1;
			output = -1 * output;
		}
		while (output / 10 > 0)
		{
			output = output / 10;
			*p = *p + 1;
		}
	}
}

void	ft_parse(int *i, const char *str, va_list args, int *p)
{
	*i = *i + 1;
	str[*i] == 'i' ? ft_flags_int(args, p) : 0;
}

int ft_printf(const char *format, ...)
{
	int i;
	int ret;
	va_list args;

	ret = 0;
	va_start(args, format);
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			ft_parse(&i, format, args, &ret);			
		else
			write(1, &format[i], 1);
	}
	va_end(args);
	return (ret);
}