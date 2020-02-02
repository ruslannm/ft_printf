/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_uoxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 19:13:09 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_udigit(uintmax_t n, int base)
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

void		ft_get_str_u(uintmax_t n, t_spec *s_args, char *str)
{
	int	i;

	i = ft_get_udigit(n, 10);
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

void		ft_get_str_o(uintmax_t n, t_spec *s_args, char *str)
{
	int i;
	int	base;

	base = (s_args->conversion == 'o' ? 8 : 16);
	i = ft_get_udigit(n, base);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
	if (s_args->flags[0] && (!i || n))
		i++;
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = n % base + '0';
		n = n / base;
	}
}

void		ft_get_str_x(uintmax_t n, t_spec *s_args, char *str)
{
	int i;
	int	base;

	base = (s_args->conversion == 'o' ? 8 : 16);
	i = ft_get_udigit(n, base);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
	str[i] = '\0';
	while (--i >= 0)
	{
		if (n % base < 10)
			str[i] = n % base + '0';
		else
			str[i] = n % base - 10 + (s_args->conversion == 'x' ? 'a' : 'A');
		n = n / base;
	}
}

void		ft_get_str_p(char **s, char *str)
{
	int		i;
	int		base;
	long	p;

	base = 16;
	p = (long)(*s);
	i = ft_get_udigit(p, base);
	str[i] = '\0';
	while (--i >= 0)
	{
		if (p % base < 10)
			str[i] = p % base + '0';
		else
			str[i] = p % base - 10 + 'a';
		p = p / base;
	}
}
