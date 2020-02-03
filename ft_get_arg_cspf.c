/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_cspf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 20:54:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_arg_c_va_list(t_spec *s_args, va_list args)
{
	unsigned char	nb;
	char			str[2];

	nb = (unsigned char)va_arg(args, unsigned int);
	str[0] = nb;
	str[1] = '\0';
	s_args->print_char = nb;
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_s(t_spec *s_args, char *str)
{
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_s_va_list(t_spec *s_args, va_list args)
{
	char	*str;
	char	str_null[7];

	str = (char *)va_arg(args, char*);
	if (!str)
	{
		ft_strcpy(str_null, "(null)");
		ft_get_arg_s(s_args, str_null);
	}
	else
		ft_get_arg_s(s_args, str);
}

void	ft_get_arg_p(t_spec *s_args, va_list args)
{
	char	*s;
	char	str[500];

	s = (char *)va_arg(args, char*);
	ft_get_str_p(&s, str);
	if (!ft_strcmp("0", str))
	{
		if (!s_args->precision && s_args->precision_ini)
			str[0] = '\0';
	}
	else
	{
		if (s_args->precision_ini &&
			(int)ft_strlen(str) > s_args->precision)
			s_args->precision = ft_strlen(str);
	}
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_f(t_spec *s_args, va_list args)
{
	long double	nb;
	char		str[50000];

	if (!s_args->modifier)
		nb = (double)va_arg(args, double);
	else if ('l' == s_args->modifier)
		nb = (double)va_arg(args, double);
	else if ('L' == s_args->modifier)
		nb = (long double)va_arg(args, long double);
	else
		nb = (double)va_arg(args, double);
	ft_set_sign(s_args);
	ft_get_str_f(nb, s_args, str);
	ft_put_output_f(s_args, str, 0);
}
