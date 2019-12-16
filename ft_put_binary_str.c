/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_binary_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/16 15:34:44 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_binary_str(intmax_t n, char *s)
{
	int 	i;

	i = ft_nbr_len(n, 2);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = n % 2 + '0';
		n = n / 2;
	}
	return (0);
}

