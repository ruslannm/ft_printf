/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:24:38 by rgero             #+#    #+#             */
/*   Updated: 2019/12/13 15:24:42 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* sum(const char first[], const char second[])
{
    size_t nFirst = strlen(first);
    size_t nSecond = strlen(second);
 
    size_t size = (nFirst > nSecond) ? nFirst : nSecond;
    size += 2;
 
    char* number = (char*) malloc(size);
    number[size - 1] = 0;
 
    const char* a = first + nFirst - 1;
    const char* b = second + nSecond - 1;
    char* c = number + size - 2;
    char one = 0;
 
    char digitA, digitB;
 
    for (; (first <= a) || (second <= b); --a, --b, --c)
    {
        digitA = (first <= a) ? (*a - '0') : 0;
        digitB = (second <= b) ? (*b - '0') : 0;
 
        *c = ((digitA + digitB + one) % 10) + '0';
        one = (digitA + digitB + one) / 10;
    }
 
    if (one)
    {
        *c = '1';
    }
    else
    {
        memmove(number, number + 1, size - 1);
    }
 
    return number;
}
 
int main()
{
    char* result = sum("123321237", "9230");
    printf("%s\n", result);
    free(result);
 
    result = sum("123456789987654321", "12345678998765432123456876168");
    printf("%s\n", result);
    free(result);
 
    result = sum("51234567891234564789654131847861313578641313378761",
                 "51387461387681346761348646131316846134684613131846");
    printf("%s\n", result);
    free(result);
 
    return 0;
}