/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:04 by rgero             #+#    #+#             */
/*   Updated: 2020/01/14 17:50:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_position(char *s, t_spec *s_args, int *i)
{
	int	position;
	int j;
	
	j = *i;
	if (ft_isdigit(s[j]))
	{
		position = ft_atoi(&s[j]);
		while (ft_isdigit(s[j]))
			j++;
		if (s[j] != '$')
			return (-1);
		s_args->position = position;
		*i = j + 1;
	}
	return (0);
}

void	ft_put_flag(t_spec *s_args, char c)
{
	if (c == '#')
		s_args->flags[0] = c;
	else if (c == '0' && s_args->flags[2] == 0)
		s_args->flags[1] = c;
	else if (c == '-')
	{
		s_args->flags[2] = c;
		s_args->flags[1] = 0;
	}
	else if (c == ' ' && s_args->flags[4] == 0)
		s_args->flags[3] = c;
	else if (c == '+')
	{
		s_args->flags[4] = c;
		s_args->flags[3] = 0;
	}
	else if (c == 39)
		s_args->flags[5] = c;
}

int	ft_parse_flags(char *s, t_spec *s_args, int *i)
{
	int		ret;
	int		j;

	j = *i;
	ret = 0;
	while (ft_strchr("#0- +'", s[j]))
		ft_put_flag(s_args, s[j++]);
	*i  = j;
	return (ret);
}

int	ft_parse_width(char *s, t_spec *s_args, int *i)
{
	if (ft_isdigit(s[*i]))
	{
		s_args->width = ft_atoi(&s[*i]);
		s_args->width_ini = 1;
		while (ft_isdigit(s[*i]))
			*i = *i + 1;
	}
	else if (s[*i] == '*')
	{
		s_args->width_ini = -1;
		*i = *i + 1;
	}
	if (!s_args->width_ini && s_args->flags[1])
		s_args->flags[1] = 0;
	return (0);
}

int	ft_parse_precision(char *s, t_spec *s_args, int *i)
{
	if (s[*i] == '.')
	{
		*i = *i + 1;
		if (ft_isdigit(s[*i]))
		{
			s_args->precision = ft_atoi(&s[*i]);
			s_args->precision_ini = 1;
			while (ft_isdigit(s[*i]))
				*i = *i + 1;
		}
		else if (s[*i] == '*')
		{
			s_args->precision_ini = -1;
			*i = *i + 1;
		}
		else 
		{
			s_args->precision = 0;
			s_args->precision_ini = 1;
		}	
	}
	return (0);
}