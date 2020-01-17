/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/01/16 16:10:41 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_get_arg_f(t_spec *s_args, va_list args)
{
	int 		ret;
	long double	nb;

	if (!s_args->modifier)
		nb = (long double)va_arg(args, double);
	else if (!ft_strcmp(s_args->modifier, "l"))
		nb = (double)va_arg(args, double);
	else if (!ft_strcmp(s_args->modifier, "L"))
		nb = (long double)va_arg(args, long double);
	else
		nb = (double)va_arg(args, double);
//	if (nb == "NaN")
	ft_putsign(s_args);
	ret = ft_put_f_str((float)nb, s_args);
	ft_get_len_output_f(s_args);
	ret = (!ret ? ft_putoutput_f(s_args) : ret);

	return (ret);	
}





