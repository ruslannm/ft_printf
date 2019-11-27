/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2019/11/27 15:11:09 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
/*


int		ft_width(char **s)
{
	int	ret;

   	ret = 0;
	if (ft_isdigit(*(*s)))
	{
		ret = ft_atoi(*s);
		if (ret > 0)
			while (ft_isdigit(*(*s)))
				(*s)++;
	}
	return (ret);
}

int		ft_precision(char **s)
{
	int	ret;

	ret = -1;
	if (*(*s) == '.' && ft_isdigit(*(*s + 1)))
	{
		(*s)++;
		ret = ft_atoi(*s);
		if (ret > 0)
			while (ft_isdigit(*(*s)))
				(*s)++;
	}
	return (ret);
}



char	ft_modifier(char **s)
{
	char	ret;

	ret = 0;
	if (*(*s) == 'h' && *(*(s + 1)) == 'h')
		ret =  'H';
	else if (*(*s) == 'l' && *(*s + 1) == 'l')
		ret = '1';
	else if (*(*s) == 'h' || *(*s) == 'l' || *(*s) == 'L')
		ret = *(*s);
	if (ret == 'H' || ret == '1')
		*s = *s + 2;
	else if (ret > 0)	
			(*s)++;
	return (ret);
}

char	ft_conversion(char **s)
{
	char	ret;
	char *conversion;

	ret = 0;
	conversion = ft_strdup("cspdiouxXf");
	if (ft_strchr(conversion, *(*s)))
	{
		ret = *(*s);
		(*s)++;
	}
	free(conversion);
	return (ret);
}

void	ft_factor(t_spec *spec)
{
	if (spec->conversion == 'c')
		spec->type = strdup("char");
	else if (spec->conversion == 's')
		spec->type = strdup("char*");
	else if (spec->conversion == 'i')
		spec->type = strdup("int");
}

t_spec *ft_specification(char **s)
{
	t_spec	*ret;

	if (!(ret = (t_spec *)malloc(sizeof(t_spec))))
		return (NULL);
	(*s)++;
	ret->flag = ft_flag(s);
	ret->width = ft_width(s);
	ret->precision = ft_precision(s);
	ret->modifier = ft_modifier(s);
	ret->conversion = ft_conversion(s);
	ft_factor(ret);
	return (ret);
}
*/
int ft_printf(const char *format, ...)
{
	int 	i;
	int		j;
	int 	ret;
	va_list args;
	t_spec	**s_args;

	va_start(args, format);
	s_args = NULL;
	ret = ft_read_format((char *)format, &s_args);
	if (!ret)
		ret = ft_read_args(s_args, args);
	i = -1;
	j = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] && format[i + 1] != '%')
			{
				write(1, s_args[j]->output, ft_strlen(s_args[j]->output));
				i = i + s_args[j]->len;
				j++;
			}			
		else
			write(1, &format[i], 1);
	}
	if (!ret)
		ret = ft_printf_len((char*)format, s_args);
	else
		ret = -1;
	return (ret);	
}