/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_fracpart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/28 16:24:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

static int	ft_get_digit(char *s, int s_len, int i)
{
	int	len_str;

	len_str = (int)ft_strlen(s);
	if (i > s_len) 
		return (0);
	else if (s_len >= len_str + i)
		return (0);
	else
		return (s[s_len - i] - '0');
}


void	ft_sum_fracpart(char *s1, char *s2, int base, char *s)
{
	int 	carry;
	int		s_len[3];
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 2 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		s[s_len[0] - i]  = (ft_get_digit(s1, s_len[0] - 2, i) + ft_get_digit(s2, s_len[0] - 2, i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[0] - 2, i) + ft_get_digit(s2, s_len[0] - 2, i) + carry) / base;
		i++;
	}
	s[1] = '.';
	s[0] = carry + '0';
}

int	ft_max_power(char *str)
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

void	ft_conv_bin_dec_place(char *str)
{
	char	tmp[5000];
	char	power[5000];
	int		max_power;	
	int		i;
	int 	start;

	ft_strcpy(tmp, "0.0");
	start = ft_strchr(str, '.') - str + 1;
	max_power = ft_max_power(str);
	i = start;
	while (i <= max_power)
	{
		if (i == start)
			ft_strcpy(power, "0.5");
		else
			ft_div_by2_frac(power);
		if (str[i] == '1')
			ft_sum_fracpart(ft_strchr(tmp, '.') + 1, ft_strchr(power, '.') + 1, 10, tmp);
		i++;
	}
	ft_strcpy(str, tmp);
}
