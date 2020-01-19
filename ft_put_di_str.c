/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/12 13:38:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(intmax_t n, int base)
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

/*
**
** len:
** 0 - length of output_raw
** 1 - the large of precision and len[0]
** 2 - length special (1 for sign 2 for xX and p)
** 3 - the large of width and len[1] + len [2]
** 4 - counter
*/

void	ft_get_len_output(t_spec *s_args, char *str)
{
	int	len[4];

	len[0] = ft_strlen(str);
	if (s_args->conversion == 'o' && s_args->flags[1] && len[0] == 0)
		len[0] = 1;
	len[1] = len[0];
	if (s_args->conversion != 's' && len[0] < s_args->precision)
		len[1] = s_args->precision;
	if ((ft_strcmp(str, "0") && ft_strlen(str) && (ft_strchr("xX", s_args->conversion) && s_args->flags[0] == '#')) || s_args->conversion == 'p')
		len[2] = 2;
	else
		len[2] = (s_args->sign ? 1 : 0);
	len[3] = (len[1] + len[2] < s_args->width ? s_args->width : len[1] + len[2]);
	s_args->output_len[0] = len[0];
	s_args->output_len[1] = len[1];
	s_args->output_len[2] = len[2];
	s_args->output_len[3] = len[3];
}

int	ft_put_sign(t_spec *s_args, int i)
{
		if (1 == s_args->output_len[2])
		{
			ft_putchar_fd(s_args->sign, s_args->fd);
			i++;
			s_args->output_len[2] = 0;
		}
		else if (2 == s_args->output_len[2])
		{
			ft_putchar_fd('0', s_args->fd);
			ft_putchar_fd((s_args->conversion == 'p' ? 'x' : s_args->conversion), s_args->fd);
			i = i + 2;
			s_args->output_len[2] = 0;
		}
	return (i);
}

int	ft_putchar_s_fd(char c, int i, int j, int fd)
{
	while (i < j)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
	return (i);
}

int	ft_put_output(t_spec *s_args, char *str)
{
	int		*len;
	int		i;

	i = 0;
	len = s_args->output_len;
	if (s_args->flags[1])
	{
		i = ft_put_sign(s_args, i);
		i = ft_putchar_s_fd('0', i, len[3] - len[1] - len[2], s_args->fd);
	}
	if (s_args->flags[2] == 0)
		i = ft_putchar_s_fd(' ', i, len[3] - len[1] - len[2], s_args->fd);
	if (len[2])
		i = ft_put_sign(s_args, i);
	i = ft_putchar_s_fd('0', i, i + len[1] - len[0], s_args->fd);
	if (len[3] < len[0])
		str[len[3]] = '\0';
	ft_putstr_fd(str, s_args->fd);
	i = i + (len[3] < len[0] ? len[3] : len[0]);
	i = ft_putchar_s_fd(' ', i, len[3], s_args->fd);
	s_args->len = (s_args->len >= 0 ? s_args->len + len[3] : -1);
	return (0);
}

void	ft_set_sign(t_spec *s_args)
{
	if (s_args->sign != '-')
	{
		if (s_args->flags[4] == '+')
			s_args->sign = '+';
		else if (s_args->flags[3] == ' ')
				s_args->sign = ' ';
	}
}

char	*ft_get_di_str(intmax_t n, t_spec *s_args)
{
	int 	i;
	char	*str;

	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0 )
		i = 0;
	if (s_args->precision_ini == 1)
		s_args->flags[1] = 0;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
