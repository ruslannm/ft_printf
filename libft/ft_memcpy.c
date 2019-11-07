/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:24:35 by rgero             #+#    #+#             */
/*   Updated: 2019/09/14 15:14:36 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (n == 0 || dst == src)
		return (dst);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (n-- > 0)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
