/******************************************************************************
filename    array.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
assignment  2
due date    10/19/2017

Brief Description:
This program performs basics functions with arrays.
  
******************************************************************************/

/**************************************************************************
   Function: reverse_array
Description: Given an array, reverse the order of the elements in 
             the array
     Inputs: a[]  - array to be reversed
             size - size of a[]
    Outputs: none
**************************************************************************/
void reverse_array(int a[], int size)
{
  int i;               /* loop variable                    */
  int temp;            /* holds value at first position    */
  int end = size - 1;  /* reverse of the temp in the array */
  
  for (i = 0; i < size / 2; i++)
  {
    temp = a[i];        /* grab first value                            */
    a[i] = a[end - i];  /* set first position to reverse value         */
    a[end - i] = temp;  /* take first value at set to reverse position */
  }

  return;
}

/**************************************************************************
   Function: add_arrays
Description: Takes three arrays, add the elements of the first two 
             arrays and put the sum in the third array.
     Inputs: a[] - first array of ints
             b[] - second array of ints
             c[] - array that holds sum of a[] and b[] at each position
    Outputs: none
**************************************************************************/
void add_arrays(const int a[], const int b[], int c[], int size)
{
  int i; /* loop variable */

  for (i = 0; i < size; i++)
    c[i] = a[i] + b[i]; /* add a and b values together and place into c */

  return;
}

/**************************************************************************
   Function: scalar_multiply
Description: Multiplies each each element in an array by the multiplier.
     Inputs: a[]        - array of ints to be multiplied
             size       - size of array
             multiplier - number each element is to be multiplied by
    Outputs: none
**************************************************************************/
void scalar_multiply(int a[], int size, int multiplier)
{
  int i; /* loop variable */

  for (i = 0; i < size; i++)
    a[i] *= multiplier;

  return;
}

/**************************************************************************
   Function: dot_product
Description: Takes two arrays, determines the dot product 
     Inputs: a[]  - first array of ints
             b[]  - second array of ints
             size - size of both arrays
    Outputs: scalar dot product of a[] and b[]
**************************************************************************/
int dot_product(const int a[], const int b[], int size)
{
  int i;            /* loop variable            */
  int product = 0;  /* resulting scalar product */

  for (i = 0; i < size; i++)
    product += (a[i] * b[i]);
  
  return product; 
}

/**************************************************************************
   Function: cross_product
Description: Takes three arrays, determines the cross product of the
             first two, and places the result in the third
     Inputs: a[] - first array of ints
             b[] - second array of ints
             c[] - array that holds crost product of a[] and b[]
    Outputs: none
**************************************************************************/
void cross_product(const int a[], const int b[], int c[])
{

  /* cross product calculations for 3x1 matricies */
  c[0] = (a[1] * b[2]) - (a[2] * b[1]);
  c[1] = -((b[2] * a[0]) - (b[0] * a[2]));
  c[2] = (a[0] * b[1]) - (a[1] * b[0]);

  return;
}
