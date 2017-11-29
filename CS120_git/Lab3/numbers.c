/******************************************************************************
filename    numbers.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         3
due date    9/22/2017

Brief Description:
This program prompts the user for 3 values and 
displays the output of several trigonometric functions. 
  
******************************************************************************/
#include <stdio.h> /* printf, scanf */
#include <math.h>  /* sin, cos, tan */

int main (void) {
  float input1; /* First user input  */
  float input2; /* Second user input */
  float input3; /* Third user input  */
  
    /* promts user for 3 numbers*/
  printf("Enter 3 numbers between 0 and 9.999: ");
  scanf("%f%f%f", &input1, &input2, &input3);

    /* prints title lines for output table */
  printf("\nNumber      sin      cos      tan      atan\n");
  printf("-------------------------------------------\n");

    /* prints first number, and sin, cos, tan and atan of it */
  printf("%7.5f%9.3f%9.3f%9.3f%9.3f\n",
         input1, sin(input1), cos(input1), tan(input1), atan(input1));

    /* prints second number, and sin, cos, tan and atan of it */
  printf("%7.5f%9.3f%9.3f%9.3f%9.3f\n",
  	     input2, sin(input2), cos(input2), tan(input2), atan(input2));
  
    /* prints third number, and sin, cos, tan and atan of it */
  printf("%7.5f%9.3f%9.3f%9.3f%9.3f\n",
         input3, sin(input3), cos(input3), tan(input3), atan(input3));
	
  return 0;
}
