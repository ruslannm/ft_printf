/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_f_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/13 16:03:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	ft_swap(char **s, int i, int j)
{
	int c_tmp;
	char *s_tmp;

	s_tmp = *s;
	c_tmp = s_tmp[i];
	s_tmp[i] = s_tmp[j];
	s_tmp[j] = c_tmp;
}
*/
int	ft_shift(char **s, int i)
{
	char *s_tmp;
	char *s_new;
	int j;

	s_tmp = *s;
	if (i > 0)
	{
		ft_strncpy(&s_tmp[1], &s_tmp[2], i);
		s_tmp[i + 1] = '.';
	}
	else if (i < 0)
	{
		j = ft_strlen(s_tmp) - i;
		if (!(s_new = ft_strnew(j)))
			return (-1);
		while (j--)
			s_new[j] = '0';
		s_new[1] = '.';
		s_new[1 - i] = '1';
		ft_strcpy(&s_new[2 - i], &s_tmp[2]);
		free(*s);
		*s = s_new;
	}
	return (0);
}


int	ft_put_binary_str(unsigned int n, char **s)
{
	int 	i;
	int		j;
	char	*tmp;

	i = ft_nbr_len(n, 2);
	if (!(tmp = ft_strnew(i)))
		return (-1);
	j = 23;
	while (--j >= 0)
	{
		if (j <= i)
			tmp[j] = n % 2 + '0';
		n = n / 2;
	}
	*s = tmp;
	return (0);
}

void	ft_get_len_output_f(t_spec *s_args)
{
	char	*pointer;
	int	len[7];

	len[5] = ft_strlen(s_args->output_raw);
	pointer = ft_strchr(s_args->output_raw, '.');
	len[0] = pointer - s_args->output_raw;  // integer part
	len[6] = len[5] - len[0] - 1; //decimal part
	if (len[6] > s_args->precision)
		len[1] = s_args->precision;
	len[2] = (s_args->sign ? 1 : 0);
	len[3] = (len[0] + len[1] + 1 < s_args->width ? s_args->width : len[0] + len[1] + 1);
	s_args->output_len[0] = len[0];
	s_args->output_len[1] = len[1];
	s_args->output_len[2] = len[2];
	s_args->output_len[3] = len[3];
	s_args->output_len[4] = 0;
}

int	ft_putoutput_f(t_spec *s_args)
{
	char	*tmp;
	int		*len;

	len = s_args->output_len;
	//if (!(tmp = ft_strnew(s_args->output_len[0] + 1 + s_args->output_len[1])))
	if (!(tmp = ft_strnew(len[3])))
		return (-1);
	
	if (s_args->flags[1])
	{
		if (len[2] == 1)
		{
			tmp[len[4]++] = s_args->sign;
			len[2] = 0;
		}
		while (len[4] < len[3] - len[1] - len[2])
			tmp[len[4]++] = '0';
	}
	if (s_args->flags[2] == 0)
		while (len[4] < len[3] - len[0] - len[1] - len[2] -1)
			tmp[len[4]++] = ' ';
	if (len[2])
		tmp[len[4]++] = s_args->sign;
	//while (len[1]-- - len[0] > 0)
	//	tmp[len[4]++] = '0';
	ft_strncpy(&tmp[len[4]], s_args->output_raw, len[0]);
	len[4] += s_args->output_len[0];
	tmp[len[4]++] = '.';
	ft_strncpy(&tmp[len[4]], &s_args->output_raw[len[0] + 1], len[1]);
	s_args->output = tmp;
	/*
	if (!(s_args->output = ft_strdup(s_args->output_raw)))
		return (-1);
	s_args->output[s_args->output_len[0]] = '\0';
	if (!(s_args->output_dec = ft_strnew(s_args->output_len[1] + 1)))
		return (-1);
	s_args->output_dec[0] = '.';
	ft_strncpy(&s_args->output_dec[1], &s_args->output_raw[s_args->output_len[0] + 1], s_args->output_len[1]);
	*/
	return (0);
}

/*
int	ft_put_f_sep(t_spec *s_args)
{
	char	*pointer;
	int		i;
	int		j;

	if ((pointer = ft_strchr(s_args->output_raw, '.')) && s_args->flags[5] == 39 && THOUSAND_SEP_LEN > 0)
	{
		i = THOUSAND_SEP_LEN * ((pointer - s_args->output_raw) / 3 );
		if (!(s_args->output = (char *)malloc(sizeof(char) * (ft_strlen(s_args->output_raw) + i + 1))))
			return (-1);
		ft_strcpy(&s_args->output[ft_strlen(s_args->output_raw) + i], pointer);
		j = 0;
		i = pointer - s_args->output_raw;
		while (--i >= 0)
		{
			if (j++ % 3 == 0 && j > 2)
			{
				ft_strncpy(&s_args->output_raw[i + 1 - THOUSAND_SEP_LEN], THOUSAND_SEP, THOUSAND_SEP_LEN);
				i = i - THOUSAND_SEP_LEN;
			}
			s_args->output_raw[i] = s_args->output_raw[i + j / 3];
		}
	}
	else if (!(s_args->output = ft_strdup(s_args->output_raw)))
		return (-1);
	return (0);
}
*/

int	ft_roundup(char **str, t_spec *s_args)
{
	int 
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
	//while (++i <= power)
	//	ft_swap(&tmp_m, i, i + 1);
	ft_shift(&tmp_m, power);
	s_args->output_raw = ft_conv_binary(tmp_m);
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
