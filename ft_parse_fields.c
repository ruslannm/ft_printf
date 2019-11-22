/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:04 by rgero             #+#    #+#             */
/*   Updated: 2019/11/22 15:21:17 by rgero            ###   ########.fr       */
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

int	ft_parse_flags(char *s, t_spec *s_args, int *i)
{
	int		ret;
	char	*tmp;
	int		j;

	j = 0;
	ret = 0;
	if (!(tmp = ft_strnew(6)))
		ret = -1;
	else
	{
		while (ft_strchr("#0- +'", s[*i]) && !ft_strchr(tmp, s[*i]))
		{
			tmp[j++] = s[*i];
			*i = *i + 1;
		}
		if (tmp[0] != '\0')
			if (!(s_args->flags = ft_strdup(tmp)))
				ret = -1;
	}
	ft_strdel(&tmp);
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
	return (0);
}

int	ft_parse_precision(char *s, t_spec *s_args, int *i)
{
	if (s[*i] == '.')
	{
		*i = *i + 1;
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
		else 
			return (-1);
	}
	return (0);
}