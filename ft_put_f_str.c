/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_f_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/17 18:03:52 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_swap(char **s, int i, int j)
{
	int c_tmp;
	char *s_tmp;

	s_tmp = *s;
	c_tmp = s_tmp[i];
	s_tmp[i] = s_tmp[j];
	s_tmp[j] = c_tmp;
}

int	ft_put_binary_str(unsigned int n, char **s)
{
	int 	i;
	char	*tmp;

	i = ft_nbr_len(n, 2);
	if (!(tmp = ft_strnew(i + 1)))
		return (-1);
	tmp[i] = '\0';
	while (--i >= 0)
	{
		tmp[i] = n % 2 + '0';
		n = n / 2;
	}
	*s = tmp;
	return (0);
}


int	ft_put_f_str(float n, t_spec *s_args)
{
	union u_double	u_d;
	int	power;
	char	*m;
	char	*tmp_m;
	int i;

	m = NULL;
	u_d = (union u_double)n;
	power = u_d.f_parts.e - 127;
	ft_put_binary_str(u_d.f_parts.m, &m);
	tmp_m = ft_strnew(23 + 3);
	ft_strcpy(tmp_m, "1.");
	i = ft_strlen(m);
	while (i < 23)
		tmp_m[24 - i++] = '0';
	ft_strcpy(&tmp_m[25 - i], m);
	i = 0;
	while (++i <= power)
		ft_swap(&tmp_m, i, i + 1);
	s_args->output_raw = ft_strnew(1);
/*	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	i = i + (s_args->flags[5] == 39 ? THOUSAND_SEP_LEN * (i / 3 ) : 0);
	if (!(s_args->output_raw = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s_args->output_raw[i] = '\0';
	j = 0;
	while (--i >= 0)
	{
		if (j++ % 3 == 0 && j > 2 && s_args->flags[5] == 39 && THOUSAND_SEP_LEN > 0)
		{
			ft_strncpy(&s_args->output_raw[i + 1 - THOUSAND_SEP_LEN], THOUSAND_SEP, THOUSAND_SEP_LEN);
			i = i - THOUSAND_SEP_LEN;
		}
		s_args->output_raw[i] = n % 10 + '0';
		n = n / 10;
	}
	*/
	return (0);
}
