/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:29:09 by rgero             #+#    #+#             */
/*   Updated: 2019/12/06 18:04:40 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_get_arg_d(t_spec *s_args, va_list args)
{
	int 		ret;
	intmax_t	nb;

	if (!s_args->modifier)
		nb = (int)va_arg(args, int);
	else if (!ft_strcmp(s_args->modifier, "h"))
		nb = (short)va_arg(args, int);
	else if (!ft_strcmp(s_args->modifier, "hh"))
		nb = (signed char)va_arg(args, int);
	else if (!ft_strcmp(s_args->modifier, "l"))
		nb = (long)va_arg(args, long int);
	else if (!ft_strcmp(s_args->modifier, "ll"))
		nb = (long long)va_arg(args, long long int);
	else
		nb = (int)va_arg(args, int);
	s_args->sign = (nb < 0 ? '-' : 0);
	if (nb == -9223372036854775807 - 1)
		ret = ft_put_u_str(9223372036854775808U, s_args);
	else
		ret = ft_put_di_str(nb, s_args);
	ft_putsign(s_args);
	ft_get_len_output(s_args);
	ret = (!ret ? ft_putoutput(s_args) : ret);
	return (ret);	
}

int	ft_get_arg_u(t_spec *s_args, va_list args)
{
	int			ret;
	uintmax_t	nb;

	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "h"))
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "hh"))
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "l"))
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if (!ft_strcmp(s_args->modifier, "ll"))
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	ret = ft_put_u_str(nb, s_args);
	ft_get_len_output(s_args);
	ret = (!ret ? ft_putoutput(s_args) : ret);
	return (ret);	
}

int	ft_get_arg_oxX(t_spec *s_args, va_list args)
{
	int			ret;
	uintmax_t	nb;

	if (!s_args->modifier)
		nb = (unsigned int)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "h"))
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "hh"))
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (!ft_strcmp(s_args->modifier, "l"))
		nb = (unsigned long)va_arg(args, unsigned long int);
	else if (!ft_strcmp(s_args->modifier, "ll"))
		nb = (unsigned long long)va_arg(args, unsigned long long int);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	ret = ft_put_oxX_str(nb, s_args);
	ft_get_len_output(s_args);
	ret = (!ret ? ft_putoutput_xX(s_args) : ret);
	return (ret);	
}

int	ft_get_arg_c(t_spec *s_args, va_list args)
{
	int				ret;
	unsigned char	nb;

	nb = (unsigned char)va_arg(args, unsigned int);
	ret = ft_put_c_str(nb, s_args);
	ft_get_len_output(s_args);
	ret = (!ret ? ft_putoutput(s_args) : ret);
	return (ret);	
}

int	ft_get_arg_s(t_spec *s_args, va_list args)
{
	int		ret;
	char	*s;

	s = (char *)va_arg(args, char*);
	ret = ft_put_s_str(s, s_args);
	ft_get_len_output(s_args);
	ret = (!ret ? ft_putoutput(s_args) : ret);
	return (ret);	
}

int	ft_get_arg_p(t_spec *s_args, va_list args)
{
	int		ret;
	char	*s;

	s = (char *)va_arg(args, char*);
	ret = ft_put_p_str(s, s_args);
	ft_get_len_output(s_args);
	ret = (!ret ? ft_putoutput_xX(s_args) : ret);
	return (ret);	
}