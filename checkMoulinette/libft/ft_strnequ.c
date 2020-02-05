/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:13:54 by rgero             #+#    #+#             */
/*   Updated: 2019/09/16 16:46:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_tmp[i] != '\0' && s2_tmp[i] != '\0')
			if (s1_tmp[i] == s2_tmp[i])
				i++;
			else
				return (0);
		else if (s1_tmp[i] == s2_tmp[i])
			return (1);
		else
			return (0);
	}
	return (1);
}
