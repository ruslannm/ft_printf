/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:04 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 20:16:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_flag(t_spec *s_args, char c)
{
	if (c == '#')
		s_args->flags[0] = c;
	else if (c == '0' && s_args->flags[2] == 0)
		s_args->flags[1] = c;
	else if (c == '-')
	{
		s_args->flags[2] = c;
		s_args->flags[1] = 0;
	}
	else if (c == ' ' && s_args->flags[4] == 0)
		s_args->flags[3] = c;
	else if (c == '+')
	{
		s_args->flags[4] = c;
		s_args->flags[3] = 0;
	}
}

int		ft_parse_flags(char *s, t_spec *s_args, int i, int j)
{
	if (j)
	{
		while (i < j)
		{
			if (ft_strchr("#0- +'", s[i]))
				ft_set_flag(s_args, s[i]);
			i++;
		}
	}
	else
	{
		while (s[i] && ft_strchr("#0- +'", s[i]))
			ft_set_flag(s_args, s[i++]);
	}
	return (i);
}

int		ft_parse_width(char *s, t_spec *s_args, va_list args, int i)
{
	if (ft_isdigit(s[i]))
	{
		s_args->width = ft_atoi(&s[i]);
		if (s_args->width >= 0)
			s_args->width_ini = 1;
		else
			s_args->width = 0;
		while (ft_isdigit(s[i]))
			i++;
	}
	else if ('*' == s[i])
	{
		s_args->width = (int)va_arg(args, int);
		if (s_args->width < 0)
		{
			s_args->width = -s_args->width;
			s_args->flags[2] = '-';
		}
		s_args->width_ini = 1;
		i++;
	}
	if (!s_args->width_ini && s_args->flags[1])
		s_args->flags[1] = 0;
	return (i);
}

int		ft_parse_precision(char *s, t_spec *s_args, va_list args, int i)
{
	if (s[i] == '.')
	{
		i++;
		s_args->precision_ini = 1;
		if (ft_isdigit(s[i]))
		{
			s_args->precision = ft_atoi(&s[i]);
			if (s_args->precision < 0)
				s_args->precision_ini = 0;
			while (ft_isdigit(s[i]))
				i++;
		}
		else if ('*' == s[i])
		{
			s_args->precision = (int)va_arg(args, int);
			if (s_args->precision < 0)
				s_args->precision_ini = 0;
			i++;
		}
		else
			s_args->precision = 0;
	}
	if (!s_args->precision_ini)
		s_args->precision = 0;
	return (i);
}
