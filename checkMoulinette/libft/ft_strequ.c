/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:10:28 by rgero             #+#    #+#             */
/*   Updated: 2019/09/15 14:46:53 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	char *s1_tmp;
	char *s2_tmp;

	if (!s1 || !s2)
		return (0);
	s1_tmp = (char *)s1;
	s2_tmp = (char *)s2;
	while (*s1_tmp != '\0' && *s2_tmp != '\0' && *s1_tmp == *s2_tmp)
	{
		s1_tmp++;
		s2_tmp++;
	}
	if (*s1_tmp == *s2_tmp)
		return (1);
	return (0);
}
