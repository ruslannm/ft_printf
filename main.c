/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:27 by rgero             #+#    #+#             */
/*   Updated: 2019/11/10 13:20:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int args, char **argv)
{
	if (args == 2)
		ft_printf(argv[1], 543);

printf("lib printf c=%055i\n", 543);
// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");

	return (0);
}