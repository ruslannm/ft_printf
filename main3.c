/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2020/01/16 16:35:29 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

union floatint{
  float f;
    int i;
};
10000000000000000000000000000000000000000000000000000000000000000
1000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000
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
	unsigned char *s;

    printf("%f\n", d.ld);
    printf("mant %u\n", d.s_parts.m);
    printf("mant %x\n", d.s_parts.m);
    printf("%u\n", d.s_parts.e);
    printf("%o\n", d.s_parts.s);
	printf("%f\n", d.s_parts.m / 8388608.0);
	z = d.s_parts.m;
	//s = (unsigned char *)d.s_parts.m;
	i = 0;
	while (i++ < 23)
		z = z / 2.;
    printf("z %u\n", z);

    return (0);
}