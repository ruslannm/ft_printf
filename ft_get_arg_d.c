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

int ft_get_arg_d(t_spec *s_args, va_list args)
{
	int 		ret;
	intmax_t	nb;
	char		*str;

	ret = 0;
	if (!s_args->modifier)
		nb = (int)va_arg(args, int);
	else if ('h' == s_args->modifier)
		nb = (short)va_arg(args, int);
	else if ('1' == s_args->modifier)
		nb = (signed char)va_arg(args, int);
	else if ('l' == s_args->modifier)
		nb = (long)va_arg(args, long int);
	else if ('2' == s_args->modifier)
		nb = (long long)va_arg(args, long long int);
	else
		nb = (int)va_arg(args, int);
	s_args->sign = (nb < 0 ? '-' : 0);
	if (nb == -9223372036854775807 - 1)
		str = ft_get_u_str(9223372036854775808U, s_args);
	else
		str = ft_get_di_str(nb, s_args);
	ft_set_sign(s_args);
	ft_get_len_output(s_args, str);
	ret = (!ret ? ft_put_output(s_args, str) : ret);
	return (ret);	
}

int	ft_get_arg_u(t_spec *s_args, va_list args)
{
	int			ret;
	uintmax_t	nb;
	char		*str;

	ret = 0;
	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if ('h' == s_args->modifier)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if ('1' == s_args->modifier)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if ('l' == s_args->modifier)
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if ('2' == s_args->modifier)
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	str = ft_get_u_str(nb, s_args);
	ft_get_len_output(s_args, str);
	ret = (!ret ? ft_put_output(s_args, str) : ret);
	return (ret);	
}

int	ft_get_arg_oxX(t_spec *s_args, va_list args)
{
	int			ret;
	uintmax_t	nb;
	char		*str;
	
	ret = 0;
	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if ('h' == s_args->modifier)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if ('1' == s_args->modifier)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if ('l' == s_args->modifier)
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if ('2' == s_args->modifier)
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	if (s_args->conversion == 'o')
		str = ft_get_o_str(nb, s_args);
	else
		str = ft_get_xX_str(nb, s_args);
	ft_get_len_output(s_args, str);
	ret = (!ret ? ft_put_output_xX(s_args, str) : ret);
	return (ret);	
}

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
	ret = ft_put_output_xX(s_args, str);
	return (ret);	
}