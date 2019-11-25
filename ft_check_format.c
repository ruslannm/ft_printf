/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:00:47 by rgero             #+#    #+#             */
/*   Updated: 2019/11/25 16:29:02 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_modifier_int(char *modifier)
{
	if (!modifier)
		return (0);
	if (!ft_strcmp("h", modifier))
		return (0);
	if (!ft_strcmp("hh", modifier))
		return (0);
	if (!ft_strcmp("l", modifier))
		return (0);
	if (!ft_strcmp("ll", modifier))
		return (0);
	return (-1);
}

static int	ft_check_modifier_float(char *modifier)
{
	if (!modifier)
		return (0);
	if (!ft_strcmp("l", modifier))
		return (0);
	if (!ft_strcmp("L", modifier))
		return (0);
	return (-1);
}


int	ft_check_format(t_spec *s_args)
{
	int	ret;

	ret = -1;
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

int		ft_check_position(t_spec **s_args, int count_args)
{
	int	position;
	int asterisk;
	int i;

	position = 0;
	asterisk = 0;
	i = 0;
	while (i < count_args)
	{
		if (s_args[i]->position)
			position++;
		if (s_args[i]->width_ini == -1 || s_args[i]->precision_ini == -1)
			asterisk++;
		i++;
	}
	if (position && asterisk)
		return (-1);
	if (position && position != count_args)
		return (-1);
	return (0);
}