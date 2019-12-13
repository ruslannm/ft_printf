/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/13 17:30:31 by rgero            ###   ########.fr       */
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
	int		s1_len;
	int 	s2_len;
	int		ret_len;
	int 	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	carry = 0;
	if (s1_len > s2_len)
		ret_len = s1_len + 1;
	else
		ret_len = s2_len + 1;
	ret = ft_strnew(ret_len + 1);
	i = 1;
	while (i <= s1_len || i <= s2_len)	
	{
		if (ft_get_digit(s1, s1_len, i) + ft_get_digit(s2, s2_len, i) + carry > base)
		{
			ret[ret_len - i] = ft_get_digit(s1, s1_len, i) + ft_get_digit(s2, s2_len, i) + carry - base + '0';
			carry = 1;
		}
		else
		{
			ret[ret_len - i] = ft_get_digit(s1, s1_len, i) + ft_get_digit(s2, s2_len, i) + carry + '0';
			carry = 0;
		}
		i++;
	}
	if (carry)
		ret[ret_len - i] = '1';
	else
	{
		ft_memmove(ret, ret + 1, ret_len - 1);
		ret[ret_len - 1] = '\0';
	}
	return (ret);
}

int main()
{
	char *my_sum;

	my_sum = ft_sum("5555", "10", 10);
	printf("res=%s", my_sum);
	return (0);
}