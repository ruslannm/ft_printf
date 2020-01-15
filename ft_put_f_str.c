/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_f_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/15 18:07:14 by rgero            ###   ########.fr       */
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
		if (j < i)   // if (j <= i)  
			tmp[j] = n % 2 + '0';
		n = n / 2;
	}
	*s = tmp;
	return (0);
}

void	ft_get_len_output_f(t_spec *s_args)
{
	char	*pointer;
	int	len[8];

	len[5] = ft_strlen(s_args->output_raw);
	if (!(pointer = ft_strchr(s_args->output_raw, '.')))
		len[0] = len[5];
	else 
		len[0] = pointer - s_args->output_raw;  // integer part
	len[6] = len[5] - len[0]; //decimal part includes point
	len[7] = 0; //tmp
	if (s_args->precision_ini && !s_args->precision)
		len[1] = (s_args->flags[0] ? 1 : 0);
	else
	{	
		len[1] = len[6];
		if (s_args->precision_ini && s_args->precision < 7)
			len[1] = (len[6] > s_args->precision + 1 ? s_args->precision + 1 : len[6]);
		else if (len[6] < s_args->precision + 1)
			len[7] = s_args->precision + 1 - len[6];
		/*
		if (len[6] > s_args->precision)
			len[1] = s_args->precision;
		else
			len[1] = len[6]		
			*/
	}
	if (s_args->sign != '\0')
		len[2] = 1;
	else
		len[2] = 0;
	len[3] = (len[0] + len[1] + len[2] + len[7] < s_args->width ? s_args->width : len[0] + len[1] + len[2] + len[7]);
	s_args->output_len[0] = len[0];
	s_args->output_len[1] = len[1];
	s_args->output_len[2] = len[2];
	s_args->output_len[3] = len[3];
	s_args->output_len[4] = 0;
	s_args->output_len[5] = len[7];
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
		while (len[4] < len[3] - len[0] - len[1] - len[2])
			tmp[len[4]++] = '0';
	}
	if (s_args->flags[2] == 0)
		while (len[4] < len[3] - len[0] - len[1] - len[2])
			tmp[len[4]++] = ' ';
	if (len[2])
		tmp[len[4]++] = s_args->sign;
	//while (len[1]-- - len[0] > 0)
	//	tmp[len[4]++] = '0';
	ft_strncpy(&tmp[len[4]], s_args->output_raw, len[0]);
	len[4] += len[0];
	ft_strncpy(&tmp[len[4]], &s_args->output_raw[len[0]], len[1]);
	len[4] += len[1];
	while (len[5]--)
		tmp[len[4]++] = '0';
	if (s_args->flags[2] != 0)
		while (len[4] < len[3])
			tmp[len[4]++] = ' ';
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

int	ft_roundup_diff(char **str, int presision)
{
	char	*ret;
	
	if (!(ret = ft_strnew(presision + 2)))
		return (-1);
	ft_strcpy(ret, "0.");
	ret[2 + --presision] = '1';
	while(presision-- > 0)
		ret[2 + presision] = '0';
	*str = ret;
	return (1);
}

int	ft_add_precision(char **str, t_spec *s_args)
{
	int		add_presision;
	int		len[3];
	char	*tmp;
	char	*pointer;
	char	*ret;

	tmp = *str;
	len[2]  = ft_strlen(tmp);
	pointer = ft_strchr(tmp, '.');
	len[0] = pointer - tmp;
	len[1] = len[2] - len[0] - 1;
	add_presision = s_args->precision - len[1];
	if (add_presision > 0)
	{
		if (!(ret = ft_strnew(add_presision + len[2])))
			return (-1);
		ft_strcpy(ret, tmp);
		while (add_presision)
			ret[len[2] + --add_presision] = '0';
		*str = ret;
	}
	return (0);
}

int	ft_roundup(char **str, t_spec *s_args)
{
	int		presision;
	int		len[3];
	char	*tmp;
	char	*pointer;
	char	*round_diff;

	tmp = *str;
	len[2]  = ft_strlen(tmp);
	pointer = ft_strchr(tmp, '.');
	len[0] = pointer - tmp;
	len[1] = len[2] - len[0] - 1;
	presision = s_args->precision;
	if (presision < len[1])
	{
		if (ft_strchr("56789", pointer[1 + presision]))
		{
			if (ft_roundup_diff(&round_diff, presision) == -1)
				return (-1);
			pointer = ft_sum_decimal_place(tmp, round_diff, 10);
			free (tmp);
			*str = pointer;
		}
		pointer[1 + presision] = '\0';
	}
	return (0);
//	ft_add_precision(char &str, s_args);
//	return (ft_add_precision(&str, s_args) == 0 ? 0 : -1);
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
	if (u_d.f_parts.s)
		s_args->sign = '-';
	if (power == 128)
	{
		if (u_d.f_parts.m == 0)
			s_args->output_raw = ft_strdup("inf");
		else
		{
			s_args->output_raw = ft_strdup("nan");
			s_args->flags[3] = 0;
			s_args->flags[4] = 0;
			s_args->sign = 0;
		}
		s_args->precision = 0;
		s_args->precision_ini = 1;
		s_args->flags[0] = 0;
		s_args->flags[1] = 0;

		return (0);
	}
	ft_put_binary_str(u_d.f_parts.m, &m);
	tmp_m = ft_strnew(23 + 2);
	ft_strcpy(tmp_m, "1.");
	i = ft_strlen(m);
	while (i < 23)
		tmp_m[24 - i++] = '0';
	ft_strcpy(&tmp_m[1 + i], m); 
	//ft_strcpy(&tmp_m[25 - i], m); //
	i = 0;
	//while (++i <= power)
	//	ft_swap(&tmp_m, i, i + 1);
	ft_shift(&tmp_m, power);
	free(m);
	m = ft_conv_binary(tmp_m);
	ft_roundup(&m, s_args);
	ft_add_precision(&m, s_args);
	s_args->output_raw = m;

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
