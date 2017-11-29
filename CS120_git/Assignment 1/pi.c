/******************************************************************************
filename    pi.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         3
due date    10/10/2017

Brief Description:
This program calculates two approximations of pi using the circle method and
the leibniz method.
  
******************************************************************************/

#include <math.h> /* sqrt */

/******************************************************************************
   Function: cicle_pi

Description: calculates an approximation of pi by calculating the area of a
             quarter of a circle with radius 2.

     Inputs: rectangles - (int) the number of rectangles that should be used
                           in the aproximation

    Outputs: The approximation of pi based on the area of a quarter circle 
******************************************************************************/
double circle_pi(int rectangles)
{
  double radius = 2.0; /* radius of the circle */
  double width;        /* width of the indevidual rectangles*/
  double height;       /* height of each rectanle */
  double midpoint;     /* midpoint of each rectagle */
  double area;         /* area of the quarter circle - approx of pi*/
  double x;            /* x coordinate of midpoint intercept to circle*/
  int i;               /* loop variables */

  area = 0;
  width =  radius / rectangles;
  midpoint = width / 2;

  /* 
   * For each rectangle, find the height and then calulate the area of the
   * rectangle, then add it to the total area calculation
   */
  for (i = 0; i < rectangles; i++)
  {
    x = (midpoint + width * i);
    height = sqrt((radius * radius) - (x * x));
    
    area += height * width;
  }

  return area;
}

/******************************************************************************
   Function: leibniz_pi

Description: Calculate an approximation of pi using the leibniz method

     Inputs: iterations - (int) the number of times wanted to repeat the
                           addition and subtraction sequence.

    Outputs: The approximation of pi
******************************************************************************/
double leibniz_pi(int iterations)
{
  double pi_approx = 0; /* the result of the approximation */
  int numerator = 1;    /* The numerator of the fraction */
  int denominator = 1;  /* The the denominator of the fraction */
  int i;                /* loop variables */

  /* add/subract leibinez fractions together 'iterations' number of times */
  for (i = 0; i < iterations; i++)
  {
    pi_approx += numerator / (double)denominator;
    denominator += 2;
    numerator *= -1;
  }

  return (pi_approx * 4); /* multiply by for because leibniz calulates pi/4 */
}
