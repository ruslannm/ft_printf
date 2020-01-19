/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:09:45 by rgero             #+#    #+#             */
/*   Updated: 2020/01/12 14:35:00 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_modifier(char *s, t_spec *s_args, int i)
{
	if (!ft_strncmp(&s[i], "hh", 2))
		s_args->modifier = '1';
	else if (!ft_strncmp(&s[i], "ll", 2))
		s_args->modifier = '2';
	else if (ft_strchr("hlL", s[i]))
		s_args->modifier = s[i];
	if (ft_isdigit(s_args->modifier))
		i = i + 2;
	else if (ft_isalpha(s_args->modifier))
		i++;
	return (i);
}

int	ft_parse_conversion(char *s, t_spec *s_args, int i)
{
	if (ft_strchr("cspdiouxXf", s[i]))
	{
		s_args->conversion = s[i];
		if (s_args->conversion == 'f' && !s_args->modifier && !s_args->precision_ini)
			s_args->precision = 6;
		i++;
	}
	return (i);
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
