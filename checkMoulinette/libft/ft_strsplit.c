/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:11:36 by rgero             #+#    #+#             */
/*   Updated: 2019/09/16 14:59:36 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_strlenc(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (!(s[ret] == '\0' || s[ret] == c))
		ret++;
	return (ret);
}

static int		ft_count_words(const char *s, char c)
{
	int	ret;

	ret = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		ret++;
		while (*s == c && *s)
			s++;
	}
	return (ret);
}

static char		*ft_word_add(char **ret, int i, size_t size_word, char const *s)
{
	char	*word;

	if (!(word = (char *)malloc(sizeof(char) * (size_word + 1))))
	{
		while (i > 0)
			free(ret[--i]);
		free(ret);
		return (NULL);
	}
	word = ft_strncpy(word, s, size_word);
	word[size_word] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		nbr_words;
	size_t	size_word;

	if (!s)
		return (NULL);
	i = 0;
	nbr_words = ft_count_words(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (nbr_words + 1))))
		return (NULL);
	j = 0;
	while (i < nbr_words)
	{
		while (s[j] == c && s[j])
			j++;
		size_word = ft_strlenc(&s[j], c);
		if (!(ret[i] = ft_word_add(ret, i, size_word, &s[j])))
			return (NULL);
		i++;
		j += size_word;
	}
	ret[nbr_words] = NULL;
	return (ret);
}
