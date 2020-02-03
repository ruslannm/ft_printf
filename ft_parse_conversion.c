/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:09:45 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 19:12:19 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_modifier(char *s, t_spec *s_args, int i)
{
	if (!ft_strncmp(&s[i], "hhl", 3))
		s_args->modifier = '7';
	else if (!ft_strncmp(&s[i], "hh", 2))
		s_args->modifier = '1';
	else if (!ft_strncmp(&s[i], "ll", 2))
		s_args->modifier = '2';
	else if (!ft_strncmp(&s[i], "lhl", 3))
		s_args->modifier = '6';
	else if (!ft_strncmp(&s[i], "lh", 2))
		s_args->modifier = '3';
	else if (!ft_strncmp(&s[i], "zh", 2))
		s_args->modifier = '4';
	else if (!ft_strncmp(&s[i], "jz", 2) || !ft_strncmp(&s[i], "jh", 2))
		s_args->modifier = '5';
	else if (ft_strchr("hlLjz", s[i]))
		s_args->modifier = s[i];
	if (ft_isdigit(s_args->modifier))
		i = i + 2;
	if ('6' == s_args->modifier || '7' == s_args->modifier)
		i++;
	else if (ft_isalpha(s_args->modifier))
		i++;
	return (i);
}

int	ft_parse_conversion(char *s, t_spec *s_args, int i)
{
	int	ret;

	ret = i;
	while (s[i] != '\0' && s[i] != '%')
	{
		if (ft_strchr("cspdiouUxXflzjh", s[i]))
		{
			s_args->conversion = s[i];
			if (s_args->conversion == 'f' && !s_args->precision_ini)
				s_args->precision = 6;
			if (ft_strchr("diouUixX", s[i]) && s_args->precision_ini)
				s_args->flags[1] = 0;
			if ('c' == s[i] && s_args->precision_ini)
			{
				s_args->precision = 0;
				s_args->precision_ini = 0;
			}
			i++;
			break ;
		}
		i++;
	}
	if (i > ret)
		ft_parse_flags(s, s_args, ret, i);
	return (s_args->conversion ? i : ret);
}

int	ft_parse_percent(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '%')
			return (i);
		i++;
	}
	return (-1);
}
