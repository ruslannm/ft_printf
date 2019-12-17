/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/17 17:44:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

static int	ft_get_digit(char *s, int s_len, int i)
{
	if (i > s_len)
		return (0);
	else
		return (s[s_len - i] - '0');
}

int	ft_sum(char *s, char *s1, char *s2, int base)
{
	int 	carry;
	int		s_len[3];
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (-1);
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) / base;
		i++;
	}
	if (carry)
		s[s_len[0] - i] = '1';
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		s[s_len[0] - 1] = '\0';
	}
	return (0);
}

int	ft_binary_pow(int power, char *s)
{
	int	i;

	char	*tmp;
	char	*n_str;

	if (!(s = ft_strnew(power + 1)))
		return (-1);
	s[0] = '1';
	i = 0;
	while (++i <= power)
		s[i] = '0';
	return (0);
}


int	ft_div(char *s, char *s1, char *s2, int precision)
{
	int 	carry;
	int		s_len[3];
	int		i;

	s_len[1] = ft_strlen(s1);  //делимое
	s_len[2] = ft_strlen(s2);  //делитель
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	
	while (s1 < s2)
	{
		s = 
	}
	
	10010001111010111000011
	12345678901234567890123
	
	
	carry = 0;
	if (!(s = ft_strnew(precision + 1)))
		return (-1);
	i = 1;
	if (s_len[2] > s_len[1])

	
	
	while (i <= s_len[1] || i <= s_len[2])	
	{
		s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) / base;
		i++;
	}
	if (carry)
		s[s_len[0] - i] = '1';
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		s[s_len[0] - 1] = '\0';
	}
	return (0);
}
