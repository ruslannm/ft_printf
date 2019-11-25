/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:55 by rgero             #+#    #+#             */
/*   Updated: 2019/11/25 15:29:41 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_read_args(t_spec **s_args, int count_args, va_list args)
{
	int	i;

	i = 0;
	while (i < count_args)
	{
		s_args[i]->output = ft_get_arg_d(s_args[i], args);
		i++;
	}
	return (0);
}