/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 15:26:45 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_shift_minus(char *str, int power)
{
	int		len;
	int		i;
	char	str_new[50000];

	len = ft_strlen(str);
	i = 0;
	if (len > power)
	{
		ft_strncpy(str_new, str, len - power);
		ft_strcpy(&str_new[len - power + 1], &str[len - power]);
		str_new[len - power] = '.';
		ft_strcpy(str, str_new);
	}
	else
	{
		ft_strcpy(str_new, "0.");
		ft_strcpy(&str_new[power - len + 2], str);
		i = 0;
		while (i < power - len)
			str_new[i++ + 2] = '0';
		ft_strcpy(str, str_new);
	}
}

void	ft_shift(char *str, int power)
{
	int len;
	int	i;

	len = ft_strlen(str);
	i = len;
	if (power > 0)
	{
		while (i < len + power)
			str[i++] = '0';
		str[len + power] = '.';
		str[len + power + 1] = '\0';
	}
	else if (power < 0)
		ft_shift_minus(str, -power);
}

void	ft_conv_bin_dec(t_spec *s_args, char *str)
{
	char	intpart[50000];
	char	fracpart[50000];
	int		len[4];

	ft_float_len(str, len);
	ft_conv_bin_intpart(str, intpart);
	ft_conv_bin_fracpart(s_args, str, fracpart);
	ft_strcpy(str, intpart);
	ft_strcpy(str + ft_strlen(intpart), fracpart + 1);
}

void	ft_sum_float(char *s1, char *s2, int base, char *s)
{
	int		len[6][4];
	char	s3[50000];
	char	s_int[6][50000];

	ft_float_len(s1, len[1]);
	ft_float_len(s2, len[2]);
	ft_sum_fracpart(s1, s2, base, s3);
	ft_float_len(s3, len[3]);
	ft_strncpy(s_int[3], s3, len[3][1]);
	s_int[3][len[3][1]] = '\0';
	ft_strncpy(s_int[1], s1, len[1][1]);
	s_int[1][len[1][1]] = '\0';
	ft_sum_int(s_int[1], s_int[3], base, s_int[4]);
	ft_strncpy(s_int[2], s2, len[2][1]);
	s_int[2][len[2][1]] = '\0';
	ft_sum_int(s_int[4], s_int[2], base, s_int[5]);
	ft_float_len(s_int[5], len[5]);
	ft_strcpy(s, s_int[5]);
	ft_strcpy(s + len[5][1], s3 + len[3][1]);
}
