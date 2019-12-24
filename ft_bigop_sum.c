/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigop_sum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/24 17:45:57 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include <stdio.h>

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

char	*ft_sum(char *s1, char *s2, int base, int i)
{
	int		carry;
	int		s_len[3];
	char	*s;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	while (++i <= s_len[0])
	{
		s[s_len[0] - i] = (ft_get_digit(s1, s_len[1], i) +
			ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) +
			ft_get_digit(s2, s_len[2], i) + carry) / base;
	}
	if (carry)
		s[s_len[0] - i] = carry;
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		s[s_len[0] - 1] = '\0';
	}
	return (s);
}

char	*ft_sum_decimal_place(char *s1, char *s2, int base, int i)
{
	int		carry;
	int		s_len[3];
	char	*s;

	s1 = ft_strchr(s1, '.') + 1;
	s2 = ft_strchr(s2, '.') + 1;
	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 2 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	while (++i <= s_len[0] - 2)
	{
		s[s_len[0] - i] = (ft_get_digit(s1, s_len[0] - 2, i) +
			ft_get_digit(s2, s_len[0] - 2, i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[0] - 2, i) +
			ft_get_digit(s2, s_len[0] - 2, i) + carry) / base;
	}
	s[1] = '.';
	s[0] = carry + '0';
	return (s);
}

void	ft_sub_move(char *s, int s_len)
{
	int	i;

	i = 0;
	while (s[i] == '0' && i < s_len - 1)
		i++;
	if (i)
	{
		ft_memmove(s, s + i, s_len - i);
		s[s_len - i] = '\0';
	}
}

char	*ft_sub(char *s1, char *s2)
{
	int		carry;
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
		s[s_len[0] - i] = (nb[0] + nb[1] - nb[2] - carry) % 10 + '0';
		carry = (nb[0] ? 1 : 0);
		i++;
	}
	ft_sub_move(s, s_len[0]);
	return (s);
}

int	main()
{
	char *ret;
	char *tmp;

	ret = ft_sum("99", "99", 10, 0 );
	printf("res_sum=%s=\n", ret);
	ret = ft_sum_decimal_place("0.625", "0.615", 10, 0);
	printf("res_sum_decimal_place=%s=\n", ret);
	
/*	ret = ft_mul("16", 7);
	printf("res_mul=%s=\n", ret);
	free(ret);
	*/
	tmp = ft_strdup("10");
    ret = ft_sub(tmp, "1");
	printf("res_sub=%s=\n", ret);

	return (0);
}