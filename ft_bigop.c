/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/18 15:48:25 by rgero            ###   ########.fr       */
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

/*
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
*/

int main()
{
	char *ret;
	
	//ret = NULL;
	ft_sum(&ret, "10", "10", 2);
	printf("res=%s=\n", ret);
	return (0);
}