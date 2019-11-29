/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/11/29 17:42:24 by rgero            ###   ########.fr       */
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

char	*ft_putoutput(t_spec *s_args, char *s)
{
	int	len[5];
	char	*tmp;
	char	*output;

	tmp = s;
	len[0] = ft_strlen(tmp);
	len[1] = (len[0] < s_args->precision ? s_args->precision : len[0]);
	len[2] = (s_args->sign ? 1 : 0);
	len[3] = (len[1] + len[2] < s_args->width ? s_args->width : len[1] + len[2]);
	//len[4] = len[3] - len[1] - len[2];
	len[4] = 0;
	if (!(output = (char*)malloc(len[3] + 1)))
		return (NULL);
	output[len[3]] = '\0';
	if (!ft_strchr(s_args->flags, '-'))
		while (len[4] < len[3] - len[1] - len[2])
			output[len[4]++] = ' ';
	if (len[2])
		output[len[4]++] = s_args->sign;
	while (len[1]-- - len[0] > 0)
		output[len[4]++] = '0';
	while (len[0]-- > 0)
		output[len[4]++] = *tmp++;
	if (ft_strchr(s_args->flags, '-'))
		while (len[4] < len[3])
			output[len[4]++] = ' ';
	free(s);
	return (output);
}

void	ft_putsign(t_spec *s_args)
{
	if (s_args->sign != '-')
	{
		if (s_args->flags)
		{
			if (ft_strchr(s_args->flags, '+'))
				s_args->sign = '+';
			else if (ft_strchr(s_args->flags, ' '))
				s_args->sign = ' ';
		}
	}
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

