/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:09:45 by rgero             #+#    #+#             */
/*   Updated: 2019/11/21 18:43:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_modifier_check_memory(char *s, int i)
{
	if (s[i])
	{
		if (!ft_strncmp(&s[i], "hh", 2))
			return (1);
		else if (!ft_strncmp(&s[i], "ll", 2))
			return (1);
		else if (s[i] == 'h')
			return (1);
		else if (s[i] == 'l')
			return (1);
		else if (s[i] == 'L')
			return (1);
	}
	return (0);
}

int	ft_parse_modifier(char *s, t_spec *s_args, int *i)
{
	if (!ft_strncmp(&s[*i], "hh", 2))
		s_args->modifier = ft_strdup("hh");
	else if (!ft_strncmp(&s[*i], "ll", 2))
		s_args->modifier = ft_strdup("ll");
	else if (s[*i] == 'h')
		s_args->modifier = ft_strdup("h");
	else if (s[*i] == 'l')
		s_args->modifier = ft_strdup("l");
	else if (s[*i] == 'L')
		s_args->modifier = ft_strdup("L");
	if (s_args->modifier)
		*i = *i + ft_strlen(s_args->modifier);
	else if (ft_parse_modifier_check_memory(s, *i))
		return (-1);	
	return (0);
}

int	ft_parse_conversion(char *s, t_spec *s_args, int *i)
{
	char *conversion;

	if (!(conversion = ft_strdup("cspdiouxX")))
		return (-1);
	if (ft_strchr(conversion, s[*i]))
	{
		s_args->conversion = s[*i];
		*i = *i + 1;
	}
	return (0);
}
