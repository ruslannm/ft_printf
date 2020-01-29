/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/29 15:45:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_shift(char *str, int power)
{
//	char s_new[33000];
	int len[5];
//	int len1_new;
	int	i;

	ft_float_len(str, len);
	i = len[1];
	if (power > 0)
	{
		while (i < len[0] - 1)
		{
			str[i] = str[i + 1];
			i++;
		}
		while (i < len[1] + power)
		{
			str[i] = '0';
			i++;
		}
		str[len[1] + power] = '.';
		str[len[0] + power] = '\0';
	}
}

/*

void	ft_shift1(char *str, int i)
{
	char s_new[33000];
	int len[5];
	int len1_new;

	ft_float_len(str, len);
	if (i > 0)
	{
		len[4] = len[0] + (i > len[3] ? i - len[3] : 0); 
		s_new[len[4]] = '\0';
		str[len[4]] = '\0';
		if (1 == len[1] && '0' == str[0])
			len1_new = 0;
		else
			len1_new = 1;		
		ft_strncpy(s_new, str, len1_new);
		if (i > len[3])
		{
			ft_strncpy(&s_new[len1_new], &str[len[1] + 1], len[3]);
			s_new[--len[4]] = '.';
			while (i-- > len[3])
				s_new[--len[4]] = '0';
		}
		else
		{
			ft_strncpy(&s_new[len1_new], &str[len[1] + 1], i);
			s_new[i + len1_new] = '.';
			ft_strncpy(&s_new[i + len1_new + 1], &str[i + len[1] + 1], len[3] - i);
		}
		ft_strcpy(str, s_new);
	}
	else if (i < 0)
	{
		len[4] = len[0] + (-i >= len[1]? - i - len[1] + 1 : 0) + (len[2] ? 0 : 1); 
		s_new[len[4]] = '\0';
		str[len[4]] = '\0';
		if (-i >= len[1])
		{
			ft_strncpy(s_new, "0.", 2);
			ft_strncpy(&s_new[2 - i - len[1]], str, len[1]);
			ft_strncpy(&s_new[2 - i], &str[len[1] + 1], len[3]);
			while (len[1] < - i++)
				s_new[2 - i - len[1]] = '0';
		}
		else
		{
			ft_strncpy(s_new, str, len[1] + i);
			s_new[i + len[1]] = '.';
			ft_strncpy(&s_new[i + len[1] + 1], &str[i + len[1]], - i);  //Error
			ft_strncpy(&s_new[len[1] + 1], &str[len[1] + 1], len[3]);
		}
	}
	ft_strcpy(str, s_new);
}
*/

void	ft_conv_bin_dec(char *str)
{
	char	int_part[5000];
	char	dec_part[5000];
	int	len[4];

	ft_float_len(str, len);
	ft_conv_bin_fracpart(str, dec_part);
	//str[len[1] + len[2]] = '\0';
	ft_conv_bin_intpart(str, int_part);
	ft_strcpy(str, int_part);
	ft_strcpy(str + ft_strlen(int_part), dec_part + 1);
}
