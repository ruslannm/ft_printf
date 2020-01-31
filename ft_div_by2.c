/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_by2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:26:38 by rgero             #+#    #+#             */
/*   Updated: 2020/01/31 14:35:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iseven(char c)
{
	if ('0' == c || '2' == c || '4' == c || '6' == c || '8' == c)
		return (1);
	else if ('1' == c || '3' == c || '5' == c || '7' == c || '9' == c)
		return (0);
	return (- 1);
}

char	ft_div_by2_algo(char c0, char c)
{
	if (1 == ft_iseven(c0))
	{
		if ('0' == c || '1' == c)
			return ('0');
		else if ('2' == c || '3' == c)
			return ('1');
		else if ('4' == c || '5' == c)
			return ('2');
		else if ('6' == c || '7' == c)
			return ('3');
		return ('4');
	}
	else
	{
		if ('0' == c || '1' == c)
			return ('5');
		else if ('2' == c || '3' == c)
			return ('6');
		else if ('4' == c || '5' == c)
			return ('7');
		else if ('6' == c || '7' == c)
			return ('8');
		return ('9');
	}
}

int	ft_div_by2_first_digit(char *str)
{
	int i;

	i = 2;
	while (str[i])
	{
		if (0 != str[i])
			return (i);
		i++;
	}
	return (i);
}

void ft_div_by2_frac(char *str)
{
	int		len;
	char	ret[50000];
	int		i;
	int		start;

	len = ft_strlen(str);
	ft_strcpy(ret, str);
	start = ft_div_by2_first_digit(str);
	i = start;
	while (i < len)
	{
		if (start == i)
			ret[i] = ft_div_by2_algo('0', str[i]);
		else
			ret[i] = ft_div_by2_algo(str[i - 1], str[i]);
		i++;
	}
	if (0 == ft_iseven(str[len - 1]))
		ft_strcpy(&ret[i++], "5");
	ret[i] = '\0';
	ft_strcpy(str, ret);
}
