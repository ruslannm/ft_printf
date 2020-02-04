/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:46:44 by rgero             #+#    #+#             */
/*   Updated: 2020/02/04 15:51:30 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list args;
	t_spec	*s_args;

	va_start(args, format);
	ret = 0;
	s_args = NULL;
	if (-1 == ft_new_spec(&s_args, 0, 1))
		return (-1);
	ret = ft_parse(s_args, args, (char*)format);
	free(s_args);
	va_end(args);
	return (ret);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		ret;
	va_list args;
	t_spec	*s_args;

	va_start(args, format);
	ret = 0;
	s_args = NULL;
	if (-1 == ft_new_spec(&s_args, 0, fd))
		return (-1);
	ret = ft_parse(s_args, args, (char*)format);
	free(s_args);
	va_end(args);
	return (ret);
}
