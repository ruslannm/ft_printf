/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:53:23 by rgero             #+#    #+#             */
/*   Updated: 2019/12/09 17:41:26 by rgero            ###   ########.fr       */
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
	
    printf("%f\n", d.ld);
    printf("%u\n", d.s_parts.m);
    printf("%u\n", d.s_parts.e);
    printf("%o\n", d.s_parts.s);

    return (0);
}