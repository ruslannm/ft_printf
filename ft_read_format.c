/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:02 by rgero             #+#    #+#             */
/*   Updated: 2019/11/27 15:15:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(char *s, t_spec *s_args, int start)
{
	int		i;

	i = 0;
	if (s[i] && ft_parse_position(s, s_args, &i) == -1)
		return (-1);
	if (s[i] && ft_parse_flags(s, s_args, &i) == -1)
		return (-1);
	if (s[i] != '\0')
		ft_parse_width(s, s_args, &i);
	if (s[i] != '\0')
		ft_parse_precision(s, s_args, &i);
	if (s[i] && ft_parse_modifier(s, s_args, &i) == -1)
		return (-1);
	if (s[i] && ft_parse_conversion(s, s_args, &i) == -1)
		return (-1);
	s_args->len = i;
	if (ft_check_format(s_args) == -1)
		return (-1);
	return (start + i);
}

t_spec	*ft_new_spec(int start)
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
	ret->conversion = 0;
	ret->start = start;
	ret->len = 0;
	ret->type = NULL;
	ret->output = NULL;
	return (ret);
}

t_spec **ft_ini_s_args(char *s)
{
	int	count_args;
	int i;
	t_spec	**ret;

	count_args = 0;
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == '%' && s[i + 1] && s[i + 1] != '%')
					count_args++;
	if (!(ret = (t_spec**)malloc(sizeof(t_spec*) * (count_args + 1))))
		return (NULL);
	ret[count_args] = NULL;
	return (ret);
}


int	ft_read_format(char *s, t_spec ***s_args)
{
	int	i;
	int j;

	if (!(*s_args = ft_ini_s_args(s)))
		return (-1);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] && s[i + 1] != '%')
		{
			if (!(*s_args[j] = ft_new_spec(i)))
				return (-1);
			if ((i = ft_parse_format(&s[i + 1], *s_args[j++], i)) < 0) 
				return (-1);
		}
		else if (s[i] == '%' && s[i + 1] && s[i + 1] == '%')
			i++;
	}
	//ft_check_format(s_args);
	if (ft_check_position(*s_args))
		return (-1);
	return (0);
}