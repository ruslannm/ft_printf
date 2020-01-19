/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:00:47 by rgero             #+#    #+#             */
/*   Updated: 2019/12/06 16:49:03 by rgero            ###   ########.fr       */
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

void	ft_fix_precision(t_spec *s_args)
{
	if (s_args->conversion == 'f')
	{
		if  (s_args->precision_ini && !s_args->precision)
			s_args->flags[1] = 0;
	}
	else if (s_args->precision_ini)
		s_args->flags[1] = 0;
}

int	ft_check_format(t_spec *s_args)
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

int		ft_check_position(t_spec **s_args)
{
	int	position;
	int asterisk;
	int i;

	position = 0;
	asterisk = 0;
	i = 0;
	while (s_args[i])
	{
		if (s_args[i]->position)
			position++;
		if (s_args[i]->width_ini == -1 || s_args[i]->precision_ini == -1)
			asterisk++;
		i++;
	}
	if (position && asterisk)
		return (-1);
	if (position && position != i)
		return (-1);
	return (0);
}