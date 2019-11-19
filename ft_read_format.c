/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:02 by rgero             #+#    #+#             */
/*   Updated: 2019/11/18 17:35:19 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(char *s, t_spec *param, int count_params)
{
	int		i;
	int 	ret;
	int 	param;
	char	*flags;

	i = -1;
	while(s[++i] != '\0')
	{
//number param
		if (ft_isdigit(s[i]))
		{
			param = ft_atoi(&s[i]);
			while (ft_isdigit(s[i]))
				i++;
			if (s[i] != '$')
				return (-1);
			i++;
		}
//flags
	flags = ft_strdup("#0- +'");
	while (ft_strchr(flags, s[i]))
		i++;
//width
	while()
		if (ft_isdigit(s[i]))
		{
			param = ft_atoi(&s[i]);
			while (ft_isdigit(s[i]))
				i++;


	}

}


int	ft_read_format(char *s, t_spec *params, int count_params)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] && s[i + 1] != '%')
		{
			if ((i = ft_parse_format(&s[i + 1], params, count_params) < 0) 
				return (-1);
		}
		else if (s[i] == '%' && s[i + 1] && s[i + 1] == '%')
			i++;
	}
}