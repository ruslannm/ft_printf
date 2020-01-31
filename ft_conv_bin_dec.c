/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/31 15:20:35 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_shift_minus(char *str, int power)
{
	int len;
	int	i;
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
		ft_shift_minus(str, - power);
}

void	ft_conv_bin_dec(char *str)
{
	char	intpart[50000];
	char	fracpart[50000];
	int	len[4];

	ft_float_len(str, len);
	ft_conv_bin_fracpart(str, fracpart);
	//write(1, fracpart, ft_strlen(fracpart));
	ft_conv_bin_intpart(str, intpart);
	ft_strcpy(str, intpart);
	ft_strcpy(str + ft_strlen(intpart), fracpart + 1);
//	write(1, str, ft_strlen(str));

}

void	ft_sum_float(char *s1, char *s2, int base, char *s)
{
	int		len[6][4];
	char	s1_int[50000];
	char	s2_int[50000];
	char	s3[50000];
	char	s3_int[50000];
	char	s4_int[50000];
	char	s5_int[50000];

	ft_float_len(s1, len[1]);
	ft_float_len(s2, len[2]);
	ft_sum_fracpart(s1 + len[1][1] + 1, s2 + len[2][1] + 1, base, s3);
	ft_float_len(s3, len[3]);
	ft_strncpy(s3_int, s3, len[3][1]);
	s3_int[len[3][1]] = '\0';
	ft_strncpy(s1_int, s1, len[1][1]);
	s1_int[len[1][1]] = '\0';
	ft_sum_int(s1_int, s3_int, base, s4_int);
	ft_strncpy(s2_int, s2, len[2][1]);
	s2_int[len[2][1]] = '\0';
	ft_sum_int(s4_int, s2_int, base, s5_int);
	ft_float_len(s5_int, len[5]);
	ft_strcpy(s, s5_int);
	ft_strcpy(s + len[5][1], s3 + len[3][1]);
}
