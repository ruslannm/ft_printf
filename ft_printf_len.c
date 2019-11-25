/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:07:20 by rgero             #+#    #+#             */
/*   Updated: 2019/11/25 17:16:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prinf_len(char *format, t_spec **s_args, int count_args)
{
	int	i;
	int ret;
	
	ret = ft_strlen(format);
	i = 0;
	while (i < count_args)
	{
		ret = ret + ft_strlen(s_args[i]->output) - s_args[i]->len - 1 ;
		i++;
	}
	return (ret);
}