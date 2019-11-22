/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:00:47 by rgero             #+#    #+#             */
/*   Updated: 2019/11/22 15:48:03 by rgero            ###   ########.fr       */
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
			if (s_args->position || s_args->modifier)
				ret = -1;
		}
		else 
			ret = (s_args->modifier ? -1 : 0);
	}
	return (ret);
}