/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2020/01/28 20:04:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


int main(void) {
	char s[5000];
	
	//ft_div_by2_frac(s);	
	ft_conv_bin_fracpart("0.101", s);
    printf("%s\n", s);
	ft_conv_bin_intpart("1000.00", s);
    printf("%s\n", s);

	ft_strcpy(s, "1");
	longmulti("2", "2", s);
    printf("%s\n", s);


    return (0);
}