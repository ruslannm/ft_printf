/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/11/25 15:36:13 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_digit(int n)
{
	int i;

	i = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}


char	*ft_putnbr_str(int n)
{
	char	*ret;
	int		sign;
	int 	i;

	sign = 0;
	if (n == -2147483648)
		ret = ft_strdup("-2147483648");
	else 
	{
		if (n < 0)
		{
			sign = 1;
			n = -1 * n;
		}
		i = ft_get_digit(n) + sign;
		ret = (char *)malloc(sizeof(char) * (i + 1));
		ret[i] = '\0';
		while (i > sign)
		{
			if (n % 10 < 10)
				ret[i - 1] = n % 10 + '0';
			n = n / 10;
			i--;
		}
		if (sign == 1)
			ret[0] = '-';
	}
	return (ret);
}
