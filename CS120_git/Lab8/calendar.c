/******************************************************************************
filename    calendar.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         8
due date    11/1/2017

Brief Description:
This program can find if a year is leap, finds the day of the week in a month
for any year, and can print a calendar for any month in any year.
  
******************************************************************************/
#include <stdio.h>

#define TRUE  1
#define FALSE 0

/**************************************************************************
   Function: is_leapyear
Description: determines if an year is a leap
     Inputs: year - year in question
    Outputs: TRUE or FALSE
**************************************************************************/
int is_leapyear(int year)
{
  if (year % 400 == 0)
    return TRUE;
  else if (year % 100 == 0)
    return FALSE;
  else if (year % 4 == 0)
    return TRUE;
  else
    return FALSE;
}

/**************************************************************************
   Function: day_of_the_week
Description: returns the day of the week 
     Inputs: day   - day of the month
             month - month that needs to be printed
             year  - year that month is in
    Outputs: day of the week, Sunday-Saturday = 1-7
**************************************************************************/
int day_of_the_week(int day, int month, int year)
{
  int weekday;      /* day of the week                                   */
  int code;         /* code needed to find day of the week               */
  int month_keys[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6}; /* month keys */
  int year_keys[] = {4, 2, 0, 6};                          /* day keys   */

   /* follow day algorithm */
  code = year % 100;
  code /= 4;
  code += day;              
  code += month_keys[month - 1];

  if((month == 1 || month == 2) && is_leapyear(year))
    code--;

  while(year > 2099)
    year -= 400;

  if (2000 <= year && year <= 2099)
    code += year_keys[3];
  else if (1900 <= year && year <= 1999)
    code += year_keys[2];
  else if (1800 <= year && year <= 1899)
    code += year_keys[1];
  else
    code += year_keys[0];

  code += year % 100;

  weekday = code  % 7;

  if (weekday == 0)
    weekday += 7;

  return weekday;
}

/**************************************************************************
   Function: print_calendar
Description: prints a calendar for a given month and year
     Inputs: month - month that needs to be printed
             year  - year that month is in
    Outputs: none
**************************************************************************/
void print_calendar(int month, int year)
{
  /* days in each month, 0 = jan */
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
  /* months in a year            */ 
  char *months[] = {"January",   "February", "March",    "April", 
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};
  
  int first_day;  /* day of the week of the first day in the month */
  int total_days; /* number of days in the month                   */
  int day;        /* day of the week                               */
  int i;          /* loop variable                                 */


   /* Print calendar header */ 
  printf("%s, %i\n", months[month - 1], year);
  printf("Su Mo Tu We Th Fr Sa\n");
  printf("---------------------\n");

   /* find the day of the week the first day is on */
  first_day = day_of_the_week(1, month, year);
  total_days = days_in_month[month - 1]; /* number of days in given month */

   /* add a day to febuary if it's a leap year */
  if (month == 2 && is_leapyear(year)) 
  {
    total_days++;
  }

   /* print empty days until first day of the month */
  for (i = 1; i < first_day; i++)
  {
    printf("   ");
  }


  day = first_day; /* day counter to current day of the week */

  /* print days */
  for (i = 1; i <= total_days; i++, day++)
  {
    printf("%2d ",i);

    if(day % 7 == 0 && i != total_days) /* on saturday, start a new line */
      printf("\n");
  }

  printf("\n"); /* new line at the end of the month */
}
