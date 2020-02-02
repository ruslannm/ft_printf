/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_csp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 16:30:21 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_arg_c(t_spec *s_args, va_list args)
{
	int				ret;
	unsigned char 	nb;
	char			str[2];

	nb = (unsigned char)va_arg(args, unsigned int);
	str[0] = nb;
	str[1] = '\0';
	s_args->print_char = nb;
	ft_get_len_output(s_args, str);
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_s(t_spec *s_args, char *str)
{
	ft_get_len_output(s_args, str);
	ft_put_output(s_args, str, 0);
}

void	ft_get_arg_s_va_list(t_spec *s_args, va_list args)
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
}

void	ft_get_arg_p(t_spec *s_args, va_list args)
{
	char	*s;
	char	str[500];

	s = (char *)va_arg(args, char*);
	ft_get_p_str(&s, str);
	ft_get_len_output(s_args, str);
	ft_put_output(s_args, str, 0);
}