/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/05 16:18:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

static int		ft_get_udigit(uintmax_t n)
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

int	ft_putunbr_str(uintmax_t n, t_spec *s_args)
{
	int 	i;
	int		j;

	i = ft_get_udigit(n);
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

/*

char	*ft_putunbr_str(uintmax_t n, t_spec *s_args)
{
	char	*ret;
	int 	i;

	//18446744073709551615 uintmax
	// 9223372036854775807
	if (s_args->flags[5] != 0)
		i = 0; // TODO conv_sep

	i = ft_get_udigit(n);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	ret[i] = '\0';
	while (i > 0)
	{
		if (n % 10 < 10)
			ret[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (ret);
}

*/