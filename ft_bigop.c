/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/20 16:40:14 by rgero            ###   ########.fr       */
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
		s[s_len[0] - i] = '1';
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		s[s_len[0] - 1] = '\0';
	}
	return (s);
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
	while (s[i] == '0')
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
		while (i <= s_len[0])	
		{
			s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) * y + carry) % 10 + '0';
			carry = (ft_get_digit(s1, s_len[1], i) * y + carry) / 10;
			i++;
		}
		if (carry)
			s[s_len[0] - i] = '1';
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
	while (ret < 10)
	{
		s = ft_mul(s2, ret);
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
		if (ft_strlen(s1) == 0)
			break;
		s1 = ft_mul(s1, 10);
		d = ft_div_int(s1, s2);
		i++;
		//if (i == 0)
		// ret[i] = '.'
	}
	return (tmp);
}

int main()
{
	char *ret;
	char *tmp;
	
	//ret = NULL;
	ret = ft_sum("99", "99", 10);
	printf("res=%s=\n", ret);
	ret = ft_mul("111111111111111111111111111111", 0);
	printf("res=%s=\n", ret);
	free(ret);
	tmp = ft_strdup("1");
    ret = ft_sub(tmp, "0");
	printf("res=%s=\n", ret);
	ret = ft_div("1", "16", 100);
	printf("res=%s=\n", ret);

	return (0);
}