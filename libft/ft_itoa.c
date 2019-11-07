/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:11:22 by rgero             #+#    #+#             */
/*   Updated: 2019/09/15 13:51:34 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	ret;

	ret = 0;
	while (n > 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

static char		*ft_except(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == -0)
		return (ft_strdup("0"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

static size_t	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	size_t	sign;

	if (n == -2147483648 || n == -0 || n == 0)
		return (ft_except(n));
	sign = ft_sign(n);
	if (sign == 1)
		n = -1 * n;
	len = sign + ft_nbrlen(n);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (--len > 0)
	{
		ret[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		ret[0] = '-';
	else
		ret[0] = n % 10 + '0';
	return (ret);
}
