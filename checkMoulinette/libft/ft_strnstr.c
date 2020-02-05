/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:57:13 by rgero             #+#    #+#             */
/*   Updated: 2019/09/15 18:20:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	if (*needle == '\0')
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack && len-- >= n_len)
	{
		if ((*haystack == *needle) &&
				(ft_strncmp(haystack, needle, n_len) == 0))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
