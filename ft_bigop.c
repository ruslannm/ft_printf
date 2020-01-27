/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/27 18:40:33 by rgero            ###   ########.fr       */
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


void	ft_sum_int(char *s1, char *s2, int base, char *s)
{
	int 	carry;
	int		len[3][3];
	int		i;
	int		s_len;

	ft_float_len(s1, len[1]);
	ft_float_len(s2, len[2]);
	s_len = 1 + (len[1][1] > len[2][1] ? len[1][1] : len[2][1]);
	carry = 0;
	i = 1;
	while (i <= len[1][1] || i <= len[2][1])	
	{
		s[s_len - i]  = (ft_get_digit(s1, len[1][1], i) + ft_get_digit(s2, len[2][1], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, len[1][1], i) + ft_get_digit(s2, len[2][1], i) + carry) / base;
		i++;
	}
	if (carry)
		s[s_len - i] = carry + '0';
	else
	{
		ft_memmove(s, s + 1, s_len - 1);
		s[s_len - 1] = '\0';
	}
}

void	ft_sum_decimal(char *s1, char *s2, int base, char *s)
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

void	ft_sum_float(char *s1, char *s2, int base, char *s)
{
	int		len[6][4];
	char	s3[5000];
	char	s4[5000];
	char	s5[5000];

	ft_float_len(s1, len[1]);
	ft_float_len(s2, len[2]);
	ft_sum_decimal(&s1[len[1][1] +1 ], &s2[len[2][1] + 1], base, s3);
	ft_sum_int(s1, s2, base, s4);
	ft_sum_int(s3, s4, base, s5);
	ft_float_len(s5, len[5]);
	ft_float_len(s3, len[3]);
	ft_strcpy(s, s5);
	ft_strcpy(s + len[5][1], s3 + len[3][1]);
}



void	ft_add_power(char *str, int base)
{
	char	ret[5000];

	if (!str)
	{
		str[0] = '1';
		str[1] = '\0';
	}
	else
	{
		str = ft_mul(ret, base);
	}
	
	free (ret);
	return (0);
}

void ft_binpow(char *a, int n)
{
	char ret[1000000];
	char tmp[1000000];

	ft_bzero(ret, 2);
	ft_strcpy(ret, "1");
	while (n > 0)
	{
		if (1 == n % 2)
		{
            longmulti(ret, a, tmp);
			ft_strcpy(ret, tmp); 
			ret[ft_strlen(tmp)] = '\0';
		}
        longmulti(a, a, tmp);
		ft_strcpy(a, tmp);
		a[ft_strlen(tmp)] = '\0';
		n = n / 2;
	}
	ft_strcpy(a, ret;
	a[ft_strlen(ret)] = '\0';
}

void	*ft_conv_bin_int(char *str)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;
	int		max_power;	
	int		i;

	ret = ft_strdup("0");
	max_power = ft_strlen(str) - 1;
	i = max_power;
	tmp2 = NULL;
	while (i >= 0)
	{
		if (tmp2)
			ft_add_power(&tmp2, 2);
		if (str[i] == '1')
		{
			if (!tmp2)	
			tmp2 = ft_binpow("2", max_power - i);
			tmp = ft_sum_int(ret, tmp2, 10);
//			free(tmp2);
			free(ret);
			ret = tmp;
		}
		i--;
	}
	free(tmp2);
	return (ret);
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

void	ft_conv_bin_dec_place(char *str, char *str)
{
	char	tmp[5000];
	char	power[5000];
	int		max_power;	
	int		i;

	ft_strcpy(str, "0.0");
	max_power = ft_max_power(str);
	i = 0;
	ft_strcpy(power, "1");
	while (i <= max_power)
	{
		ft_div_2_dec(power);
		if (str[i] == '1')
		{
	ret[len_new] = '\0';


			tmp = ft_sum_decimal(ft_strchr(ret, '.') + 1, ft_strchr(s_power, '.') + 1, 10);
		}
		i++;
	}
	return (ret);
}

void	ft_conv_bin2dec(char *str)
{
	char	int_part[5000];
	char	dec_part[5000];
	int	len[4];

	ft_float_len(str, len);
	ft_conv_bin_dec_place(str + len[1] + 1, dec_part);
	str[len[1] + len[2]] = '\0';
	ft_conv_bin_int(str, int_part);
	ft_strcpy(str, int_part);
	ft_strcpy(str + ft_strlen(int_part), dec_part);
}
