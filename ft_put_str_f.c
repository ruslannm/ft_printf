/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/30 18:47:10 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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


int		ft_check_str_zero(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

/*
** 0 - str lenght
** 1 - int length
** 2 - point length
** 3 - dec lenght
*/
/*
void	ft_float_len(char *str, int *len)
{
	char	*point;

	len[0] = ft_strlen(str);
	if (!(point = ft_strchr(str, '.')))
	{
		len[1] = len[0];
		len[2] = 0;
		len[3] = 0;
	}
	else
	{
		len[1] = point - str;
		len[2] = 1;
 		len[3] = len[0] - len[1] - len[2];
	}
	len[4] = 0;
}
*/
void	ft_get_binary_str(unsigned long int n, int power, char *str)
{
	int		j;
	char	c;

	j = 0;
	ft_memset(str, '0', 64);
	str[64] = '\0';
	while (n > 0)
	{
		str[j++] = n % 2 + '0';
		n = n / 2;
	}
//	while (j < 64)
//		tmp[j++] = '0';
	while(j-- > 32)
	{
		c = str[j];
		str[j] = str[63 - j];
		str[63 - j] = c;
	}
	ft_shift(str, power - 63); //-63);
}
/*
int	ft_get_f_m_binary_str(unsigned long int n, char **s, int power)
{
	int		j;
	char	*tmp;
	char	c;
	int		m_len;

	m_len = 53;

	if (!(tmp = ft_strnew(m_len)))
		return (-1);
	j = 0;
	while (n > 0)
	{
		tmp[j++] = n % 2 + '0';
		n = n / 2;
		//j--;
	}
	while (j < m_len - 1)
		tmp[j++] = '0';
	tmp[j++] = '1';
	while(j-- > m_len / 2)
	{
		c = tmp[j];
		tmp[j] = tmp[m_len - j - 1];
		tmp[m_len - j - 1] = c;
	}
//	ft_shift(&tmp, power); //-63);
	*s = tmp;
	return (0);
}
*/


/*
**
** len:
** 0 - length of integer_part
** 1 - length of decimal_part
** 2 - length of sign
** 3 - lenth of printing string
** 4 - counter
** 7 - add printing 0 in precision
*/

void	ft_get_len_output_f(t_spec *s_args, char *str)
{
	int	len[8];
	int	f_len[5];

	ft_float_len(str, f_len);  //0 - len. 1- int. 2 - point 3 - dec without point
	if (s_args->precision > f_len[3])
		len[4] = s_args->precision - f_len[3];
	else
	{
		len[4] = 0;
		if (s_args->precision_ini && !s_args->precision)
		{
			if (s_args->flags[0])
				str[f_len[1] + f_len[2]] = '\0';
			else
				str[f_len[1]] = '\0';
			ft_float_len(str, f_len);
		}
	}
	len[2] = (s_args->sign ? 1 : 0);
	len[1] = f_len[0];
	if (f_len[1] + f_len[2] + f_len[3] + len[2] + len[4] < s_args->width)
		len[3] = s_args->width;
	else
		len[3] = f_len[1] + f_len[2] + f_len[3] + len[2] + len[4]; 	
	s_args->output_len[0] = f_len[0];
	s_args->output_len[1] = len[1];
	s_args->output_len[2] = len[2];
	s_args->output_len[3] = len[3];
	s_args->output_len[4] = len[4];

}

int	ft_put_output_f(t_spec *s_args, char *str)
{
	int	*len;
	int	i;

	i = 0;
	len = s_args->output_len;
	if (s_args->flags[1])
	{
		i = ft_put_sign(s_args, i);
		i = ft_putchar_s_fd('0', i, len[3] - len[1] - len[2] - len[4], s_args->fd);
	}
	if (s_args->flags[2] == 0)
		i = ft_putchar_s_fd(' ', i, len[3] - len[1] - len[2] - len[4], s_args->fd);
	if (len[2])
		i = ft_put_sign(s_args, i);
	i = ft_putchar_s_fd('0', i, i + len[1] - len[0], s_args->fd);
	if (len[3] < len[0])
		str[len[3]] = '\0';
	ft_putstr_fd(str, s_args->fd);
	if (len[4])
		i = ft_putchar_s_fd('0', i, i + len[4], s_args->fd);
	i = i + (len[3] < len[0] ? len[3] : len[0]);
	i = ft_putchar_s_fd(' ', i, len[3], s_args->fd);
	s_args->len = (s_args->len >= 0 ? s_args->len + len[3] : -1);
	return (0);
}

void	ft_roundup_diff(char *str, int precision)
{
	if (precision)
	{
		ft_strcpy(str, "0.");
		str[2 + --precision] = '1';
	//str[2 + precision--] = '1';
		while(precision-- > 0)
			str[2 + precision] = '0';
	}
	else
		ft_strcpy(str, "1.");
	
}

int	ft_isodd(char c)
{
	if ('1' == c || '3' == c || '5' == c || '7' == c || '9' == c)
		return (1);
	return (0);
}

int	ft_roundup(char *str, t_spec *s_args)
{
	int		precision;
	int		len[5];
	char	ret[5000];
	char	round_diff[5000];

	ft_float_len(str, len);
	precision = s_args->precision;
	if (precision < len[3])
	{
		len[4] = (precision ? precision : - 1);
		if ((ft_strchr("6789", str[len[1] + 1 + precision])) || 
			('5' == str[len[1] + 1 + precision] && 
			(ft_isodd(str[len[1] + 1 + len[4] - 1]) || ft_check_str_zero(&str[len[1] + 2 + precision]))))
		{
			ft_roundup_diff(round_diff, precision);
			ft_sum_float(str, round_diff, 10, ret);
			ft_strcpy(str, ret);
		}
		if ((len[1] + 1 + precision) < (int)ft_strlen(str))
			str[len[1] + 1 + precision] = '\0';
	}
	return (0);
//	ft_add_precision(char &str, s_args);
//	return (ft_add_precision(&str, s_args) == 0 ? 0 : -1);
}

void	ft_get_str_f_null(t_spec *s_args, int sign, char *str)
{
	if (sign)
		s_args->sign = '-';
	//s_args->flags[0] = 0;
	//s_args->flags[1] = 0;
	ft_strcpy(str, "0.000000");
}


/*
** -1 - Error
**  0 - Inf
**	1 - NaN
*/


int		ft_check_mantissa(char *str)
{
	if (!ft_strncmp(str, "00", 2))
		return (ft_check_str_zero(&str[2]));
	else if (!ft_strncmp(str, "01", 2))
		return (1);
	else if (!ft_strncmp(str, "10", 2))
		return (ft_check_str_zero(&str[2]));
	else if (!ft_strncmp(str, "11", 2))
	{
		if (ft_check_str_zero(&str[2]))
			return (0);
		else
			return (1);		
	}
	return (-1);
}

void	ft_get_str_f_naninf(t_spec *s_args, unsigned long int mantissa, char *str)
{
	char	m_str[64];

	ft_get_binary_str(mantissa, 63, m_str);
	if (1 == ft_check_mantissa(m_str))
	{
		ft_strcpy(str, "nan");
		s_args->flags[3] = 0;
		s_args->flags[4] = 0;
		s_args->sign = 0;
	}
	else
		ft_strcpy(str, "inf");
	s_args->precision = 0;
	s_args->precision_ini = 1;
	s_args->flags[0] = 0;
	s_args->flags[1] = 0;
}

/*
int	ft_get_shift(char *str)
{
	int	ret;
	int max_power;
	int *len;
	int	len3;

	len = ft_float_len(str);
	max_power = ft_max_power(str);
	if (max_power < len[1])
		ret = len[1] - max_power + max_power / 2;
	else if (max_power > len[1])
	{
		len3 = max_power - len[1] - len[2];
		ret = len[1] + (len[1] + len3) / 2;
	}
	else
		ret = 0;
	return (ret);	
}
*/
void	ft_get_f_str(long double n, t_spec *s_args, char *str)
{
	union u_long_double	u_d;
	int		power;

	str[0] = '\0';
	u_d = (union u_long_double)n;
	if (u_d.f_parts.e == 0 && u_d.f_parts.m == 0)
	{
		ft_get_str_f_null(s_args, u_d.f_parts.s, str);
		return ;
	}
	power = u_d.f_parts.e - 16383;//1023;//127;
	if (u_d.f_parts.s)
		s_args->sign = '-';
	if (power == 16384)//1024) //128)
	{
		ft_get_str_f_naninf(s_args, u_d.f_parts.m, str);
		return ;
	}
	ft_get_binary_str(u_d.f_parts.m, power, str);
	ft_conv_bin_dec(str);
	ft_roundup(str, s_args);
}
