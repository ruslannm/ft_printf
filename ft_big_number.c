/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 15:25:52 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iseven(char c)
{
	if ('0' == c || '2' == c || '4' == c || '6' == c || '8' == c)
		return (1);
	else if ('1' == c || '3' == c || '5' == c || '7' == c || '9' == c)
		return (0);
	return (-1);
}

char	ft_div_by2_algo(char c0, char c)
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

int		ft_div_by2_first_digit(char *str)
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

void	ft_div_by2_frac(char *str)
{
	int		len;
	char	ret[50000];
	int		i;
	int		start;

	len = ft_strlen(str);
	ft_strcpy(ret, str);
	start = ft_div_by2_first_digit(str);
	i = start;
	while (i < len)
	{
		if (start == i)
			ret[i] = ft_div_by2_algo('0', str[i]);
		else
			ret[i] = ft_div_by2_algo(str[i - 1], str[i]);
		i++;
	}
	if (0 == ft_iseven(str[len - 1]))
		ft_strcpy(&ret[i++], "5");
	ret[i] = '\0';
	ft_strcpy(str, ret);
}

void	ft_mul_long(const char *s1, const char *s2, char *s3)
{
	int	l[3];
	int	i[6];

	l[1] = ft_strlen(s1);
	l[2] = ft_strlen(s2);
	ft_memset(s3, '0', l[1] + l[2]);
	s3[l[1] + l[2]] = '\0';
	i[1] = l[1] - 1;
	while (i[1] >= 0)
	{
		i[2] = l[2] - 1;
		i[3] = i[1] + i[2] + 1;
		i[5] = 0;
		while (i[2] >= 0)
		{
			i[4] = (s1[i[1]] - '0') * (s2[i[2]--] - '0') + (s3[i[3]] - '0') +
					i[5];
			i[5] = i[4] / 10;
			s3[i[3]--] = (i[4] % 10) + '0';
		}
		s3[i[3]] += i[5];
		i[1]--;
	}
	if (s3[0] == '0')
		ft_memmove(s3, s3 + 1, l[1] + l[2]);
}
