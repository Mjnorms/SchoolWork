/******************************************************************************
filename    sieve.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         7
due date    10/24/2017

Brief Description:
Tests if an array contains letters that form a palindrome using subscripting.
  
******************************************************************************/
#include <stdio.h> /* printf */
#include <math.h>  /* sqrt   */

#define FALSE 0
#define TRUE  1

/**************************************************************************
   Function: sieve
Description: sets elements in a an array to 1 or 0 based on if the index
             is prime or not respectively
     Inputs: primes[] - array containing word to test
             size     - size of array
    Outputs: none
**************************************************************************/
void sieve(int primes[], int size)
{
  int i, j;

  for (i = 0; i < size; i++)
  {
    primes[i] = TRUE;  /* set all elements to TRUE */
  }

  primes[0] = 0; /* 0 and 1 are never prime */
  primes[1] = 0;

  for (i = 2; i <= sqrt(size); i++)
  {
    for (j = 2; (i * j) <= size; j++)
      primes[i * j] = FALSE; /* if it is a multiple, it's not prime */
  }
}

/**************************************************************************
   Function: twin_primes
Description: finds all twin primes in the array
     Inputs: primes[] - array containing word to test
             size     - size of array
    Outputs: count    - number of twin primes in the array
**************************************************************************/
int twin_primes(const int primes[], int size)
{
  int i;         /* loop variables                 */
  int count = 0; /* number of twin primes in array */

  for (i = 0; i < (size - 2); i++)
  {
    /* see if any primes are two apart */
    if (primes[i] == 1 && (primes[i] == primes[i + 2]))
    {
      count++; /* add to total twin prime count */
      printf("twin prime #%4i: %4i and %4i\n", count, i, (i + 2));
    }
  }

  return count;
}

/**************************************************************************
   Function: brun_constant
Description: attempts to approximate Brun's constant from array of primes
     Inputs: primes[] - array containing word to test
             size     - size of array
    Outputs: constant - aproximation of Brun's constant
**************************************************************************/
double brun_constant(const int primes[], int size)
{
  int i;                 /* loop variables                   */
  double constant = 0.0; /* approximation of Brun's constant */

  /* for each set of twin primes, add their reciprocals to constant */
  for (i = 0; i < (size - 2); i++)
  {
    if (primes[i] == 1 && (primes[i] == primes[i + 2]))
      constant += ((1 / (double)i) + (1 / ((double)i + 2)));
  }

  return constant;
}
