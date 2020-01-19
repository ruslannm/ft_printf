/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_csp_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:29 by rgero             #+#    #+#             */
/*   Updated: 2020/01/12 12:46:58 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c_str(unsigned char n)
{
	char	*ret;
	
	if (!(ret = ft_strnew(2)))
		return (NULL);
	ret[0] = n;
	return (ret);
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
