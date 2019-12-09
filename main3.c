/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2019/12/09 16:44:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

union floatint{
  float f;
    int i;
};

union u_double 
{	
	long double ld; 
	struct 
	{ 
		unsigned long int m : 64; 
		unsigned int e : 15;
		unsigned int s : 1; 
	} 		s_parts; 
};

union my_double 
{	
	double ld; 
	struct 
	{ 
		unsigned long int m : 52; 
		unsigned int e : 11;
		unsigned int s : 1; 
	} 		s_parts; 
};

int main(void) {
    union floatint u = {10.f};
	union my_double d = {0.15625};
	
    printf("%f\n", d.ld);
    printf("%lu\n", d.s_parts.m);
    printf("%x\n", d.s_parts.e);
    printf("%o\n", d.s_parts.s);

    return (0);
}