/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2020/01/28 16:07:09 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


int main(void) {
	char s[5000];

	ft_strcpy(s, "0.1");
	//ft_div_by2_frac(s);	
	ft_conv_bin_dec_place(s);
    printf("%s\n", s);
    return (0);
}