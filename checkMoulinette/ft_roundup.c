/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundup_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 17:22:22 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_str_zero(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_roundup_diff(char *str, int precision)
{
	if (precision)
	{
		ft_strcpy(str, "0.");
		str[2 + --precision] = '1';
		while (precision-- > 0)
			str[2 + precision] = '0';
	}
	else
		ft_strcpy(str, "1.");
}

int		ft_isodd(char c)
{
	if ('1' == c || '3' == c || '5' == c || '7' == c || '9' == c)
		return (1);
	return (0);
}

void	ft_roundup(char *str, t_spec *s_args)
{
	int		precision;
	int		len[5];
	char	ret[5000];
	char	round_diff[5000];

	ft_float_len(str, len);
	precision = s_args->precision;
	if (precision < len[3])
	{
		len[4] = (precision ? precision : -1);
		if ((ft_strchr("6789", str[len[1] + 1 + precision])) ||
			('5' == str[len[1] + 1 + precision] &&
			(ft_isodd(str[len[1] + 1 + len[4] - 1]) ||
			ft_check_str_zero(&str[len[1] + 2 + precision]))))
		{
			ft_roundup_diff(round_diff, precision);
			ft_sum_float(str, round_diff, 10, ret);
			ft_strcpy(str, ret);
		}
		if ((len[1] + 1 + precision) < (int)ft_strlen(str))
			str[len[1] + 1 + precision] = '\0';
	}
}
