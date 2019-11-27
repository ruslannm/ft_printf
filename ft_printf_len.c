/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:07:20 by rgero             #+#    #+#             */
/*   Updated: 2019/11/27 15:15:53 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_len(char *format, t_spec **s_args)
{
	int	i;
	int ret;
	
	ret = ft_strlen(format);
	i = -1;
	while (s_args[++i])
		ret = ret + ft_strlen(s_args[i]->output) - s_args[i]->len - 1 ;
	return (ret);
}