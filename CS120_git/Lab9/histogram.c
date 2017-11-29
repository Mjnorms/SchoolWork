/******************************************************************************
filename    jumble.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
assignment  4
due date    11/1/2017

Brief Description:
This program uses low level encoding teqniques to encrypt a string
  
******************************************************************************/
#include <stdio.h>     /* printf      */
#include <ctype.h>     /* toupper     */
#include <string.h>    /* strlen      */
#include "histogram.h" /* lab defines */

/**************************************************************************
   Function: GetCounts
Description: counts the number of letters, spaces, 
             and other characters in a string 
     Inputs: *string - string that needs to be measured
    Outputs: count     - number of letters in the string
             letters[] - a count of each letter in the string
             *spaces   - number of spaces in the string
             *other    - number of other characters in the string 
**************************************************************************/
int GetCounts(const char *string, int letters[], int *spaces, int *other)
{
  int count = 0; /* number of letters in the string */
  int i = 0;     /* loop variable                   */

   /* reset all passed parameters */
  *spaces = 0;
  *other = 0;
  while(i < NUM_LETTERS)
  {
    letters[i] = 0;
    i++;
  }

   /* reset loop variable */
  i = 0;

   /* go through each element in the string */
  while(string[i] != 0)
  {
     /* if it's a letter make it uppercase */
    int current = toupper(string[i]);

    if(current >= 'A' && current <= 'Z')
    {
      letters[current - 'A']++; /* increment the letter */
      count++; /* add letter to total */
    }
    else if (current == SPACE)
      *spaces += 1;
    else
      *other += 1;
    
    i++;
  }
   /* return total number of letters */
  return count;
}

/**************************************************************************
   Function: PrintHistogram
Description: prints a histogram of the count of letters given in an array 
     Inputs: letters[] - count of each letter than needs to be printed
    Outputs: none
**************************************************************************/
void PrintHistogram(const int letters[])
{
  int i, j; /* loop variables */

  for (i = 0; i < NUM_LETTERS; i++)
  {
    printf("%c:", 'A' + i); /* print the first part */
    for (j = 0; j < letters[i]; j++)
    {
      printf("*"); /* print stars based on count of letters */
    }
    printf("\n"); /* next line */
  }
}

/**************************************************************************
   Function: GetStatistics
Description: counts the number of letters, spaces, 
             and other characters in a string 
     Inputs: letters[] - array of counts of letters in a string
    Outputs: *average    - average score of the string
             *max_letter - most common letter in the string
             *max_count  - count of most common letter in the string
**************************************************************************/
void GetStatistics(const int letters[], double *average, char *max_letter,
                 int *max_count)
{
  int i;              /* loop variables */
  double total = 0.0; /* total score    */

   /* reset all passed parameters */
  *average = 0;
  *max_letter = 'A';
  *max_count = 0;

   /* calculate the score */
  for (i = 0; i < NUM_LETTERS; i++)
  {
     /* add score of letter to the total */
    total += (letters[i] * (i + 1));

     /* set new max if current letter has greater count */
    if (*max_count < letters[i])
    {
      *max_letter = 'A' + i;
      *max_count = letters[i];
    }
  }
   /* calculate the average score */
  *average = total / NUM_LETTERS;
}