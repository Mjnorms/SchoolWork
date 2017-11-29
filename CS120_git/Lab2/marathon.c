/******************************************************************************
filename    marathon.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         2
due date    09/16/2017

Brief Description:
  This program calculates the distance of a marathon in kilometers. 
  
******************************************************************************/

#include <stdio.h> /* printf */

/* Convenient definitions */
#define YARDS_PER_MILE
#define KILOS_PER_MILE 1.609

/* A marathon is 26 miles, 385 yards               */
/* Prints the distance of a marathon in kilometers */
int main(void)
{
  int miles = 26;    /* Miles in a marathon                 */
  int yards = 385;   /* Yards in a marathon                 */
  double kilometers; /* Calculated kilometers in a marathon */
  
    /* Convert miles and yards into kilometers */
  kilometers = (miles + (double)yards / YARDS_PER_MILE) * KILOS_PER_MILE;

     /* Display the result on the screen */
  printf("A marathon is %f kilometers\n", kilometers);
  
    /* Return successful value to OS */
  return 0;
}
