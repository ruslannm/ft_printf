/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:04 by rgero             #+#    #+#             */
/*   Updated: 2019/11/20 16:57:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_position(char *s, t_spec *s_args, int *i)
{
	if (ft_isdigit(s[*i]))
	{
		s_args->position = ft_atoi(&s[*i]);
		while (ft_isdigit(s[*i]))
			*i = *i + 1;
		if (s[*i] != '$')
			return (-1);
		*i = *i + 1;
	}
	return (0);
}