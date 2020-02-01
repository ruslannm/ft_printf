/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_csp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/02/01 19:25:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_arg_c(t_spec *s_args, va_list args)
{
	int				ret;
	unsigned char 	nb;
	char			str[2];

	nb = (unsigned char)va_arg(args, unsigned int);
	ret = 0;
	str[0] = nb;
	str[1] = '\0';
	ft_get_len_output(s_args, str);
	ret = (!ret ? ft_put_output(s_args, str) : ret);
	return (ret);
}

int	ft_get_arg_s(t_spec *s_args, char *str)
{
	int		ret;

	ret = 0;
	ft_get_len_output(s_args, str);
	ret = ft_put_output(s_args, str);
	return (ret);
}

int	ft_get_arg_s_va_list(t_spec *s_args, va_list args)
{
	char	*str;
	char	str_null[7];

	str = (char *)va_arg(args, char*);
	if (!str)
	{
		ft_strcpy(str_null, "(null)");
		ft_get_arg_s(s_args, str_null);
	}
	else
		ft_get_arg_s(s_args, str);
	return (0);
}

int	ft_get_arg_p(t_spec *s_args, va_list args)
{
	int		ret;
	char	*s;
	char	*str;

	ret = 0;
	s = (char *)va_arg(args, char*);
	str = ft_get_p_str(&s);
	ft_get_len_output(s_args, str);
	ret = ft_put_output(s_args, str);
	free(str);
	return (ret);
}