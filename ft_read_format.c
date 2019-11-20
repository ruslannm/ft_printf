/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:02 by rgero             #+#    #+#             */
/*   Updated: 2019/11/20 18:01:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(char *s, t_spec *s_args)
{
	int		i;
//	int 	j;
//	int 	ret;
	//int 	param;
//	char	*flags;
//	char	*tmp;

	i = -1;
	while(s[++i] != '\0')
	{
		if (ft_parse_position(s, s_args, &i) == -1)
			return (-1);
		if (ft_parse_flags(s, s_args, &i) == -1)
			return (-1);
	/*		flags = ft_strdup("#0- +'");
		tmp = ft_strnew(6);
		j = 0;
		while (ft_strchr(flags, s[i]))
			tmp[j++] = s[i++];
		s_args->flags = ft_strdup(tmp);
		free (tmp);
		if (ft_isdigit(s[i]))
		{
			s_args->width = ft_atoi(&s[i]);
			s_args->width_ini = 1;
			while (ft_isdigit(s[i]))
				i++;
		}
		else if (s[i] == '\*')
		{
			s_args->width_ini = -1;
			i++;
		}
		if (s[i] == '.')
		{
			i++;
			if (ft_isdigit(s[i]))
			{
				s_args->precision = ft_atoi(&s[i]);
				s_args->precision_ini = 1;
				while (ft_isdigit(s[i]))
					i++;
			}
			else if (s[i] == '\*')
			{
				s_args->precision_ini = -1;
				i++;
			}
		}
		*/
	}
	return (1);
}

t_spec	*ft_new_spec()
{
	t_spec	*ret;

	if (!(ret = (t_spec*)malloc(sizeof(t_spec))))
		return (NULL);
	ret->position = 0;
	ret->flags = NULL;
	ret->width_ini = 0;
	ret->width = 0;
	ret->precision_ini = 0;
	ret->precision = 0;
	ret->modifier = NULL;
	ret->conversion = NULL;
	ret->type = NULL;
	return (ret);
}


int	ft_read_format(char *s, t_spec **s_args)
{
	int	i;
	int j;

	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] && s[i + 1] != '%')
		{
			if (!(s_args[j] = ft_new_spec()))
				return (-1);
			if ((i = ft_parse_format(&s[i + 1], s_args[j++])) < 0) 
				return (-1);
		}
		else if (s[i] == '%' && s[i + 1] && s[i + 1] == '%')
			i++;
	}
	return (1);
}