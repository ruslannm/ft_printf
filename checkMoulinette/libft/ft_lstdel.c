/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:03:54 by rgero             #+#    #+#             */
/*   Updated: 2019/09/17 17:16:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*lst;

	if (alst && del)
	{
		lst = *alst;
		while (lst != NULL)
		{
			tmp = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = tmp;
		}
	}
	*alst = NULL;
}
