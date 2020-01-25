/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/25 14:19:22 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int	ft_strcmp_nb(const char *s1, const char *s2)
{
	int	s_len[3];

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	if (s_len[1] > s_len[2])
		return (1);
	else if (s_len[1] < s_len[2])
		return (-1);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

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
/*
char	*ft_sum(char *s1, char *s2, int base)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*s;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) / base;
		i++;
	}
	if (carry)
		s[s_len[0] - i] = carry + '0';
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		s[s_len[0] - 1] = '\0';
	}
	return (s);
}
*/

char	*ft_sum_int(char *s1, char *s2, int base)
{
	int 	carry;
	int		*len[3];
	int		i;
	char	*s;
	int		s_len;

	len[1] = ft_float_len(s1);
	len[2] = ft_float_len(s2);
	s_len = 1 + (len[1][1] > len[2][1] ? len[1][1] : len[2][1]);
	carry = 0;
	if (!(s = ft_strnew(s_len + 1)))
		return (NULL);
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
	free(len[1]);
	free(len[2]);
	return (s);
}

char	*ft_sum_decimal(char *s1, char *s2, int base)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*s;

//	s1 = ft_strchr(s1, '.') + 1;
//	s2 = ft_strchr(s2, '.') + 1;
	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 2 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		s[s_len[0] - i]  = (ft_get_digit(s1, s_len[0] - 2, i) + ft_get_digit(s2, s_len[0] - 2, i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[0] - 2, i) + ft_get_digit(s2, s_len[0] - 2, i) + carry) / base;
		i++;
	}
	s[1] = '.';
	s[0] = carry + '0';
	return (s);
}

char	*ft_sum_float(char *s1, char *s2, int base)
{
	int	*len[4];
	char	*s3;
	char	*s4;
	char	*s5;
	char	*ret;

	len[1] = ft_float_len(s1);
	len[2] = ft_float_len(s2);
	s3 = ft_sum_decimal(&s1[len[1][1] +1 ], &s2[len[2][1] + 1], base);
	s4 = ft_sum_int(s1, s2, base);
	s5 = ft_sum_int(s3, s4, base);
	len[3] = ft_float_len(s3);
	if (!(ret = ft_strjoin(s5, &s3[len[3][1]])))
		return (NULL);
	return (ret);
}

char	*ft_sub(char *s1, char *s2)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*s;
	int		nb[3];

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = s_len[1];
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	i = 1;
	while (i <= s_len[1])	
	{
		nb[1] = ft_get_digit(s1, s_len[1], i);
		nb[2] = ft_get_digit(s2, s_len[2], i);
		nb[0] = ((nb[1] - carry) < nb[2] ? 10 : 0);
		s[s_len[0] - i]  = (nb[0] + nb[1] - nb[2] - carry) % 10 + '0';
		carry = (nb[0] ? 1 : 0);
		i++;
	}
	i = 0;
	while (s[i] == '0' && i < s_len[0] - 1)
		i++;
	if (i)
	{
		ft_memmove(s, s + i, s_len[0] - i);
		s[s_len[0] - i] = '\0';
	}
	return (s);
}




char	*ft_mul(char *s1, int y)
{
	char	*s;
	int		s_len[2];
	int		carry;
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[0] = 1 + s_len[1];
	s = ft_strnew(s_len[0] + 1);
	if (!y)
		s[0] = '0';
	else if	(y == 10)
	{
		s = ft_strcpy(s, s1);
		s[s_len[0] - 1] = '0';
	}
	else
	{
		carry = 0;
		i = 1;
		while (i < s_len[0])	
		{
			s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) * y + carry) % 10 + '0';
			carry = (ft_get_digit(s1, s_len[1], i) * y + carry) / 10;
			i++;
		}
		if (carry)
			s[s_len[0] - i] = carry + '0';
		else
		{
			ft_memmove(s, s + 1, s_len[0] - 1);
			s[s_len[0] - 1] = '\0';
		}
	}
	return (s);
}

int 	ft_div_int(char *s1, char *s2)
{
	int		ret;
	char	*s;
	
	ret = 1;
	while (ret <= 10)
	{
		s = ft_mul(s2, ret);
		if (ft_strcmp_nb(s, s1) > 0)
		{
			ret = ret - 1;
			free(s);
			break;
		}
		else if (ft_strcmp_nb(s, s1) == 0)
		{
			free(s);
			break;
		}
		ret++;
		free(s);
	}
	return (ret);
}


