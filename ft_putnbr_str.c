/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/11/27 18:13:20 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

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

char	*ft_conv_sep(char *s)
{
	int i;
	int j;
	struct lconv *lc;
	char	*thousands_sep;
	char	*ret;

	lc = localeconv();
	thousands_sep = ",";//lc->thousands_sep;
	i = ft_strlen(s);
	j = (i + 1)
	i = i + ft_strlen(lc->thousands_sep) * (i + 1)/3;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	while ()
}


char	*ft_putnbr_str(intmax_t n, t_spec *s_args)
{
	char	*ret;
	int		sign;
	int 	i;
	char	*tmp;

	sign = 0;
	if (n < 0)
		s_args->sign = '-';
	
	if (n == -9223372036854775807 - 1)
	{
		tmp = ft_putnbr_str(223372036854775808, s_args);
		ret = ft_strjoin("9", tmp);
		free(tmp);
	}
	else 
	{
		if (n < 0)
			n = -1 * n;
		i = ft_get_digit(n);
		ret = (char *)malloc(sizeof(char) * (i + 1));
		ret[i] = '\0';
		while (i > 0)
		{
			if (n % 10 < 10)
				ret[i - 1] = n % 10 + '0';
			n = n / 10;
			i--;
		}
	}
	return (ret);
}
