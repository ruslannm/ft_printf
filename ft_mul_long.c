/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:09:21 by rgero             #+#    #+#             */
/*   Updated: 2020/01/31 16:23:57 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
 
/* c = a * b.  Caller is responsible for memory.
   c must not be the same as either a or b. */
void longmulti(const char *a, const char *b, char *c)
{
	int i = 0, j = 0, k = 0, n, carry;
	int la, lb;
 
	/* either is zero, return "0" */
	if (!strcmp(a, "0") || !strcmp(b, "0")) {
		c[0] = '0', c[1] = '\0';
		return;
	}
 	
	la = strlen(a);
	lb = strlen(b);
	memset(c, '0', la + lb);
	c[la + lb] = '\0';
 
	i = la - 1;
    while (i >= 0)
    {
        j = lb - 1;
        k = 1;
        carry = 0;
        while (j >= 0)
        {
            n = (a[i] - '0') * (b[j] - '0') + (c[k] - '0') + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
            j--;
            k--;
        }
        c[k] += carry;
        i--;
    }

	if (c[0] == '0') 
        memmove(c, c + 1, la + lb);
	return;
}

int main()
{
	char c[50000];

	longmulti("12", "34", c);
	printf("%s\n", c);
 
	return 0;
}
