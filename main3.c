/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2019/12/12 16:38:42 by rgero            ###   ########.fr       */
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
	float ld; 
	struct 
	{ 
		unsigned int m : 23; 
		unsigned int e : 8;
		unsigned int s : 1; 
	} 		s_parts; 
};

int main(void) {
    union floatint u = {10.f};
	union my_double d = {3.14f};
	int i;
	unsigned int z;

    printf("%f\n", d.ld);
    printf("mant %u\n", d.s_parts.m);
    printf("mant %x\n", d.s_parts.m);
    printf("%u\n", d.s_parts.e);
    printf("%o\n", d.s_parts.s);
	printf("%f\n", d.s_parts.m / 8388608.0);
	z = d.s_parts.m;
	i = 0;
	while (i++ < 23)
		z = z / 2.;
    printf("z %u\n", z);

    return (0);
}