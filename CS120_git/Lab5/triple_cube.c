/******************************************************************************
filename    triple_cube.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         3
due date    10/10/2017

Brief Description:
This program contains two functions, one that prints 3 digit number that have
the cube property, and the other that print pythag triples
  
******************************************************************************/
#include <stdio.h> /*prinf*/

/******************************************************************************
   Function: print_cubes

Description: print out all triple digit number that its digits trippled and
             added together are the same as the number itself

     Inputs: none

    Outputs: Printed lines of the numbers and its digits
******************************************************************************/
void print_cubes(void)
{
  int first_digit;  /* first digit of 3 digit number */
  int second_digit; /* second digit of 3 digit number */
  int third_digit;  /* last digit of 3 digit number */
  int sum;          /* sum of cubed digits */
  int i;            /* loop variables */

  for (i = 100; i < 1000; i++)
  {
    first_digit = i / 100;
    second_digit = i / 10 % 10;
    third_digit = i % 10;

    /* cube each digit */
    first_digit = first_digit * first_digit * first_digit;
    second_digit = second_digit * second_digit * second_digit;
    third_digit = third_digit * third_digit * third_digit;

    /* add cubes together */
    sum = first_digit + second_digit + third_digit;

    /* if sum of cubes equals 3 digit number */
    if (sum == i)
    {
      printf("%i has the cube property. (%i + %i + %i)\n", 
             i, first_digit, second_digit, third_digit);
    }
  }
}

/******************************************************************************
   Function: print_pythagorean_triples

Description: prints number in a range that are pythagorean triples

     Inputs: low  - starting number
             high - last number

    Outputs: Printed lines of pythag triples
******************************************************************************/
void print_pythagorean_triples(int low, int high)
{
  int i, j, k;   /* loop variables */
  int i_squared; /* first number squared */
  int j_squared; /* second number squared */
  int k_squared; /* third number squared */
  int count = 0; /* number of triples found */
  int sum = 0;   /* sum of first two numbers squared */

  for (i = low; i < high - 2; i++)
  {
    for (j = i + 1; j < high - 1; j++)
    {
      for (k = j + 1; k < high; k++)
      {
        i_squared = (i * i);
        j_squared = (j * j);
        k_squared = (k * k);
        sum = i_squared + j_squared;

        if (sum == k_squared)
        { 
          count++;
          printf("Triple #%3i: %3i,%3i,%3i --> %4i + %4i = %4i\n", 
                 count, i, j, k, i_squared, j_squared, k_squared);
        }
      }
    }
  }
}
