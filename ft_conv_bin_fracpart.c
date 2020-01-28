/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_fracpart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/28 19:13:53 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

void	ft_sum_fracpart(char *s1, char *s2, int base, char *s)
{
	int 	carry;
	int		l[3];
	int		i;
	int		j[3];

	l[1] = ft_strlen(s1);
	l[2] = ft_strlen(s2);
	l[0] = 2 + (l[1] > l[2] ? l[1] : l[2]);
	carry = 0;
	i = 1;
	while (i <= l[1] || i <= l[2])	
	{
		j[1] = (l[0] - 2 - l[1] >= i ? 0 : s1[l[0] - 2 - i] - '0');
		j[2] = (l[0] - 2 - l[2] >= i ? 0 : s2[l[0] - 2 - i] - '0');
		s[l[0] - i]  = (j[1] + j[2] + carry) % base + '0';
		carry = (j[1] + j[2] + carry) / base;
		i++;
	}
	s[1] = '.';
	s[0] = carry + '0';
	s[l[0]] = '\0';
}

int	ft_max_power(const char *str)
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

void	ft_conv_bin_fracpart(const char *str, char *fracpart)
{
	char	power[5000];
	int		max_power;	
	int		i;
	int 	start;

	ft_strcpy(fracpart, "0.0");
	start = ft_strchr(str, '.') - str + 1;
	max_power = ft_max_power(str);
	i = start;
	while (i <= max_power)
	{
		if (i == start)
		{
			ft_strcpy(power, "0.5");
			ft_strcpy(fracpart, "0.5");
		}
		else
		{
			ft_div_by2_frac(power);
			if (str[i] == '1')
				ft_sum_fracpart(ft_strchr(fracpart, '.') + 1, ft_strchr(power, '.') + 1, 10, fracpart);
		}
		i++;
	}
}
