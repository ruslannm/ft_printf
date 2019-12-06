/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:55 by rgero             #+#    #+#             */
/*   Updated: 2019/12/06 15:38:09 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_read_args(t_spec **s_args, va_list args)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (s_args[++i])
	{
		if (ft_strchr("di", s_args[i]->conversion))
			ret = (ret == -1 ? ret : ft_get_arg_d(s_args[i], args)); 
		else if (ft_strchr("u", s_args[i]->conversion))
			ret = (ret == -1 ? ret : ft_get_arg_u(s_args[i], args)); 
		else if (ft_strchr("oxX", s_args[i]->conversion))
			ret = (ret == -1 ? ret : ft_get_arg_oxX(s_args[i], args)); 

	}
	return (ret);
}