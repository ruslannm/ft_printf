/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/06 15:36:35 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

static int	ft_get_udigit(uintmax_t n, int base)
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

int	ft_putunbr_str(uintmax_t n, t_spec *s_args)
{
	int 	i;
	int		j;

	i = ft_get_udigit(n, 10);
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
	return (0);
}

/*
int	ft_putonbr_str(uintmax_t n, t_spec *s_args)
{
	int i;
	int	j;
	int	base;

	base = 8;
	i = ft_get_udigit(n, base);
	if (!(s_args->output_raw = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s_args->output_raw[i] = '\0';
	j = 0;
	while (--i >= 0)
	{
		s_args->output_raw[i] = n % base + '0';
		n = n / base;
	}
	return (0);
}
*/

int	ft_putoxXnbr_str(uintmax_t n, t_spec *s_args)
{
	int i;
	int	j;
	int	base;

	base = (s_args->conversion == 'o' ? 8 : 16);
	i = ft_get_udigit(n, base);
	if (!(s_args->output_raw = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s_args->output_raw[i] = '\0';
	j = 0;
	while (--i >= 0)
	{
		if (n % base < 10)
			s_args->output_raw[i] = n % base + '0';
		else
			s_args->output_raw[i] = n % base - 10 + (s_args->conversion == 'x' ? 'a' : 'A');
		n = n / base;
	}
	return (0);
}
