/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_dic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:29 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 15:54:35 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*ft_get_c_str(unsigned char n)
{
	char	*ret;
	
	if (!(ret = ft_strnew(2)))
		return (NULL);
	ret[0] = n;
	return (ret);
}
*/

void	ft_get_di_str(intmax_t n, t_spec *s_args, char *str)
{
	int 	i;

	n = n * (n < 0 ? -1 : 1);
	i = ft_nbr_len(n, 10);
	if (n == 0 && s_args->precision_ini == 1 && s_args->precision == 0)
		i = 0;
	if (s_args->precision_ini == 1)
		s_args->flags[1] = 0;
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
}
