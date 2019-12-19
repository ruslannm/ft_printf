/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/19 15:39:30 by rgero            ###   ########.fr       */
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

int	ft_sum(char **s, char *s1, char *s2, int base)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*tmp;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(tmp = ft_strnew(s_len[0] + 1)))
		return (-1);
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		tmp[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) / base;
		i++;
	}
	if (carry)
		tmp[s_len[0] - i] = '1';
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		tmp[s_len[0] - 1] = '\0';
	}
	*s = tmp;
	return (0);
}

char *ft_sub(char *x_str, char *y_str)
{
	char *x;
	char *y;
	char *ret;

	x = x_str;
	y = y_str;
	ret = ft_strnew(10);
	return (ret);
}

int ft_mul(char **s, char *s1, int y)
{
	char	*tmp;
	int		s_len[2];
	int		carry;
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[0] = 1 + s_len[1];
	tmp = ft_strnew(s_len[0] + 1);
	if (y == 10)
	{
		tmp = ft_strcpy(tmp, s1);
		tmp[s_len[0] - 1] = '0';
	}
	else
	{
		carry = 0;
		i = 1;
		while (i <= s_len[0])	
		{
			tmp[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) * y + carry) % 10 + '0';
			carry = (ft_get_digit(s1, s_len[1], i) * y + carry) / 10;
			i++;
		}
		if (carry)
			tmp[s_len[0] - i] = '1';
		else
		{
			ft_memmove(tmp, tmp + 1, s_len[0] - 1);
			tmp[s_len[0] - 1] = '\0';
		}
	}
	*s = tmp;
	return (0);
}
/*
int ft_div(char *s1, char *s2, int digit)
{
	char *ret;
	int i;
	int d;
	char *x_str;
	char *y_str;

	ret = ft_strnew(300);
	i = 0;
	d = 0;
	while (i < digit)
	{
		ret[i] = d;
		x_str = NULL;//ft_sub(x_str, ft_mul(y_str, d));
		if (ft_strlen(x_str) == 0)
			break;
		x_str = ft_mul(&x_str, x_str, 10);
		d = ft_div_int(x_str, y_str);
		//if (i == 0)
		// ret[i] = '.'
	}
	return (0);
}
*/
int main()
{
	char *ret;
	
	//ret = NULL;
	ft_sum(&ret, "10", "10", 2);
	printf("res=%s=\n", ret);
	ft_mul(&ret, "111111111111111111111111111111", 9);
	printf("res=%s=\n", ret);

	return (0);
}