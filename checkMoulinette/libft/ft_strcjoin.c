/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:46:48 by rgero             #+#    #+#             */
/*   Updated: 2019/11/27 16:09:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcjoin(char const *s1, char c)
{
	size_t	s1_len;
	size_t	i;
	char	*ret;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!(ret = (char *)malloc(sizeof(char) * (s1_len + 2))))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
