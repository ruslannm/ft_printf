/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/01 16:39:46 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_read_args(t_spec *s_args, va_list args)
{
	int	ret;

	ret = 0;
	if (ft_strchr("di", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_d(s_args, args));
	else if (ft_strchr("u", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_u(s_args, args));
	else if (ft_strchr("oxX", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_ox(s_args, args));
	else if (ft_strchr("c", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_c(s_args, args));
	else if (ft_strchr("s", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_s(s_args, args));
	else if (ft_strchr("p", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_p(s_args, args));
	else if (ft_strchr("f", s_args->conversion))
		ret = (ret == -1 ? ret : ft_get_arg_f(s_args, args));
	return (ret);
}