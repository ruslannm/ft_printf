/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/01/12 10:56:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_arg_c(t_spec *s_args, va_list args)
{
	int				ret;
	unsigned char	nb;
	char			*str;

	nb = (unsigned char)va_arg(args, unsigned int);
	ret = 0;
	if (!nb)
	{
		if (s_args->width)
			s_args->width =  s_args->width - 1;
		s_args->width_diff = 1;
	}
	if (!(str = ft_get_c_str(nb)))
		return (-1);
	ft_get_len_output(s_args, str);
	ret = (!ret ? ft_put_output(s_args, str) : ret);
	return (ret);	
}

int	ft_get_arg_s(t_spec *s_args, va_list args)
{
	int		ret;
	char	*str;

	ret = 0;
	str = (char *)va_arg(args, char*);
	if (!str)
	{
		if (!(str = ft_strdup("(null)")))
			return (-1);
	}
	if (s_args->precision_ini && (size_t)s_args->precision < ft_strlen(str))
		str[s_args->precision] = '\0';
//	ret = ft_put_s_str(s, s_args);
	ft_get_len_output(s_args, str);
	ret =  ft_put_output(s_args, str);
	return (ret);	
}

int	ft_get_arg_p(t_spec *s_args, va_list args)
{
	int		ret;
	char	*s;
	char	*str;

	ret = 0;
	s = (char *)va_arg(args, char*);
	str = ft_get_p_str(s);
	ft_get_len_output(s_args, str);
//	ret = ft_put_output_xX(s_args, str);
	ret = ft_put_output(s_args, str);
	return (ret);	
}