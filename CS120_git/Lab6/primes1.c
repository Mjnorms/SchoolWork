/******************************************************************************
filename    primes1.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         6
due date    10/19/2017

Brief Description:
This program performs basics functions with arrays.
  
******************************************************************************/
#include <stdio.h> /* printf */

#define FALSE 0
#define TRUE  1

/**************************************************************************
   Function: is_prime
Description: determines if an integer is a prime number
     Inputs: number - int in question
    Outputs: TRUE or FALSE
**************************************************************************/
int is_prime(int number)
{
  int i; /* loop variable */

  /* two is always prime */
  if(number == 2)
    return TRUE;

  /* one and even numbers are never prime */
  if(number == 1 || number % 2 == 0)
    return FALSE;

  /* check if any number devides into 'number' except 1 and itself */
  for (i = 3; i < number / 2; i++)
  {
    if(number % i == 0)
    {
      return FALSE;
    }
  }

  /* if not, then return true for prime */
  return TRUE;
}

/**************************************************************************
   Function: conjecture
Description: find two primes numbers that sum to each even number 
             in a range
     Inputs: low  - low end of range
             high - high end of range
    Outputs: Prints first example of sum for each even number
**************************************************************************/
void conjecture(int low, int high)
{
  int i, j, k; /* loop variables */

  int is_prime(int number);

  /* add one to the low end if the number is odd */
  if(low % 2 != 0)
    low++;

  /* traverse through the whole range */
  for (i = low; i <= high; i += 2)
  {
    for (j = 2; j <= high; j++)
    {
      if(is_prime(j))
      {
        for (k = 2; k <= high; k++)
        {
          if(is_prime(k) && (k + j == i) && j <= k)
          {
            printf("%3i = %3i + %3i\n", i, j, k);  /* if both j and k are */
            break;                                 /* and add up to i,    */
          }                                        /* then print the sum  */
        }                                          /* and try the next    */ 
      }                                            /* even number         */
      if(is_prime(k) && (k + j == i) && j <= k)
        break;
    }
  }
  return;
}