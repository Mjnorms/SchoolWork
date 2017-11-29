/******************************************************************************
filename    fibonacci.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         4
due date    10/3/2017

Brief Description:
This program prompts the user for a value and then prints the Fibonacci
sequence and quotient up to the number of times the user specified
  
******************************************************************************/
#include <stdio.h> /* printf, scanf */

/* Start Header ----------------------------------------------------------
  DESCRIPTION:  Prints the Fibbonacci sequence the number of times the user
                specified, up to 46 times.

  METHOD:       Display the prompt and accept the user input
                Print the column headings and first two values
                Calculate the other values (loop) and print them

- End Header -----------------------------------------------------------*/
int main (void) 
{

  double quotient; /* stores calculated Fibonacci quotient */
  int lastNumber;  /* number of times to repeat Fibbonaci sequence */
  int previous;    /* previous Fibonacci number in sequence */
  int current;     /* current number in sequence */
  int next;        /* next number in sequence */
  int i;           /*loop variables */

    /* get user input, exit if 1, continue if between 2 and 46 */
  do
  {
    printf("Enter the Fibonacci number to calculate.");
    printf("\nThe number must be an integer between 2 and 46. ");
    printf("(Enter 1 to quit): ");
    scanf("%d", &lastNumber);

    if(lastNumber == 1)
      break;

    /* print header and first 2 lines if input is good */
    else if(lastNumber >= 2 && lastNumber <= 46)
    {
      printf("\n%20s%17s", "Fibonacci", "Fibonacci");
      printf("\n%2s%17s%18s", "N", "number", "quotient");
      printf("\n-------------------------------------");
      printf("\n%2i%14i%21s", 0, 0, "N/A");
      printf("\n%2i%14i%21s", 1, 1, "N/A");
      printf("\n");
    }
  }
  while (lastNumber < 2 || lastNumber > 46);

    /* initialize previous and next to values in last line printed */
  previous = 1;
  next = 1;

    /* print lines until number of lines = to user input */
  for(i = 2; i <= lastNumber; i++)
  {
    current = next;
    quotient = ((double)current / previous); /* calculate quotient */
    printf("%2i%14i%21.16f\n", i,            /* print line */
           current, quotient);
    next = current + previous;               /* find next fib number */
    previous = current;
  }

  return 0;
}
