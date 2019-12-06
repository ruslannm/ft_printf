/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:29 by rgero             #+#    #+#             */
/*   Updated: 2019/12/06 16:01:54 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c_str(unsigned char n, t_spec *s_args)
{
	if (!(s_args->output_raw = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	s_args->output_raw[1] = '\0';
	s_args->output_raw[0] = n;
	return (0);
}