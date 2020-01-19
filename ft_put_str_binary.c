/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_binary_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:18:37 by rgero             #+#    #+#             */
/*   Updated: 2019/12/18 15:26:29 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_binary_str(intmax_t n, char *s)
{
	int 	i;

	i = ft_nbr_len(n, 2);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = n % 2 + '0';
		n = n / 2;
	}
	return (0);
}

int ft_put_binary_decimal_str(char *b, char *s) 
{ 
    char *num;
	
	num = b; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = ft_strlen(num); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 
  