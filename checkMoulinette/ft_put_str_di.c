/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 20:57:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** len:
** 0 - length of output_raw
** 1 - the large of precision and len[0] for s - min
** 2 - length special (1 for sign 2 for xX and p)
** 3 - the large of width and len[1] + len [2]
** 4 - counter
*/

void	ft_get_len_output(t_spec *s_args, char *str, int *len)
{
	len[0] = ft_strlen(str);
	if (('c' == s_args->conversion && 0 == len[0]) ||
	('o' == s_args->conversion && s_args->flags[0] && 0 == len[0]))
		len[0] = 1;
	len[1] = len[0];
	if ('s' != s_args->conversion && len[0] < s_args->precision)
		len[1] = s_args->precision;
	if (('s' == s_args->conversion) &&
		len[0] > s_args->precision && s_args->precision_ini)
	{
		len[0] = s_args->precision;
		len[1] = len[0];
	}
	if ((ft_strcmp(str, "0") && ft_strlen(str) &&
		(ft_strchr("xX", s_args->conversion) && s_args->flags[0] == '#')) ||
		s_args->conversion == 'p')
		len[2] = 2;
	else
		len[2] = (s_args->sign ? 1 : 0);
	len[3] = (len[1] + len[2] < s_args->width ? s_args->width :
			len[1] + len[2]);
}

int		ft_put_sign(t_spec *s_args, int *len, int i)
{
	if (1 == len[2])
	{
		ft_putchar_fd(s_args->sign, s_args->fd);
		i++;
		len[2] = 0;
	}
	else if (2 == len[2])
	{
		ft_putchar_fd('0', s_args->fd);
		ft_putchar_fd((s_args->conversion == 'p' ? 'x' : s_args->conversion),
						s_args->fd);
		i = i + 2;
		len[2] = 0;
	}
	return (i);
}

int		ft_putchar_s_fd(char c, int i, int j, int fd)
{
	while (i < j)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
	return (i);
}

void	ft_putstrn_fd(char const *s, int n, int fd)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_put_output(t_spec *s_args, char *str, int i)
{
	int		len[4];

	ft_get_len_output(s_args, str, len);
	if (s_args->flags[1])
	{
		i = ft_put_sign(s_args, len, i);
		i = ft_putchar_s_fd('0', i, len[3] - len[1] - len[2], s_args->fd);
	}
	if (s_args->flags[2] == 0)
		i = ft_putchar_s_fd(' ', i, len[3] - len[1] - len[2], s_args->fd);
	if (len[2])
		i = ft_put_sign(s_args, len, i);
	i = ft_putchar_s_fd('0', i, i + len[1] - len[0], s_args->fd);
	if (len[3] < len[0])
		str[len[3]] = '\0';
	if ((s_args->conversion == 's' || s_args->conversion == 'p') &&
		s_args->precision_ini)
		ft_putstrn_fd(str, s_args->precision, s_args->fd);
	else if (s_args->conversion == 'c')
		ft_putchar_s_fd(s_args->print_char, i, i + 1, s_args->fd);
	else
		ft_putstr_fd(str, s_args->fd);
	i = i + (len[3] < len[0] ? len[3] : len[0]);
	i = ft_putchar_s_fd(' ', i, len[3], s_args->fd);
	s_args->len = (s_args->len >= 0 ? s_args->len + len[3] : -1);
}
