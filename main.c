/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2019/11/10 17:05:19 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int args, char **argv)
{
	if (args == 3)
		ft_printf(argv[1], argv[2]);
printf("\nlib:\n");
printf(argv[1], argv[2]);
// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");

	return (0);
}