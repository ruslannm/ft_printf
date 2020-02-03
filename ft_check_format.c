/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:00:47 by rgero             #+#    #+#             */
/*   Updated: 2020/02/03 14:43:24 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_modifier_int(char modifier)
{
	if (!modifier)
		return (0);
	if (ft_strchr("12hl", modifier))
		return (0);
	return (-1);
}

static int	ft_check_modifier_float(char modifier)
{
	if (!modifier)
		return (0);
	if (ft_strchr("lL", modifier))
		return (0);
	return (-1);
}

void		ft_fix_precision(t_spec *s_args)
{
	if (s_args->conversion == 'f')
	{
		if (s_args->precision_ini && !s_args->precision)
			s_args->flags[1] = 0;
	}
	else if (s_args->precision_ini)
		s_args->flags[1] = 0;
}

int			ft_check_format(t_spec *s_args)
{
	int	ret;

	ret = 0;
	if (!s_args->conversion)
		return (-1);
	ft_fix_precision(s_args);
	if (ft_strchr("dinouxX", s_args->conversion))
		ret = ft_check_modifier_int(s_args->modifier);
	else if (ft_strchr("feg", s_args->conversion))
		ret = ft_check_modifier_float(s_args->modifier);
	else
	{
		if (s_args->conversion == 'c')
		{
			if (s_args->precision || s_args->modifier)
				ret = -1;
		}
		else
			ret = (s_args->modifier ? -1 : 0);
	}
	return (ret);
}
