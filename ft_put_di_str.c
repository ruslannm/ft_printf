/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/11 14:23:22 by rgero            ###   ########.fr       */
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

void	ft_get_len_output(t_spec *s_args)
{
	int	len[4];

	len[0] = ft_strlen(s_args->output_raw);
	if (s_args->conversion == 'o' && s_args->flags[1] && len[0] == 0)
		len[0] = 1;
	len[1] = (len[0] < s_args->precision ? s_args->precision : len[0]);
//	if (s_args->output_raw && ((ft_strchr("xX", s_args->conversion) && s_args->flags[0] == '#') || s_args->conversion == 'p'))
//		len[2] = 2;
//	else
//		len[2] = (s_args->sign ? 1 : 0);
	len[2] = (s_args->sign ? 1 : 0);
	len[3] = (len[1] + len[2] < s_args->width ? s_args->width : len[1] + len[2]);
	s_args->output_len[0] = len[0];
	s_args->output_len[1] = len[1];
	s_args->output_len[2] = len[2];
	s_args->output_len[3] = len[3];
	s_args->output_len[4] = 0;
}

int	ft_putoutput(t_spec *s_args)
{
	int		*len;
	char	*tmp;
	char	*output;

	len = s_args->output_len;
	tmp = s_args->output_raw;
	if (!(output = ft_strnew(len[3])))
		return (-1);
	if (s_args->flags[1])
	{
		if (len[2] == 1)
		{
			output[len[4]++] = s_args->sign;
			len[2] = 0;
		}
		while (len[4] < len[3] - len[1] - len[2])
			output[len[4]++] = '0';
	}
	if (s_args->flags[2] == 0)
		while (len[4] < len[3] - len[1] - len[2])
			output[len[4]++] = ' ';
	if (len[2])
		output[len[4]++] = s_args->sign;
	while (len[1]-- - len[0] > 0)
		output[len[4]++] = '0';
	while (len[0]-- > 0)
		output[len[4]++] = *tmp++;
	if (s_args->flags[2] != 0)
		while (len[4] < len[3])
			output[len[4]++] = ' ';
	s_args->output = output;
	return (0);
}

int	ft_putoutput_xX(t_spec *s_args)
{
	int		*len;
	char	*tmp;
	char	*output;

	len = s_args->output_len;
	tmp = s_args->output_raw;
	if (!(output = ft_strnew(len[3])))
		return (-1);
	if (s_args->flags[2] == 0 && s_args->flags[1] == 0)
	{
		while (len[4] < len[3] - len[1] - len[2])
			output[len[4]++] = ' ';
	}
	if (len[2])
	{
		output[len[4]++] = '0';
		output[len[4]++] = (s_args->conversion == 'p' ? 'x' : s_args->conversion);
	}
	if (s_args->flags[1])
	{
		while (len[4] < len[3] - len[1] - len[2])
			output[len[4]++] = '0';
	}
	while (len[1]-- - len[0] > 0)
		output[len[4]++] = '0';
	while (len[0]-- > 0)
		output[len[4]++] = *tmp++;
	if (s_args->flags[2] != 0)
		while (len[4] < len[3])
			output[len[4]++] = ' ';
	s_args->output = output;
	return (0);
}


void	ft_putsign(t_spec *s_args)
{
	if (s_args->sign != '-')
	{
		if (s_args->flags[4] == '+')
			s_args->sign = '+';
		else if (s_args->flags[3] == ' ')
				s_args->sign = ' ';
	}
}

int	ft_put_di_str(intmax_t n, t_spec *s_args)
{
	int 	i;

	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0 )
		i = 0;
	if (!(s_args->output_raw = ft_strnew(i)))
		return (-1);
	s_args->output_raw[i] = '\0';
	while (--i >= 0)
	{
		s_args->output_raw[i] = n % 10 + '0';
		n = n / 10;
	}
	return (0);
}

/*

int	ft_put_di_str(intmax_t n, t_spec *s_args)
{
	int 	i;
	int		j;

	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	i = i + (s_args->flags[5] == 39 ? THOUSAND_SEP_LEN * (i / 3 ) : 0);
	if (!(s_args->output_raw = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s_args->output_raw[i] = '\0';
	j = 0;
	while (--i >= 0)
	{
		if (j++ % 3 == 0 && j > 2 && s_args->flags[5] == 39 && THOUSAND_SEP_LEN > 0)
		{
			ft_strncpy(&s_args->output_raw[i + 1 - THOUSAND_SEP_LEN], THOUSAND_SEP, THOUSAND_SEP_LEN);
			i = i - THOUSAND_SEP_LEN;
		}
		s_args->output_raw[i] = n % 10 + '0';
		n = n / 10;
	}
	if s_args->output_raw[i]
	return (0);
}
*/
