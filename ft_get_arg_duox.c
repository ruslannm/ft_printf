/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_duox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 15:55:34 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_sign(t_spec *s_args)
{
	if (s_args->sign != '-')
	{
		if (s_args->flags[4] == '+')
			s_args->sign = '+';
		else if (s_args->flags[3] == ' ')
			s_args->sign = ' ';
	}
}

void	ft_get_arg_d(t_spec *s_args, va_list args)
{
	intmax_t	nb;
	char		str[5000];

	if (!s_args->modifier)
		nb = (int)va_arg(args, int);
	else if ('h' == s_args->modifier)
		nb = (short)va_arg(args, int);
	else if ('1' == s_args->modifier)
		nb = (signed char)va_arg(args, int);
	else if ('l' == s_args->modifier)
		nb = (long)va_arg(args, long int);
	else if ('2' == s_args->modifier)
		nb = (long long)va_arg(args, long long int);
	else
		nb = (int)va_arg(args, int);
	s_args->sign = (nb < 0 ? '-' : 0);
	if (nb == -9223372036854775807 - 1)
		ft_get_u_str(9223372036854775808U, s_args, str);
	else
		ft_get_di_str(nb, s_args, str);
	ft_set_sign(s_args);
	ft_get_len_output(s_args, str);
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_u(t_spec *s_args, va_list args)
{
	uintmax_t	nb;
	char		str[5000];

	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if ('h' == s_args->modifier)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if ('1' == s_args->modifier)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if ('l' == s_args->modifier)
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if ('2' == s_args->modifier)
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	ft_get_u_str(nb, s_args, str);
	ft_get_len_output(s_args, str);
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_ox(t_spec *s_args, va_list args)
{
	uintmax_t	nb;
	char		str[5000];

	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if ('h' == s_args->modifier)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if ('1' == s_args->modifier)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if ('l' == s_args->modifier)
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if ('2' == s_args->modifier)
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	if (s_args->conversion == 'o')
		ft_get_o_str(nb, s_args, str);
	else
		ft_get_x_str(nb, s_args, str);
	ft_get_len_output(s_args, str);
	ft_put_output(s_args, str, 0);
}
