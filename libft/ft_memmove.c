/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:28:19 by rgero             #+#    #+#             */
/*   Updated: 2019/09/15 11:09:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	if (len == 0 || dst == src)
		return (dst);
	i = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (src_tmp < dst_tmp)
		while (len-- > 0)
			dst_tmp[len] = src_tmp[len];
	else
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	return (dst);
}
