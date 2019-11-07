/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:05:05 by rgero             #+#    #+#             */
/*   Updated: 2019/09/17 18:42:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_del(void *content, size_t len)
{
	ft_bzero(content, len);
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*nxt;

	if (!(lst && f))
		return (NULL);
	tmp = f(lst);
	if (!(nxt = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	ret = nxt;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(nxt->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_lstdel(&ret, ft_del);
			return (NULL);
		}
		nxt = nxt->next;
		lst = lst->next;
	}
	return (ret);
}
