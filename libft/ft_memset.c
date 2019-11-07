/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:01:32 by rgero             #+#    #+#             */
/*   Updated: 2019/09/16 16:02:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b_tmp;

	b_tmp = (unsigned char *)b;
	while (len-- > 0)
	{
		*b_tmp = (unsigned char)c;
		b_tmp++;
	}
	return (b);
}
