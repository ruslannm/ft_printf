/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_tolst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:44:18 by rgero             #+#    #+#             */
/*   Updated: 2019/09/18 18:10:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_del(void *content, size_t len)
{
	ft_bzero(content, len);
	free(content);
}

t_list		*ft_strsplit_tolst(char const *s, char c)
{
	char	**arr;
	t_list	*ret;
	t_list	*nxt;
	int		i;

	if (!(arr = ft_strsplit(s, c)))
		return (NULL);
	i = 0;
	if (!(nxt = ft_lstnew(arr[i], ft_strlen(arr[i]) + 1)))
		ret = NULL;
	ret = nxt;
	while (arr[++i])
	{
		if (!(nxt->next = ft_lstnew(arr[i], ft_strlen(arr[i]) + 1)))
		{
			ft_lstdel(&ret, &ft_del);
			return (NULL);
		}
		nxt = nxt->next;
	}
	return (ret);
}
