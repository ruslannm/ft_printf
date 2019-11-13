/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:52:13 by rgero             #+#    #+#             */
/*   Updated: 2019/11/13 18:17:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(int *i, const char *str, va_list args, int *p)
{
	*i = *i + 1;
	str[*i] == 'i' || str[*i] == 'd' ? ft_flag_int(args, p) : 0;
	str[*i] == 'c' ? ft_flag_char(args, p) : 0;
	str[*i] == 's' ? ft_flag_str(args, p) : 0;
}
