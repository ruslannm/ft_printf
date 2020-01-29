/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_intpart.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/29 14:53:40 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

void	ft_float_len(const char *str, int *len)
{
	char	*point;

	len[0] = ft_strlen(str);
	if (!(point = ft_strchr(str, '.')))
	{
		len[1] = len[0];
		len[2] = 0;
		len[3] = 0;
	}
	else
	{
		len[1] = point - str;
		len[2] = 1;
 		len[3] = len[0] - len[1] - len[2];
	}
	len[4] = 0;
}


void	ft_sum_int(const char *s1, const char *s2, int base, char *s)
{
	int 	carry;
	int		l[3];
	int		i;
	int 	j[3];

	l[1] = ft_strlen(s1);
	l[2] = ft_strlen(s2);
	l[0] = 1 + (l[1] > l[2] ? l[1] : l[2]);
	carry = 0;
	i = 1;
	while (i <= l[1] || i <= l[2])	
	{
		j[1] = (l[0] - l[1] < i ? 0 : s1[l[1] - i] - '0');
		j[2] = (l[0] - l[2] < i ? 0 : s2[l[2] - i] - '0');

		s[l[0] - i]  = (j[1] + j[2] + carry) % base + '0';
		carry = (j[1] + j[2] + carry) / base;
		i++;
	}
	if (carry)
		s[l[0] - i] = carry + '0';
	else
	{
		ft_memmove(s, s + 1, l[0] - 1);
		s[l[0] - 1] = '\0';
	}
}

void	ft_mul_by2(char *str)
{
	char	tmp[5000];

	if (!str)
	{
		str[0] = '1';
		str[1] = '\0';
	}
	else
	{
		longmulti(str, "2", tmp);
		ft_strcpy(str, tmp);
	}
}

void ft_binpow(char *a, int n)
{
	char ret[5000];
	char tmp[5000];

	if (0 == n)
	{
		ft_strcpy(a, "1");
		return ;
	}
	if (a[0] == '\0')
		ft_strcpy(a, "2");
	ft_strcpy(ret, "1");
	while (n > 0)
	{
		if (1 == n % 2)
		{
            longmulti(ret, a, tmp);
			ft_strcpy(ret, tmp); 
		}
        longmulti(a, a, tmp);
		ft_strcpy(a, tmp);
		n = n / 2;
	}
	ft_strcpy(a, ret);
}

void	ft_conv_bin_intpart(const char *str, char *intpart)
{
	char	power[5000];
	int		max_power;	
	int		i;
	int		l[3];

	ft_float_len(str, l);
	ft_strcpy(intpart, "0");
	max_power = l[1] - 1;
	i = max_power;
	power[0] = '\0';
	while (i >= 0)
	{
		if (power[0] != '\0')
			ft_mul_by2(power);
		if (str[i] == '1')
		{
			if (power[0] == '\0')	
				ft_binpow(power, max_power - i);
			ft_sum_int(intpart, power, 10, intpart);
		}
		i--;
	}
}

/*
void	ft_conv_bin2dec(char *str)
{
	char	int_part[5000];
	char	dec_part[5000];
	int	len[4];

	ft_float_len(str, len);
	ft_conv_bin_fracpart(str, dec_part);
	str[len[1] + len[2]] = '\0';
	ft_conv_bin_intpart(str, int_part);
	ft_strcpy(str, int_part);
	ft_strcpy(str + ft_strlen(int_part), dec_part);
}
*/