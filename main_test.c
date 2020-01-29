/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2020/01/29 15:45:35 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


int main(void) {
	char s[5000];
	
	//ft_div_by2_frac(s);	
	ft_conv_bin_fracpart("0.101", s);
    printf("%s\n", s);
	ft_conv_bin_intpart("111.00", s);
    printf("%s\n", s);

	ft_strcpy(s, "1");
	longmulti("2", "2", s);
    printf("%s\n", s);
	ft_strcpy(s, "111.11");
	ft_conv_bin_dec(s);
    printf("%s\n", s);
	ft_strcpy(s, "123.45");
	ft_shift(s, 5);
    printf("%s\n", s);

    return (0);
}