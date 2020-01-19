/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2020/01/12 11:12:15 by rgero            ###   ########.fr       */
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

char	*ft_get_str(char *s, t_spec **s_args)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = ft_strnew(0);
	while (s[++i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] && s[i + 1] != '%')
			{
			/*
				write(1, s_args[j]->output, ft_strlen(s_args[j]->output));
				i = i + s_args[j]->len;
				j++;
				*/
				if (s_args[j]->output)
					tmp = ft_strjoin(ret, s_args[j]->output);
				else
					tmp = ft_strdup(ret);				
				free(ret);
				ret = tmp;
				i = i + s_args[j++]->len;
			}			
		else
			{
				if (s[i] == '%')
					i++;
				tmp = ft_strcjoin(ret, s[i]);
				free(ret);
				ret = tmp;
			}
	}
	return (ret);
}

int	ft_get_width_diff(t_spec **s_args)
{
	int	ret;
	int		j;

	ret = 0;
	j = 0;
	while (s_args[j])
	{
		if (s_args[j]->width_diff)
			ret++;
		j++;
	}
	return (ret);
}

int ft_printf(const char *format, ...)
{
	int 	ret;
	va_list args;
	t_spec	*s_args;

	va_start(args, format);
	ret = 0;
	s_args = NULL;
	if (-1 == ft_new_spec(&s_args, (char*)format, 0, 0))
		return (-1);
	ret = ft_parse(s_args, args);
	return (ret);

/*	if ((s_args = ft_read_format((char *)format)))
		ret = ft_read_args(s_args, args);
	if (!ret)
	{
		output = ft_get_str((char*)format, s_args);
		ft_putstr(output);
		ret = ft_strlen(output) + ft_get_width_diff(s_args); //printf_len((char*)format, s_args);
	}
	else
		ret = -1;
	return (ret);	
	*/
}



/*
int ft_printf(const char *format, ...)
{
	int 	ret;
	va_list args;
	t_spec	**s_args;
	char	*output;

	va_start(args, format);
	ret = -1;
	if ((s_args = ft_read_format((char *)format)))
		ret = ft_read_args(s_args, args);
	if (!ret)
	{
		output = ft_get_str((char*)format, s_args);
		ft_putstr(output);
		ret = ft_strlen(output) + ft_get_width_diff(s_args); //printf_len((char*)format, s_args);
	}
	else
		ret = -1;
	return (ret);	
}
*/