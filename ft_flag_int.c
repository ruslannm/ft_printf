/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:48:58 by rgero             #+#    #+#             */
/*   Updated: 2019/11/13 17:54:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_int(va_list args, int *p)
{
	int output;

	output = va_arg(args, int);
	ft_putnbr(output);
	if (output == -2147483648)
		*p += 12;
	else 
	{
		if (output < 0)
		{
			*p = *p + 1;
			output = -1 * output;
		}
		while (output / 10 > 0)
		{
			output = output / 10;
			*p = *p + 1;
		}
	}
}