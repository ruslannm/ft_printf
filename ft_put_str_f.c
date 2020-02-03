/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 20:59:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** len:
** 0 - length of integer_part
** 1 - length of decimal_part
** 2 - length of sign
** 3 - lenth of printing string
** 4 - counter
*/

void	ft_get_len_output_f(t_spec *s_args, char *str, int *len)
{
	int	f_len[5];

	ft_float_len(str, f_len);
	if (s_args->precision > f_len[3])
		len[4] = s_args->precision - f_len[3];
	else
	{
		len[4] = 0;
		if (s_args->precision_ini && !s_args->precision)
		{
			if (s_args->flags[0])
				str[f_len[1] + f_len[2]] = '\0';
			else
				str[f_len[1]] = '\0';
			ft_float_len(str, f_len);
		}
	}
	len[2] = (s_args->sign ? 1 : 0);
	len[1] = f_len[0];
	if (f_len[1] + f_len[2] + f_len[3] + len[2] + len[4] < s_args->width)
		len[3] = s_args->width;
	else
		len[3] = f_len[1] + f_len[2] + f_len[3] + len[2] + len[4];
	len[0] = f_len[0];
}

void	ft_put_output_f(t_spec *s_args, char *str, int i)
{
	int	l[5];

	ft_get_len_output_f(s_args, str, l);
	if (s_args->flags[1])
	{
		i = ft_put_sign(s_args, l, i);
		i = ft_putchar_s_fd('0', i, l[3] - l[1] - l[2] - l[4], s_args->fd);
	}
	if (s_args->flags[2] == 0)
		i = ft_putchar_s_fd(' ', i, l[3] - l[1] - l[2] - l[4], s_args->fd);
	if (l[2])
		i = ft_put_sign(s_args, l, i);
	i = ft_putchar_s_fd('0', i, i + l[1] - l[0], s_args->fd);
	if (l[3] < l[0])
		str[l[3]] = '\0';
	ft_putstr_fd(str, s_args->fd);
	if (l[4])
		i = ft_putchar_s_fd('0', i, i + l[4], s_args->fd);
	i = i + (l[3] < l[0] ? l[3] : l[0]);
	i = ft_putchar_s_fd(' ', i, l[3], s_args->fd);
	s_args->len = (s_args->len >= 0 ? s_args->len + l[3] : -1);
}

void	ft_putchar_format(t_spec *s_args, char *s, int i)
{
	ft_putchar_fd(s[i], s_args->fd);
	if (s_args->len >= 0)
		s_args->len = s_args->len + 1;
}

void	ft_putchar_empty(t_spec *s_args, char *s, char *str, int i)
{
	s_args->print_char = s[i];
	str[0] = s[i];
	str[1] = '\0';
	s_args->start = s_args->start + 1 + i;
	ft_put_output(s_args, str, 0);
}

void	ft_put_output_d(t_spec *s_args, char *str)
{
	ft_set_sign(s_args);
	ft_put_output(s_args, str, 0);
}
