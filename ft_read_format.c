/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:02 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 15:28:49 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format_spec(char *s, t_spec *s_args, int i)
{
	i = ft_parse_flags(s, s_args, i);
	i = ft_parse_width(s, s_args, i);
	i = ft_parse_precision(s, s_args, i);
	i = ft_parse_modifier(s, s_args, i);
	i = ft_parse_conversion(s, s_args, i);
	return (i);
}

int	ft_parse_format(t_spec *s_args, va_list args)
{
	int		i;
	char	*s;
	char	str[5000];
	int		percent;

	s = s_args->format + s_args->start;
	i = ft_parse_format_spec(s, s_args, 0);
	percent = ft_parse_percent(s, 0);
	if (0 == s_args->conversion)
	{
		if (0 == i)
		{
			str[0] = s[0];
			str[1] = '\0';
			i = 1;
		}
		else if (percent == i)
			ft_strcpy(str, "%");
		else if (percent > 0)
		{
			ft_strncpy(str, s + i, percent - 1);
			str[percent - 1] = '\0';
		}
		else
		{
			s_args->start = s_args->start + i;
			return (0);
		}
		ft_get_arg_s(s_args, str);
		s_args->start = s_args->start + (percent > 0 ? percent + 1 : i);
	}
	else
	{
		s_args->start = s_args->start + i;
		ft_read_args(s_args, args);
	}
	return (0);
}

int	ft_new_spec(t_spec **s_args, char *format, int start, int fd)
{
	if (!*s_args)
	{
		if (!(*s_args = (t_spec*)malloc(sizeof(t_spec))))
			return (-1);
		(*s_args)->len = 0;
		(*s_args)->width_diff = 0;
		(*s_args)->fd = fd;
		if (!((*s_args)->format = ft_strdup(format)))
			return (-1);
	}
	(*s_args)->position = 0;
	(*s_args)->flags[0] = 0;
	(*s_args)->flags[1] = 0;
	(*s_args)->flags[2] = 0;
	(*s_args)->flags[3] = 0;
	(*s_args)->flags[4] = 0;
	(*s_args)->width_ini = 0;
	(*s_args)->width = 0;
	(*s_args)->precision_ini = 0;
	(*s_args)->precision = 0;
	(*s_args)->modifier = 0;
	(*s_args)->conversion = 0;
	(*s_args)->start = start;
	(*s_args)->sign = 0;
	return (0);
}

int	ft_parse(t_spec *s_args, va_list args)
{
	int		i;
	char	*s;

	i = -1;
	s = s_args->format;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_new_spec(&s_args, NULL, i + 1, 0);
			ft_parse_format(s_args, args);
			i = s_args->start - 1;
		}
		else
		{
			ft_putchar_fd(s[i], s_args->fd);
			if (s_args->len >= 0)
				s_args->len = s_args->len + 1;
		}
	}
	if (-1 == s_args->len)
		return (-1);
	return (s_args->len);
}
