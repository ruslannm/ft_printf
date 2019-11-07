/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:23:17 by rgero             #+#    #+#             */
/*   Updated: 2019/09/11 15:53:09 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h_tmp;
	char	*n_tmp;
	size_t	i;
	size_t	j;

	h_tmp = (char *)haystack;
	n_tmp = (char *)needle;
	if (!*n_tmp)
		return (&h_tmp[0]);
	i = 0;
	while (h_tmp[i] != '\0')
	{
		j = 0;
		while (h_tmp[i + j] == n_tmp[j])
		{
			j++;
			if (n_tmp[j] == '\0')
				return (&h_tmp[i]);
		}
		i++;
	}
	return (NULL);
}
