/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2019/11/12 18:45:26 by rgero            ###   ########.fr       */
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

int ft_printf(const char * restrict format, ...)
{
	char	*first_agr;
	char i;
	size_t size;
	va_list args;
	t_spec	*spec;

	size = sizeof(format);
	first_agr = (char *)format;
	va_start(args, format);
	//factor = factor + 8;
	while (*first_agr)
	{
		while (*first_agr != '%')
		{
			ft_putchar(*first_agr);
			first_agr++;
		}
		spec = ft_specification(&first_agr);
//		if (!strcmp(spec->factor, 'int')
//			//ft_print_arg(factor, spec);
		if (!strcmp(spec->type, "int"))
		{
//			first_agr++;
			i = va_arg(args, char);
			ft_putchar(i);
		}
		//first_agr++;
	}
	va_end(args);
	return (0);
}