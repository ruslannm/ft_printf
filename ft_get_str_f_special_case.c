/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_f_special_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 18:45:00 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_mantissa_len(unsigned long int n, int base)
{
	int i;

	i = 1;
	while (n / base > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

void	ft_get_str_f_null(t_spec *s_args, int sign, char *str)
{
	if (sign)
		s_args->sign = '-';
	ft_strcpy(str, "0.000000");
}

/*
** -1 - Error
**  0 - Inf
**	1 - NaN
*/

int		ft_check_mantissa(char *str)
{
	if (!ft_strncmp(str, "00", 2))
		return (ft_check_str_zero(&str[2]));
	else if (!ft_strncmp(str, "01", 2))
		return (1);
	else if (!ft_strncmp(str, "10", 2))
		return (ft_check_str_zero(&str[2]));
	else if (!ft_strncmp(str, "11", 2))
	{
		if (ft_check_str_zero(&str[2]))
			return (0);
		else
			return (1);
	}
	return (-1);
}

void	ft_get_str_f_naninf(t_spec *s_args, unsigned long int mantissa,
		char *str)
{
	char	m_str[64];

	ft_get_str_binary(mantissa, 63, m_str);
	if (1 == ft_check_mantissa(m_str))
	{
		ft_strcpy(str, "nan");
		s_args->flags[3] = 0;
		s_args->flags[4] = 0;
		s_args->sign = 0;
	}
	else
		ft_strcpy(str, "inf");
	s_args->precision = 0;
	s_args->precision_ini = 1;
	s_args->flags[0] = 0;
	s_args->flags[1] = 0;
}
