/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2019/11/13 16:30:52 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int args, char **argv)
{
	int i;
	if (args == 3)
		ft_printf("int=%i\n", 57);
printf("\nlib:\n");
printf(argv[1], atoi(argv[2]));
i = printf("int=%i\n", 50);
printf("out =%i\n", i);
// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");

	return (0);
}