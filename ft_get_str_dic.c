/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_dic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:29 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 16:15:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_di_str(intmax_t n, t_spec *s_args, char *str)
{
	int 	i;

	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
	str[i] = '\0';
	if (s_args->precision_ini == 1)
		s_args->flags[1] = 0;
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
}
