/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/05 16:14:53 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static intmax_t	ft_get_maxpower(intmax_t n)
{
	intmax_t i;

	i = 1;
	while (i * 10 < n)
		i *= 10;
	return (i);
}
*/
static int	ft_get_digit(intmax_t n)
{
	int i;

	i = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}


void	ft_get_len_output(t_spec *s_args, char *s)
{
	int	len[6];

	len[0] = ft_strlen(s);
	len[1] = (len[0] < s_args->precision ? s_args->precision : len[0]);
	len[2] = (s_args->sign ? 1 : 0);
	len[3] = ft_strlen(s_args->thousand_sep) * (len[0] + 1)/3;
	len[4] = (len[1] + len[2] + len[3] < s_args->width ? s_args->width : len[1] + len[2] + len[3]);
	len[5] = 0;
	s_args->output_len[0] = len[0];
	s_args->output_len[1] = len[1];
	s_args->output_len[2] = len[2];
	s_args->output_len[3] = len[3];
	s_args->output_len[4] = len[4];
	s_args->output_len[5] = 0;
}

char	*ft_putoutput(t_spec *s_args, char *s)
{
	int		*len;
	char	*tmp;
	char	*output;

	len = s_args->output_len;
	tmp = s;
	if (!(output = (char*)malloc(len[4] + 1)))
		return (NULL);
	output[len[4]] = '\0';
	if (s_args->flags[2] == 0)
		while (len[5] < len[4] - len[1] - len[2] - len[3])
			output[len[5]++] = ' ';
	if (len[2])
		output[len[5]++] = s_args->sign;
	while (len[1]-- - len[0] > 0)
		output[len[5]++] = '0';
	while (len[0]-- > 0)
		output[len[5]++] = *tmp++;
	if (s_args->flags[2] != 0)
		while (len[4] < len[3])
			output[len[4]++] = ' ';
	free(s);
	return (output);
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

int	ft_putnbr_str(intmax_t n, t_spec *s_args)
{
	int 	i;
	int		j;

	n = n * (n < 0 ? -1 : 1);
	i = ft_get_digit(n);
	i = i + (s_args->flags[5] == 39 ? THOUSAND_SEP_LEN * (i / 3 ) : 0);
	if (!(s_args->output = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s_args->output[i] = '\0';
	j = 0;
	while (--i >= 0)
	{
		if (j++ % 3 == 0 && j > 2 && s_args->flags[5] == 39 && THOUSAND_SEP_LEN > 0)
		{
			ft_strncpy(&s_args->output[i + 1 - THOUSAND_SEP_LEN], THOUSAND_SEP, THOUSAND_SEP_LEN);
			i = i - THOUSAND_SEP_LEN;
		}
		s_args->output[i] = n % 10 + '0';
		n = n / 10;
	}
	return (0);
}
