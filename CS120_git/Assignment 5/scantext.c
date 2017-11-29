/******************************************************************************
filename    scantext.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
assignment  5
due date    11/15/2017

Brief Description:
This program counts tabs, characters, and words in a string.
  
******************************************************************************/
int toupper(int c);
/**************************************************************************
   Function: mystrlen
Description: finds the length of a string 
     Inputs: *string - string that needs to be measured
    Outputs: length of string 
**************************************************************************/
static int mystrlen(const char *string)
{
  int length = 0;  /* The number of characters in the string */
  
    /* Count the characters (not including the NUL) */
  while (*string++)
    length++;

  return length;
}

/**************************************************************************
   Function: count_tabs
Description: counts the number of tabs in the string 
     Inputs: *string - string that needs to be measured
    Outputs: number of tabs 
**************************************************************************/
int count_tabs(const char *string)
{
  int tabs = 0; /* number of tabs */

  while (*string)
  {
    if (*string == '\t')
      tabs++; /* if a tab is found, add 1 to count */
    string++;
  }

  return tabs;
}

/**************************************************************************
   Function: substitute_char
Description: Given a string, substitute old_char with new_char 
     Inputs: *string  - string where the chars are being changed
             old_char - char to be swapped out
             new_char - char to be swapped in
    Outputs: Number of substitutions
**************************************************************************/
int substitute_char(char *string, char old_char, char new_char)
{
  int substitutions = 0; /* number of substitutions made */

  while (*string)
  {
    if (*string == old_char)
    {
       /* if an old char is found, swap it and add to count */
      *string = new_char;
      substitutions++;
    }
    string++;
  }
  return substitutions;
}

/**************************************************************************
   Function: calculate_lengths
Description: Calculate the length and print length of the string.
     Inputs: *string - string to be counted
             tabsize - size of tabs
    Outputs: *string_length  - length of string
             *display_length - print length of string
**************************************************************************/
void calculate_lengths(const char *string, int tabsize, int *string_length,
                          int *display_length)
{
  int tabs; /* number of tabs in the string */

  tabs = count_tabs(string);

   /* number of characters in the string w/ tabs */
  *string_length = mystrlen(string);
   /* number of characters in the string when tabs are replaced by spaces */
  *display_length = mystrlen(string) - tabs + (tabs * tabsize);

}

/**************************************************************************
   Function: count_words
Description: Count the number of words in a string
     Inputs: *string - string to be counted 
    Outputs: number of words
**************************************************************************/
int count_words(const char *string)
{ 
  int word_count = 0; /* number of words in the string */
  int word;           /* current word flag */

   /* move through the string until a word is found */
  while(*string)
  {
    word = 0;
     /*move through one word*/ 
    while(toupper(*string) >= 'A' && toupper(*string) <= 'Z')
    {
      word = 1;
      string++;
    }
     /* count word */
    word_count += word;
    string++;
  }

  return word_count;
}
