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

void bi_mul(PBIGINT a, PBIGINT b, PBIGINT c)
{
    PBIGINT lsda, msda, lsdb, msdb;
    PBIGINT ptra, ptrb, ptrc, ptrct;
 
    ULONG carry = 0;
 
    if(BI_GETLEN(a) < BI_GETLEN(b))
    {
        ptra = b;
        ptrb = a;
    }
    else
    {
        ptra = a;
        ptrb = b;
    }
 
    msdb = BI_MSDPTR(ptrb);
    msda = BI_MSDPTR(ptra);
 
    for(ptrc = BI_LSDPTR(c), lsda = BI_LSDPTR(ptra), lsdb = BI_LSDPTR(ptrb); lsdb <= msdb; ++lsdb, ++ptrc)
        *ptrc = (USHORT)(carry = (ULONG)*lsda * (ULONG)*lsdb +
                                 (ULONG)(USHORT)(carry >> BI_BITPERREG));
    
    *ptrc = (USHORT)(carry >> BI_BITPERREG);
 
    for(ptrc = BI_LSDPTR(c) + 1, lsda = BI_LSDPTR(ptra) + 1; lsda <= msda; ++lsda, ++ptrc)
    {
        carry = 0;
        for(ptrct = ptrc, lsdb = BI_LSDPTR(ptrb); lsdb <= msdb; ++lsdb, ++ptrct)
            *ptrct = (USHORT)(carry = (ULONG)*lsda * (ULONG)*lsdb + (ULONG)*ptrct +
                                      (ULONG)(USHORT)(carry >> BI_BITPERREG));
 
        *ptrct = (USHORT)(carry >> BI_BITPERREG);
    }
 
    if(carry >> BI_BITPERREG)
        ++ptrc;
 
    BI_SETLEN(c, ptrc - BI_LSDPTR(c));
}


int main(void)
{
    REALINT real = { 0xAABB, 0xCCDD, 0xEEFF, 0x1111 };
    _print_real(real, REAL_MAX_ORDER);
}