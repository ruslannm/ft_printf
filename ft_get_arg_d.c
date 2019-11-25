/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2019/11/25 16:01:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_get_arg_d(t_spec *s_args, va_list args)
{
	char 		*ret;
	intmax_t	nb;

	if (!ft_strcmp(&s_args->conversion, "h"))
		nb = (short)va_arg(args, int);
	else
		nb = 0;
	ret = ft_putnbr_str(nb);
	return (ret);	
}