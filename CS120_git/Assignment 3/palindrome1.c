/******************************************************************************
filename    palindrome1.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
assignment  3
due date    10/24/2017

Brief Description:
Tests if an array contains letters that form a palindrome using subscripting.
  
******************************************************************************/

/**************************************************************************
   Function: is_prime
Description: determines if an array contains a palindrome
     Inputs: phrase[] - array containing word to test
             length   - length of array
    Outputs: 1 or 0, based on if the array is a palindrome or not
             1 is true
             0 is false
**************************************************************************/
int is_palindrome1(const char phrase[], int length)
{
  int i;                 /* loop variable               */
  int end = length - 1;  /* last character in the array */
  
  /* 
   * Test to see if characters a distance from the beginning are the same
   * as characters the same distance from the end of the array
   */ 
  for (i = 0; i < (length / 2); i++)
    if(phrase[end - i] != phrase[i])
      return 0; /* return false if one pair isn't equal */

  return 1;
}