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
#include "jumble.h" /* ENCODE/DECODE */

/**************************************************************************
   Function: mystrlen
Description: finds length of a string
     Inputs: *string - string that needs to be measured
    Outputs: length of the string
**************************************************************************/
int mystrlen(const unsigned char *string)
{
  int count = 0; /* loop variable */

  /* count each char until null pointer */
  while(string[count] != 0)
    count++;

  return count;
}

/**************************************************************************
   Function: jumble
Description: encodes a string
     Inputs: *string   - string to be jumbled
             *password - string used to encode or decode
             method    - to encode or decode
             passes    - how many times to run password over string
    Outputs: none
**************************************************************************/
void jumble(unsigned char *string, const unsigned char *password, 
            enum CODE_METHOD method, int passes)
{
  int phraseLength = mystrlen(string); /* length of string   */
  int passLength = mystrlen(password); /* length of password */
  int sign = 1;                        /* default is encode  */
  int i, j;                            /* loop variables     */

   /* swap if method is decode */
  if (method == DECODE)
    sign *= -1;

   /* add or subtract password to string to encode or decode respectively    */
  while(passes != 0)
  {
    for (i = 0, j = 0; i < phraseLength; i++)
    {
      string[i] += sign * password[j]; /* add or subtract password           */
      if (j == (passLength - 1))
        j = 0;                         /* reset password if ran out of chars */
      else
        j++;                           /* or continue to next char           */
    }
    passes--;                          /* count pass                         */
  }
}
