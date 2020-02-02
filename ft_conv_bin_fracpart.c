/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_fracpart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 19:09:13 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sum_fracpart(const char *s1, const char *s2, int base, char *s)
{
	int	carry;
	int	l[3][5];
	int	i;
	int	j[3];

	ft_float_len(s1, l[1]);
	ft_float_len(s2, l[2]);
	l[0][0] = 2 + (l[1][3] > l[2][3] ? l[1][3] : l[2][3]);
	carry = 0;
	i = 1;
	while (i <= l[0][0] - 2)
	{
		j[1] = (l[0][0] - 2 - l[1][3] >= i ? 0 :
				s1[l[0][0] + l[1][1] - 1 - i] - '0');
		j[2] = (l[0][0] - 2 - l[2][3] >= i ? 0 :
				s2[l[0][0] + l[2][1] - 1 - i] - '0');
		s[l[0][0] - i] = (j[1] + j[2] + carry) % base + '0';
		carry = (j[1] + j[2] + carry) / base;
		i++;
	}
	s[1] = '.';
	s[0] = carry + '0';
	s[l[0][0]] = '\0';
}

int		ft_max_power(const char *str)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if ('0' != str[i])
			ret = i;
		i++;
	}
	return (ret);
}

int		ft_strncmp_frac(const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		if (s2[i] != '\0')
		{
			if (!(s2[i] == '.' || s2[i] == '0'))
				return (-1);
		}
		i++;
	}
	return (1);
}

void	ft_conv_bin_fracpart(t_spec *s_args, const char *str, char *fracpart)
{
	char	power[50000];
	int		l[6];

	ft_strcpy(fracpart, "0.0");
	ft_float_len(str, l);
	l[4] = ft_max_power(str);
	l[3] = l[1];
	while (l[3]++ <= l[4])
	{
		if (l[3] == l[1] + l[2])
		{
			ft_strcpy(power, "0.5");
			if (str[l[3]] == '1')
				ft_strcpy(fracpart, "0.5");
		}
		else
		{
			ft_div_by2_frac(power);
			if (str[l[3]] == '1')
				ft_sum_fracpart(fracpart, power, 10, fracpart);
		}
		if (l[4] > 100 && ft_strncmp_frac(power, s_args->precision + 15) > 0)
			l[3] = l[4] + 1;
	}
}
