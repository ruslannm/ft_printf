/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_csp_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:29 by rgero             #+#    #+#             */
/*   Updated: 2020/01/12 12:46:58 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c_str(unsigned char n)
{
	char	*ret;
	
	if (!(ret = ft_strnew(2)))
		return (NULL);
	ret[0] = n;
	return (ret);
}
/*
char	*ft_get_s_str(char *s, t_spec *s_args)
{
	if (!s)
	{
		if (!(s_args->output_raw = ft_strdup("(null)")))
			return (-1);
	}
	else
	{
		if (!(s_args->output_raw = ft_strdup(s)))
			return (-1);
	}
	if (s_args->precision_ini && (size_t)s_args->precision < ft_strlen(s_args->output_raw))
		s_args->output_raw[s_args->precision] = '\0';
	return (0);
}
*/