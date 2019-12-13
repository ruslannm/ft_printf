/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/13 18:48:13 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int	ft_get_digit(char *s, int s_len, int i)
{
	if (i > s_len)
		return (0);
	else
		return (s[s_len - i] - '0');
}

char *ft_sum(char *s1, char *s2, int base)
{
	int 	carry;
	char	*ret;
	int		s_len[3];
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	ret = ft_strnew(s_len[0] + 1);
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		ret[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) / base;
		i++;
	}
	if (carry)
		ret[s_len[0] - i] = '1';
	else
	{
		ft_memmove(ret, ret + 1, s_len[0] - 1);
		ret[s_len[0] - 1] = '\0';
	}
	return (ret);
}


int main()
{
	char *my_sum;

	my_sum = ft_sum("101", "101", 2);
	printf("res=%s", my_sum);
	return (0);
}