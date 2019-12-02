/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2019/12/02 17:40:07 by rgero            ###   ########.fr       */
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
	ft_putsign(s_args);
	ret = ft_putoutput(s_args, ret);
	return (ret);	
}

char *ft_get_arg_u(t_spec *s_args, va_list args)
{
	char 		*ret;
	uintmax_t	nb;

	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "h"))
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "hh"))
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "l"))
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if (!ft_strcmp(s_args->modifier, "ll"))
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	ret = ft_putunbr_str(nb, s_args);
	ret = ft_putoutput(s_args, ret);
	return (ret);	
}
