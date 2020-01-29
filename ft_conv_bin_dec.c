/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/29 17:35:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_shift_minus(char *str, int power)
{
	char s_new[33000];
	int len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (len > power)
	{
		str[len + 1] = '\0';
		while (len - i++ > power)
		{
			str[len - i + 1] = str[len - i];
		//	i++;
		}
		str[len - i] = '.';
	}
	else 
	{
		i = len;
		ft_strcpy(s_new, "0.");
		i = 0;
		while (i < power - 1)
			s_new[i++ + 2] = '0';
		s_new[i++ + 2] = '1';
		ft_strcpy(s_new + i++ + 2, str + 2);
		s_new[i + 2] = '\0';
		ft_strcpy(str, s_new);
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
	char	int_part[50000];
	char	dec_part[50000];
	int	len[4];

	ft_float_len(str, len);
	ft_conv_bin_fracpart(str, dec_part);
	ft_conv_bin_intpart(str, int_part);
	ft_strcpy(str, int_part);
	ft_strcpy(str + ft_strlen(int_part), dec_part + 1);
}

void	ft_sum_float(char *s1, char *s2, int base, char *s)
{
	int		len[6][4];
	char	s3[50000];
	char	s4[50000];
	char	s5[50000];

//	ft_float_len(s1, len[1]);
//	ft_float_len(s2, len[2]);
	ft_sum_fracpart(s1, s2, base, s3);
	ft_sum_int(s1, s2, base, s4);
	ft_sum_int(s3, s4, base, s5);
	ft_float_len(s5, len[5]);
	ft_float_len(s3, len[3]);
	ft_strcpy(s, s5);
	ft_strcpy(s + len[5][1], s3 + len[3][1]);
}
