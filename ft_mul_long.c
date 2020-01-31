/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:09:21 by rgero             #+#    #+#             */
/*   Updated: 2020/01/31 17:29:54 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mul_long(const char *s1, const char *s2, char *s3)
{
	int	l[3];
	int	i[6];

	l[1] = ft_strlen(s1);
	l[2] = ft_strlen(s2);
	ft_memset(s3, '0', l[1] + l[2]);
	s3[l[1] + l[2]] = '\0';
	i[1] = l[1] - 1;
	while (i[1] >= 0)
	{
		i[2] = l[2] - 1;
		i[3] = i[1] + i[2] + 1;
		i[5] = 0;
		while (i[2] >= 0)
		{
			i[4] = (s1[i[1]] - '0') * (s2[i[2]--] - '0') + (s3[i[3]] - '0') +
					i[5];
			i[5] = i[4] / 10;
			s3[i[3]--] = (i[4] % 10) + '0';
		}
		s3[i[3]] += i[5];
		i[1]--;
	}
	if (s3[0] == '0')
		ft_memmove(s3, s3 + 1, l[1] + l[2]);
}
