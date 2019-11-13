/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:07:45 by rgero             #+#    #+#             */
/*   Updated: 2019/11/13 18:22:07 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_char(va_list args, int *p)
{
	char output;

	output = (char)va_arg(args, int);
	*p = *p + 1;
	ft_putchar(output);
}

void	ft_flag_str(va_list args, int *p)
{
	char	*output;

	output = (char*)va_arg(args, char*);
	if (output)
	{
		*p = *p + ft_strlen(output);
		ft_putstr(output);
	}
	else
	{
		*p = *p + 6;
		ft_putstr("(null)");
	}
}