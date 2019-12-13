/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:09:21 by rgero             #+#    #+#             */
/*   Updated: 2019/12/13 16:11:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int Div(int *S, int *S1, int n, int n1, char A[], char B[])
{
    int t = SizeOfDec(n, n1);
    int *S3 = S, i = 0, *S31, *S11;
    int u = ComparingNumber(S, S1, n, n1);
    for (; u>0; i++)
    {
        S3 = Dec(S3, S1, n, n1, t);
        for (long long int i = t - 1; i >= 0; i--)
        {
            if (S3[i] == 0)
            {
                t--;
            }
            if (S3[i] != 0)break;
        }
        S31 = TurnArray(S3, t);
        ///PrintArray2(S31, t);
        ///printf("\n");
        S11 = TurnArray(S1, n1);
        ///PrintArray2(S11, n1);
        ///printf("\n");
        u = ComparingNumber(S31, S11, t, n1);
    }
    return i;
}

int ComparingNumber1(int *S1, int *S2, int n, int n1)
{
    int t;
    if (n > n1) t = 1;
    if (n < n1) t = 0;
    if (n == n1)
    {
        for (int i = 0; i <n; i++)
        {
            if (S1[i]>S2[i])
            {
                t = 1;
                break;
            }
            if (S1[i] < S2[i])
            {
                t = 0;
                break;
            }
            if (S1[i] == S2[i])
            {
                t = -1;
            }
        }
    }
    return t;
}

int ComparingNumber(int *S1, int *S2, int n, int n1)
{
  int res;
  
  if (n < n1) res = -1;
  else if (n > n1) res = 1;
  else res = memcmp(S1, S2, n * sizeof(*S1));
 
  return res;
}

int* TurnArray1(int *S, int n)
{
    int* S3 = (int*)malloc(sizeof(int)*n);
    for (int i = 0, i1 = 1; i<n; i++, i1++)
    {
        S3[i] = S[n - i1];
        if (S[n-i1] < 0) S3[i] = 0;
    }
    return S3;
}


int* TurnArray(int *S, int n)
{
  int *S3 = 0;
 
  int i = 0;
  int i1 = 0;
 
  if ((S != NULL) && (n > 0))
  {
    S3 = malloc(n * sizeof(*S3));
 
    if (S3 != NULL)
    {
      i = 0;
      i1 = 1;
 
      while (i < n)
      {
        if (S[n - i1] < 0) S3[i] = 0;
        else S3[i] = S[n - i1];
        
        i++;
        i1++;
      }
    }
  }
 
  return S3;
}

int main()
{
	return (0);
}