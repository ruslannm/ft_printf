/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:55 by rgero             #+#    #+#             */
/*   Updated: 2019/12/05 16:27:20 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_read_args(t_spec **s_args, va_list args)
{
	int		i;

	i = 0;
	while (s_args[i])
	{
		ft_get_arg_d(s_args[i], args);  //TODO control error
		i++;
	}
	return (0);
}