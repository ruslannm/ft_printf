/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/19 17:55:50 by rgero            ###   ########.fr       */
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
		ft_memmove(tmp, tmp + 1, s_len[0] - 1);
		tmp[s_len[0] - 1] = '\0';
	}
	*s = tmp;
	return (0);
}

char	*ft_sub(char *s1, char *s2)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*tmp;
	int		nb[3];

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = s_len[1];
	carry = 0;
	tmp = s1;
	i = 1;
	while (i <= s_len[1])	
	{
		nb[1] = ft_get_digit(s1, s_len[1], i);
		nb[2] = ft_get_digit(s2, s_len[2], i);
		nb[0] = ((nb[1] - carry) < nb[2] ? 10 : 0);
		tmp[s_len[0] - i]  = (nb[0] + nb[1] - nb[2] - carry) % 10 + '0';
		carry = (nb[0] ? 1 : 0);
		i++;
	}
	i = 0;
	while (tmp[i] == '0')
		i++;
	if (i)
	{
		ft_memmove(tmp, tmp + i, s_len[0] - i);
		tmp[s_len[0] - i] = '\0';
	}
	return (tmp);
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
	if (!y)
		tmp[0] = '0';
	else if	(y == 10)
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

int 	ft_div_int(char *s1, char *s2)
{
	int		ret;
	char	*s;
	
	ret = 1;
	while (ret < 10)
	{
		ft_mul(&s, s2, ret);
		if (ft_strcmp(s, s1) > 0)
		{
			ret = ret - 1;
			free(s);
			break;
		}
		else if (ft_strcmp(s, s1) == 0)
		{
			free(s);
			break;
		}
		ret++;
		free(s);
	}
	return (0);
}


int ft_div(char **s, char *s1, char *s2, int digit)
{
	char *ret;
	int i;
	int d;
//	char *x_str;
//	char *y_str;
	char	*tmp;

	ret = ft_strnew(digit);
	i = 0;
	d = 0;
	while (i < digit)
	{
		ret[i] = d;
		ft_mul(&tmp, s2, d);
		s1 = ft_sub(s1, tmp);
		if (ft_strlen(s1) == 0)
			break;
		ft_mul(&s1, s1, 10);
		d = ft_div_int(s1, s2);
		//if (i == 0)
		// ret[i] = '.'
	}
	*s =ret;
	return (0);
}

int main()
{
	char *ret;
	
	//ret = NULL;
	ft_sum(&ret, "99", "99", 10);
	printf("res=%s=\n", ret);
	ft_mul(&ret, "111111111111111111111111111111", 0);
	printf("res=%s=\n", ret);
	free(ret);
	ret = ft_strdup("123");
    ret = ft_sub(ret, "123");
	printf("res=%s=\n", ret);
	ft_div(&ret, "1", "10", 100);
	printf("res=%s=\n", ret);

	return (0);
}