/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:09:26 by rgero             #+#    #+#             */
/*   Updated: 2019/09/17 18:59:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		if (!(ret->content = malloc(sizeof(content) * content_size)))
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	ret->next = NULL;
	return (ret);
}
