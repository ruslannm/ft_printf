/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_dif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:29 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 19:10:55 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbr_len(intmax_t n, int base)
{
	int i;

	i = 1;
	while (n / base > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

void	ft_get_str_di(intmax_t n, t_spec *s_args, char *str)
{
	int	i;

	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
	str[i] = '\0';
	if (s_args->precision_ini == 1)
		s_args->flags[1] = 0;
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
}

void	ft_get_str_binary(unsigned long int n, int power, char *str)
{
	int		j;
	char	c;

	j = 0;
	ft_memset(str, '0', 64);
	str[64] = '\0';
	while (n > 0)
	{
		str[j++] = n % 2 + '0';
		n = n / 2;
	}
	while (j-- > 32)
	{
		c = str[j];
		str[j] = str[63 - j];
		str[63 - j] = c;
	}
	ft_shift(str, power - 63);
}

void	ft_get_str_f(long double n, t_spec *s_args, char *str)
{
	union u_long_double	u_d;
	int					power;

	str[0] = '\0';
	u_d = (union u_long_double)n;
	if (u_d.f_parts.e == 0 && u_d.f_parts.m == 0)
	{
		ft_get_str_f_null(s_args, u_d.f_parts.s, str);
		return ;
	}
	power = u_d.f_parts.e - 16383;
	if (u_d.f_parts.s)
		s_args->sign = '-';
	if (power == 16384)
	{
		ft_get_str_f_naninf(s_args, u_d.f_parts.m, str);
		return ;
	}
	ft_get_str_binary(u_d.f_parts.m, power, str);
	ft_conv_bin_dec(s_args, str);
	ft_roundup(str, s_args);
}