char *ft_div(char *s1, char *s2, int digit)
{
	char *ret;
	int i;
	int d;
//	char *x_str;
//	char *y_str;
	char	*tmp;
//	char	*tmp2;

	if (!(ret = ft_strnew(digit)))
		return (NULL);
	i = 0;
	d = 0;
	while (i < digit)
	{
		ret[i] = d + '0';
		tmp = ft_mul(s2, d);
		s1 = ft_sub(s1, tmp);
//		free (s1);
//		s1 = tmp2;
		if (!ft_strcmp(s1, "0"))
			break;
		s1 = ft_mul(s1, 10);
		d = ft_div_int(s1, s2);
		if (i == 0)
			ret[++i] = '.';
		i++;
	}
	return (ret);
}
/*
int	ft_nbr_len(intmax_t n, int base)
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
*/
char	*ft_put_i_str(int n)
{
	int 	i;
	char	*ret;

	i = ft_nbr_len(n, 10);
	if (!(ret = ft_strnew(i + 1)))
		return (NULL);
	ret[i] = '\0';
	while (--i >= 0)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}


int	ft_add_power(char **str, int base)
{
	char	*ret;

	ret = *str;
	if (!ret)
	{
		if (!(ret = ft_strnew(2)))
			return (-1);
		ret[0] = '1';
		*str = ret;
		return (0);
	}
	*str = ft_mul(ret, base);
	free (ret);
	return (0);
}


char	*ft_pow(int base, int power)
{
	char	*ret;
	char	*tmp;

	if (power == 0)
	{
		if (!(ret = ft_strnew(2)))
			return (NULL);
		ret[0] = '1';
	}
	else
	{
		if (!(ret = ft_put_i_str(base)))
			return (NULL);
		while (--power)
		{
			tmp = ft_mul(ret, base);
			free(ret);
			ret = tmp;
		}
	}
	return (ret);
}

char	*ft_conv_bin_int(char *binary)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;
	int		max_power;	
	int		i;

	ret = ft_strdup("0");
	max_power = ft_strlen(binary) - 1;
	i = max_power;
	tmp2 = NULL;
	while (i >= 0)
	{
		ft_add_power(&tmp2, 2);
		if (binary[i] == '1')
		{
//			tmp2 = ft_pow(2, max_power - i);
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

char	*ft_conv_bin_dec_place(char *binary)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;
	char	*s_power;
	int		max_power;	
	int		i;

	ret = ft_strdup("0.0");
	max_power = ft_strlen(binary);
	i = 1;
	s_power = ft_strdup("1");
	while (i <= max_power)
	{
		ft_add_power(&s_power, 2);
		if (binary[i - 1] == '1')
		{
			//tmp = ft_pow(2, i);
			tmp2 = ft_div("1", s_power, max_power + 1);
//			free(tmp);
			tmp = ft_sum_decimal(ft_strchr(ret, '.') + 1, ft_strchr(tmp2, '.') + 1, 10);
//			free(tmp2);
			free(ret);
			ret = tmp;
		}
		i++;
	}
	return (ret);
}

int	ft_conv_bin2dec(char **str)
{
	char	*tmp;
	char	*ret;
	char	*pointer;
	char	*int_part;
	char	*dec_part;

	tmp = *str;
	ret = ft_strdup(tmp);
	pointer = ft_strchr(ret, '.');
	dec_part = ft_conv_bin_dec_place(pointer + 1);
	*pointer = '\0';
	int_part = ft_conv_bin_int(ret);
	free(ret);
	ret = ft_strjoin(int_part, dec_part + 1);
	*str = ret;
	return (0);
}
/*
int main()
{
	char *ret;
	char *tmp;
	
	//ret = NULL;
 	int i;

   i = ft_div_int("2320", "256");
   printf("i=%i\n", i);

	ret = ft_sum("99", "99", 10);
	printf("res_sum=%s=\n", ret);
	ret = ft_sum_decimal_place("0.625", "0.615", 10);
	printf("res_sum_decimal_place=%s=\n", ret);
	
	ret = ft_mul("16", 7);
	printf("res_mul=%s=\n", ret);
	free(ret);
	tmp = ft_strdup("1");
    ret = ft_sub(tmp, "1");
	printf("res_sub=%s=\n", ret);
	ret = ft_div("1", "9", 100);
	printf("res_div=%s=\n", ret);

	ret=ft_pow(2, 16);
	printf("res_pow=%s=\n", ret);

	ret = ft_conv_bin_int("1000");
	printf("res_bin_to_int=%s=\n", ret);

	ret = ft_conv_bin_dec_place("101");
	printf("res_bin_to_dec_place=%s=\n", ret);

	ret = ft_conv_binary("1000.101");
	printf("res_bin_to_int=%s=\n", ret);

	return (0);
}
*/