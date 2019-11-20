/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:04 by rgero             #+#    #+#             */
/*   Updated: 2019/11/20 17:58:05 by rgero            ###   ########.fr       */
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
	char	*flags;
	char	ret;
	char	*tmp;
	int		j;

	ret = 0;
	j = 0;
	flags = ft_strdup("#0- +'");
	tmp = ft_strnew(6);
	if (!flags || !tmp)
		ret = -1;
	else
	{
		while (ft_strchr(flags, s[*i]) && !ft_strchr(tmp, s[*i]))
		{
			tmp[j++] = s[*i];
			*i = *i + 1;
		}
		if (tmp[0] != '\0')
			if (!(s_args->flags = ft_strdup(tmp)))
				ret = -1;
	}
	ft_strdel(&flags);
	ft_strdel(&tmp);
	return (ret);
}