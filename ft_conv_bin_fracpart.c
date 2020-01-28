/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_fracpart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/28 15:30:42 by rgero            ###   ########.fr       */
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

int		ft_iseven(char c)
{
	if ('0' == c || '2' == c || '4' == c || '6' == c || '8' == c)
		return (1);
	else if ('1' == c || '3' == c || '5' == c || '7' == c || '9' == c)
		return (0);
	return (- 1);
}

char	ft_div_2_algo(char c0, char c)
{
	if (1 == ft_iseven(c0))
	{
		if ('0' == c || '1' == c)
			return ('0');
		else if ('2' == c || '3' == c)
			return ('1');
		else if ('4' == c || '5' == c)
			return ('2');
		else if ('6' == c || '7' == c)
			return ('3');
		return ('4');
	}
	else
	{
		if ('0' == c || '1' == c)
			return ('5');
		else if ('2' == c || '3' == c)
			return ('6');
		else if ('4' == c || '5' == c)
			return ('7');
		else if ('6' == c || '7' == c)
			return ('8');
		return ('9');
	}
}

int	ft_div_2_first_digit(char *str)
{
	int i;

	i = 2;
	while (str[i])
	{
		if (0 != str[i])
			return (i);
		i++;
	}
	return (i);
}

void ft_div_2_dec(char *str)
{
	int	len;
	int	len_new;
	char	ret[5000];
	int		i;
	int		start;

	len = ft_strlen(str);
	start = ft_div_2_first_digit(str);
	i = start;
	while (i < len)
	{
		if (start == i)
			ret[i - start] = ft_div_2_algo('0', str[i]);
		else
			ret[i - start] = ft_div_2_algo(str[i - 1], str[i]);
		i++;
	}
	if (0 == ft_iseven(str[len - 1]))
		ft_strcpy(&ret[i++ - start], "5");
	ret[i] = '\0';
	ft_strcpy(str, ret);
}

void	ft_conv_bin_dec_place(char *str)
{
	char	tmp[5000];
	char	power[5000];
	int		max_power;	
	int		i;

	ft_strcpy(tmp, "0.0");
	max_power = ft_max_power(str);
	i = 0;
	ft_strcpy(power, "1");
	while (i <= max_power)
	{
		ft_div_2_dec(power);
		if (str[i] == '1')
			ft_sum_decimal(ft_strchr(tmp, '.') + 1, ft_strchr(power, '.') + 1, 10, tmp);
		}
		i++;
	}
	ft_strcpy(str, tmp);
	i = ft_strlen(tmp);
	str[i] = '\0';
}
