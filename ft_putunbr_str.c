/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/02 17:39:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

static int		ft_get_udigit(uintmax_t n)
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

/*
TODO
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
*/

char	*ft_putunbr_str(uintmax_t n, t_spec *s_args)
{
	char	*ret;
	int 	i;

	//18446744073709551615 uintmax
	// 9223372036854775807
	if (s_args->flags[5] != 0)
		i = 0; // TODO conv_sep

	i = ft_get_udigit(n);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	ret[i] = '\0';
	while (i > 0)
	{
		if (n % 10 < 10)
			ret[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (ret);
}

