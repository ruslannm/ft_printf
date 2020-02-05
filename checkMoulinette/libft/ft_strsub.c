/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:28 by rgero             #+#    #+#             */
/*   Updated: 2019/09/16 16:30:44 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = (size_t)start;
	while (i < len)
		ret[i++] = s[j++];
	ret[i] = '\0';
	return (ret);
}
