/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:59:01 by rgero             #+#    #+#             */
/*   Updated: 2020/02/04 16:45:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mul_long_frac(const char *s1, const char *s2, char *s)
{
	int		l[3][4];
	char	tmp[50000];
	char	s1_tmp[50000];
	char	s2_tmp[50000];

	if (!ft_strcmp("0", s1))
	{
		ft_strcpy(s, s2);
		return ;
	}
	ft_float_len(s1, l[1]);
	ft_float_len(s2, l[2]);
	ft_strcpy(s1_tmp, s1 + 2);
	ft_strcpy(s2_tmp, s2 + 2);
	ft_mul_long(s1_tmp, s2_tmp, tmp);
	ft_shift(tmp, -l[1][3] - l[2][3]);
	ft_strcpy(s, tmp);
}

void	ft_fast_two(int power, char *str)
{
	if (1 == power)
		ft_strcpy(str, "0.5");
	else if (2 == power)
		ft_strcpy(str, "0.25");
	else if (3 == power)
		ft_strcpy(str, "0.125");
	else if (4 == power)
		ft_strcpy(str, "0.0625");
	else if (5 == power)
		ft_strcpy(str, "0.03125");
	else if (6 == power)
		ft_strcpy(str, "0.015625");
	else if (7 == power)
		ft_strcpy(str, "0.0078125");
	else if (8 == power)
		ft_strcpy(str, "0.00390625");
	else if (9 == power)
		ft_strcpy(str, "0.001953125");
}

void	ft_big_div(int power, char *ret)
{
	int		ratio;
	char	s1[50000];
	char	s2[50000];
	char	tmp[50000];

	ratio = 10;
	ft_strcpy(s1, "0");
	ft_strcpy(s2, "0.0009765625");
	while (power)
	{
		if (power >= 10)
		{
			ft_mul_long_frac(s1, s2, tmp);
			ft_strcpy(s1, tmp);
			power = power - 10;
		}
		else
		{
			ft_fast_two(power, s2);
			ft_mul_long_frac(s1, s2, tmp);
			ft_strcpy(s1, tmp);
			power = 0;
		}
	}
	ft_strcpy(ret, s1);
}
