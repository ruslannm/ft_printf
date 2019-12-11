/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:21:53 by rgero             #+#    #+#             */
/*   Updated: 2019/12/11 16:27:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "real.h" 
 
/* ФУНКЦИЯ ВЫВОДА */
void _print_real (PREALINT num, size_t size) 
{
    while (size--)
        printf("%0.4X ", num[size]);
    printf("\n");
}
 
int main(void)
{
    REALINT real = { 0xAABB, 0xCCDD, 0xEEFF, 0x1111 };
    _print_real(real, REAL_MAX_ORDER);
}