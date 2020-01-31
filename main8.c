/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:09:21 by rgero             #+#    #+#             */
/*   Updated: 2020/01/31 16:48:10 by rgero            ###   ########.fr       */
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
 
	/* see if either a or b is negative */
	if (a[0] == '-') { i = 1; k = !k; }
	if (b[0] == '-') { j = 1; k = !k; }
 
	/* if yes, prepend minus sign if needed and skip the sign */
	if (i || j) {
		if (k) c[0] = '-';
		longmulti(a + i, b + j, c + k);
		return;
	}
 
	la = strlen(a);
	lb = strlen(b);
	memset(c, '0', la + lb);
	c[la + lb] = '\0';
 
#	define I(a) (a - '0')
	for (i = la - 1; i >= 0; i--) {
		for (j = lb - 1, k = i + j + 1, carry = 0; j >= 0; j--, k--) {
			n = I(a[i]) * I(b[j]) + I(c[k]) + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
		}
		c[k] += carry;
	}
#	undef I
	if (c[0] == '0') memmove(c, c + 1, la + lb);
 
	return;
}
 int main()
{
	char c[50000];

	longmulti("12", "34", c);
	printf("%s\n", c);
 
	return 0;
}