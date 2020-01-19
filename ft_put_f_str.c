/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_f_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/16 16:45:07 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mantissa_len(unsigned long int n, int base)
{
	int i;

	i = 1;
	while (n / base > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}


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

int	*ft_float_len(char *str)
{
	char	*point;
	int		*len;

	if (!(len = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	len[0] = ft_strlen(str);
	if (!(point = ft_strchr(str, '.')))
	{
		len[1] = len[0];
		len[2] = 0;
	}
	else
	{
		len[1] = point - str;
		len[2] = len[0] - len[1] - 1;
	}
	len[3] = 0;
	len[4] = 0;
	return (len);
}

int	ft_shift(char **s, int i)
{
	char *s_tmp;
	char *s_new;
	int *len;

	s_tmp = *s;
	len = ft_float_len(s_tmp);
	if (i > 0)
	{
		len[3] = len[0] + (i > len[2] ? i - len[2] : 0); 
		if (!(s_new = ft_strnew(len[3])))
			return (-1);
		ft_strncpy(s_new, s_tmp, len[1]);
		if (i > len[2])
		{
			ft_strncpy(&s_new[1], &s_tmp[2], len[2]);
			s_new[--len[3]] = '.';
			while (i-- > len[2])
				s_new[--len[3]] = '0';
		}
		else
		{
			ft_strncpy(&s_new[len[1]], &s_tmp[len[1] + 1], i);
			s_new[i + len[1]] = '.';
			ft_strncpy(&s_new[i + len[1] + 1], &s_tmp[i + len[1] + 1], len[2] - i);
		}
		free(*s);
		*s = s_new;
	}
	else if (i < 0)
	{
		len[3] = len[0] + (-i >= len[1]? - i - len[1] + 1 : 0); 
		if (!(s_new = ft_strnew(len[3])))
			return (-1);
		//ft_strncpy(s_new, s_tmp, len[1]);
		if (-i >= len[1])
		{
			ft_strncpy(s_new, "0.", 2);
			ft_strncpy(&s_new[2 - i - len[1]], s_tmp, len[1]);
			ft_strncpy(&s_new[2 - i], &s_tmp[len[1] + 1], len[2]);
			while (len[1] + i++ < 0)
				s_new[2 - i - len[1]] = '0';
		}
		else
		{
			ft_strncpy(s_new, s_tmp, len[1] + i);
			s_new[i + len[1]] = '.';
			ft_strncpy(&s_new[i + len[1] + 1], &s_tmp[i + len[1]], - i);
			ft_strncpy(&s_new[len[1] + 1], &s_tmp[len[1] + 1], len[2]);
		}
		free(*s);
		*s = s_new;
	}
	return (0);
}


int	ft_put_binary_str(unsigned long int n, char **s)
{
	int		j;
	char	*tmp;
	char	c;

	if (!(tmp = ft_strnew(64)))
		return (-1);
	j = 0;
	while (n > 0)
	{
		tmp[j++] = n % 2 + '0';
		n = n / 2;
		//j--;
	}
	while (j < 64)
		tmp[j++] = '0';
	while(j-- > 32)
	{
		c = tmp[j];
		tmp[j] = tmp[63 - j];
		tmp[63 - j] = c;
	}
	ft_shift(&tmp, -63);
	*s = tmp;
	return (0);
}

void	ft_get_len_output_f(t_spec *s_args, char *str)
{
	char	*pointer;
	int	len[8];

	len[5] = ft_strlen(str);
	if (!(pointer = ft_strchr(str, '.')))
		len[0] = len[5];
	else 
		len[0] = pointer - str;  // integer part
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

int	ft_put_output_f(t_spec *s_args, char *str)
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
	ft_putstr_fd(str, s_args->fd);
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
	int		*len;
	char	*tmp;
	char	*ret;
	char	*round_diff;

	tmp = *str;
	len = ft_float_len(tmp);
	presision = s_args->precision;
	if (presision < len[2])
	{
		if (ft_strchr("56789", tmp[len[1] + 1 + presision]))
		{
			round_diff = NULL;
			if (ft_roundup_diff(&round_diff, presision) == -1)
				return (-1);
			ret = ft_sum_float(tmp, round_diff, 10);
			free (tmp);
			*str = ret;
		}
		ret[len[1] + 1 + presision] = '\0';
	}
	return (0);
//	ft_add_precision(char &str, s_args);
//	return (ft_add_precision(&str, s_args) == 0 ? 0 : -1);
}

char	*ft_get_f_str(long double n, t_spec *s_args)
{
	union u_double	u_d;
	int	power;
	char	*m;

	m = NULL;
	u_d = (union u_double)n;
	if (u_d.f_parts.e == 0 && u_d.f_parts.m == 0)
	{
		if (u_d.f_parts.s)
			s_args->sign = '-';
		s_args->output_raw = ft_strdup("0.000000");
		s_args->flags[0] = 0;
		s_args->flags[1] = 0;
		return (0);
	}
	power = u_d.f_parts.e - 16383;//1023;//127;
	if (u_d.f_parts.s)
		s_args->sign = '-';
	if (power == 16383)//1024) //128)
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
	ft_shift(&m, power);
	ft_conv_bin2dec(&m);
	ft_roundup(&m, s_args);
	ft_add_precision(&m, s_args);
	return (m);
}
