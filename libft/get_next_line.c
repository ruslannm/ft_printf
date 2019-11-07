/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:31:45 by rgero             #+#    #+#             */
/*   Updated: 2019/10/09 17:21:21 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_lst_pop(t_list **root, char **line, int fd, int ret)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *root;
	prev = NULL;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
		{
			if (!(*line = ft_strdup((char *)tmp->content)))
				ret = -1;
			if (prev)
				prev->next = tmp->next;
			else
				*root = tmp->next;
			free(tmp->content);
			free(tmp);
			return (ret);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(*line = ft_strnew(1)))
		ret = -1;
	return (ret);
}

static int	ft_lst_push(t_list **root, int fd, char *tail)
{
	t_list	*tmp;

	if (!*root)
	{
		if (!(*root = ft_lstnew(tail, ft_strlen(tail) + 1)))
			return (-1);
		(*root)->content_size = fd;
	}
	else
	{
		tmp = *root;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_lstnew(tail, ft_strlen(tail) + 1)))
			return (-1);
		tmp->next->content_size = fd;
	}
	return (1);
}

static int	ft_split_line(char **tail, char **buff_pos)
{
	int ret;

	ret = 1;
	if (!(*tail = ft_strdup(*buff_pos + 1)))
		ret = -1;
	*buff_pos[0] = '\0';
	return (ret);
}

static int	ft_get_buff(int fd, char **line, char **tail, char **buff)
{
	ssize_t	buff_bytes;
	char	*buff_pos;
	char	*tmp;

	while ((buff_bytes = read(fd, *buff, BUFF_SIZE)) > 0)
	{
		(*buff)[buff_bytes] = '\0';
		if (!(tmp = ft_strjoin(*line, *buff)))
			return (-1);
		free(*line);
		*line = tmp;
		if ((buff_pos = ft_strchr(*line, '\n')))
			return (ft_split_line(&(*tail), &buff_pos));
	}
	if (ft_strlen(*line) > 0)
		return (1);
	return (buff_bytes < 0 ? -1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	char			*tail;
	int				ret;
	static t_list	*root = NULL;
	char			*buff_pos;
	char			*buff;

	tail = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(buff = (char*)malloc(BUFF_SIZE + 1)))
		return (-1);
	if (ft_lst_pop(&root, &(*line), fd, 1) == -1)
		return (-1);
	if ((buff_pos = ft_strchr(*line, '\n')))
		ret = ft_split_line(&tail, &buff_pos);
	else
		ret = ft_get_buff(fd, &(*line), &tail, &buff);
	if (tail && tail[0] != '\0')
		ret = ft_lst_push(&root, fd, tail);
	ft_memdel((void **)&buff);
	ft_memdel((void **)&tail);
	return (ret);
}
