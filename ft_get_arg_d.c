/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2019/11/27 18:01:37 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_get_arg_d(t_spec *s_args, va_list args)
{
	char 		*ret;
	intmax_t	nb;

	if (!s_args->modifier)
		nb = (int)va_arg(args, int);
	else if (!ft_strcmp(s_args->modifier, "h"))
		nb = (short)va_arg(args, int);
	else if (!ft_strcmp(s_args->modifier, "hh"))
		nb = (signed char)va_arg(args, int);
	else if (!ft_strcmp(s_args->modifier, "l"))
		nb = (long)va_arg(args, long int);
	else if (!ft_strcmp(s_args->modifier, "ll"))
		nb = (long long)va_arg(args, long long int);
	else
		nb = (int)va_arg(args, int);
	ret = ft_putnbr_str(nb, s_args);
	return (ret);	
}