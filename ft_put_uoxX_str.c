/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uoxX_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2020/01/11 17:22:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_udigit(uintmax_t n, int base)
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

char	*ft_get_u_str(uintmax_t n, t_spec *s_args)
{
	int 	i;
	char	*str;

	i = ft_get_udigit(n, 10);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0 )
		i = 0;
	if (s_args->precision_ini == 1)
		s_args->flags[1] = 0;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

/*
int	ft_put_u_str(uintmax_t n, t_spec *s_args)
{
	int 	i;
	int		j;

	i = ft_get_udigit(n, 10);
	i = i + (s_args->flags[5] == 39 ? THOUSAND_SEP_LEN * (i / 3 ) : 0);
	if (!(s_args->output_raw = ft_strnew(i)))
		return (-1);
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
	return (0);
}
*/

char	*ft_put_o_str(uintmax_t n, t_spec *s_args)
{
	int i;
	int	base;
	char	*str;

	base = (s_args->conversion == 'o' ? 8 : 16);
	i = ft_get_udigit(n, base);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
	if (s_args->flags[0] && (!i || n))
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = n % base + '0';
		n = n / base;
	}
	return (str);
}

char	*ft_get_xX_str(uintmax_t n, t_spec *s_args)
{
	int i;
	int	base;
	char	*str;

	base = (s_args->conversion == 'o' ? 8 : 16);
	i = ft_get_udigit(n, base);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
/*
	if (s_args->conversion != 'o' && n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)// && !s_args->flags[0])
		i = 0;
*/
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		if (n % base < 10)
			str[i] = n % base + '0';
		else
			str[i] = n % base - 10 + (s_args->conversion == 'x' ? 'a' : 'A');
		n = n / base;
	}
	return (str);
}

char	*ft_get_p_str(char *s)
{
	int i;
	int	base;
	long p;
	char	*ret;

	base = 16;
	p = (long)s;
	free(s);
	i = ft_get_udigit(p, base);
	if (!(ret = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		if (p % base < 10)
			ret[i] = p % base + '0';
		else
			ret[i] = p % base - 10 + 'a';
		p = p / base;
	}
	return (ret);
}
