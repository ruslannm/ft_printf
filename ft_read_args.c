/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 16:02:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read_args(t_spec *s_args, va_list args)
{
	if (ft_strchr("di", s_args->conversion))
		ft_get_arg_d(s_args, args);
	else if (ft_strchr("u", s_args->conversion))
		ft_get_arg_u(s_args, args);
	else if (ft_strchr("oxX", s_args->conversion))
		ft_get_arg_ox(s_args, args);
	else if (ft_strchr("c", s_args->conversion))
		ft_get_arg_c(s_args, args);
	else if (ft_strchr("s", s_args->conversion))
		ft_get_arg_s_va_list(s_args, args);
	else if (ft_strchr("p", s_args->conversion))
		ft_get_arg_p(s_args, args);
	else if (ft_strchr("f", s_args->conversion))
		ft_get_arg_f(s_args, args);
}