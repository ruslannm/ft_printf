/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/01/29 16:48:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_get_arg_f(t_spec *s_args, va_list args)
{
	int 		ret;
	long double	nb;
//	long double	lnb;

	char	str[50000];  // or 50000

	ret = 0;
	if (!s_args->modifier)
		nb = (double)va_arg(args, double);
	else if ('l' == s_args->modifier)
		nb = (double)va_arg(args, double);
	else if ('L' == s_args->modifier)
		nb = (long double)va_arg(args, long double);
	else
		nb = (double)va_arg(args, double);
	ft_set_sign(s_args);
	ft_get_f_str(nb, s_args, str);
//	ft_get_len_output_f(s_args, str);
	ft_get_len_output_f(s_args, str);
	ret = (!ret ? ft_put_output_f(s_args, str) : ret);

	return (ret);	
}





