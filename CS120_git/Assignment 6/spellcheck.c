/******************************************************************************
filename    spellcheck.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
assignment  6
due date    11/30/2017

Brief Description:
A program that performs actions with a dictionary
  
******************************************************************************/
#include <string.h> /* strlen, strcpy, strcmp    */
#include <stdio.h>  /* FILE, fopen, feof, fclose */

/* FILE_OK, FILE_ERR_OPEN, WORD_OK, WORD_BAD, LONGEST_WORD */
#include "spellcheck.h"

int toupper(int c);

/**************************************************************************
   Function: removeNewline
Description: replaces the new line at the end of a fgets string w/ nul
     Inputs: *string - string to remove new line from
    Outputs: none 
**************************************************************************/
static void removeNewline(char *string)
{
  int strlength; /* length of string */

  strlength = strlen(string); /* find length */
  string[strlength - 1] = '\0'; /* go to end of str and replace with nul */
}

/**************************************************************************
   Function: word_count
Description: count the number of words
     Inputs: *dictionary - list of words
    Outputs: number of words in dictionary
**************************************************************************/
static int word_count(const char *dictionary)
{
  char buffer[LONGEST_WORD] = {0}; /* holds one line of file */
  int count = 0;                   /* count of words in file */
  
   /* Open a file for read/text */
  FILE *pFile;
  pFile = fopen(dictionary, "rt");
  if(!pFile)
    return FILE_ERR_OPEN;

   /* While there are more lines in the file */
  while(!feof(pFile))
  {
    if (fgets(buffer, LONGEST_WORD, pFile)) /* Read in a line. */
      count++;  /* add one to count */
  }

   /* Close the file. */
  fclose(pFile);

  return count;
}

/**************************************************************************
   Function: mystrupr
Description: convert all lowercase letters to uppercase
     Inputs: *string - string to change
    Outputs: pointer to the first character of the string that was
             passed in
**************************************************************************/
char *mystrupr(char *string)
{
  char *first = string; /* pointer to the first char in string */

  while (*string)
  {
    *string = toupper(*string); /* set char to upper */
    string++; /* move to next char in string */
  }
  return first;
}

/**************************************************************************
   Function: words_starting_with
Description: count the number of words that start with letter given
     Inputs: *dictionary - list of words
             letter      - letter to check for
    Outputs: number of words that start with letter 
**************************************************************************/
int words_starting_with(const char *dictionary, char letter)
{
  char buffer[LONGEST_WORD] = {0}; /* holds one line of file     */
  int count = 0;                   /* words starting with letter */
  FILE *pFile;                     /* dictionary file            */
  
   /* Open a file for read/text */
  pFile = fopen(dictionary, "rt");
  if(!pFile)
    return FILE_ERR_OPEN;

   /* While there are more lines in the file */
  while(!feof(pFile))
  {
    if (fgets(buffer, LONGEST_WORD, pFile)) /* Read in a line. */
    {
      removeNewline(buffer); /* remove newline at the end */
      if (toupper(buffer[0]) == toupper(letter))
        count++;  /* if first letter matches add one to count */
    }
  }

   /* Close the file. */
  fclose(pFile);

  return count;
}

/**************************************************************************
   Function: word_lengths
Description: find words within character count
     Inputs: *dictionary - list of words
             lengths[]   - words within length
             count       - max length
    Outputs: result of file open
**************************************************************************/
int word_lengths(const char *dictionary, int lengths[], int count)
{
  char buffer[LONGEST_WORD] = {0}; /* holds one line of file */
  int i = 0;                       /* loop variable          */
  int length = 0;                  /* length of string       */
  FILE *pFile;                     /* dictionary file        */
  
  while (lengths[i])
  {
    lengths[i] = 0;
    i++;
  }

   /* Open a file for read/text */
  pFile = fopen(dictionary, "rt");
  if(!pFile)
    return FILE_ERR_OPEN;

   /* While there are more lines in the file */
  while(!feof(pFile))
  {
    if (fgets(buffer, LONGEST_WORD, pFile)) /* Read in a line. */
    {
      removeNewline(buffer); /* remove newline at the end */
      length = strlen(buffer);
      if (length <= count)
      {
        lengths[length]++; /* add one to count at correct length */
      }
    }
  }

   /* Close the file. */
  fclose(pFile);

  return FILE_OK;
}

/**************************************************************************
   Function: info
Description: report some information for the file given
     Inputs: *dictionary - file to inspect
             *dinfo      - info to report
    Outputs: result of file open 
**************************************************************************/
int info(const char *dictionary, struct DICTIONARY_INFO *dinfo)
{
  char buffer[LONGEST_WORD] = {0};     /* holds one line of file */
  int word_minimum = LONGEST_WORD + 1; /* smallest word          */
  int word_maximum = 0;                /* largest word           */
  int length = 0;                      /* length of word         */
  FILE *pFile;                         /* dictionary file        */

   /* Open a file for read/text */
  pFile = fopen(dictionary, "rt");
  if(!pFile)
    return FILE_ERR_OPEN;

   /* While there are more lines in the file */
  while(!feof(pFile))
  {
    if (fgets(buffer, LONGEST_WORD, pFile)) /* Read in a line. */
    {
      removeNewline(buffer); /* remove newline at the end */
      length = strlen(buffer); /* set length of word */
      if (length < word_minimum)
        word_minimum = length; /* set new minimum */
      if (length > word_maximum)
        word_maximum = length; /* set new max */
    }
  }

  dinfo->count = word_count(dictionary); /* set word count */
  dinfo->shortest = word_minimum;  /* set shortest word */
  dinfo->longest = word_maximum;  /* set longest word */

   /* Close the file. */
  fclose(pFile);
  
  return FILE_OK;
}

/**************************************************************************
   Function: spell_check
Description: check spelling of word by check if word exists in dictionary
     Inputs: *dictionary - list of words
             *word       - word to check 
    Outputs: result of spell check 
**************************************************************************/
int spell_check(const char *dictionary, const char *word)
{
  char buffer[LONGEST_WORD] = {0}; /* holds one line of file   */
  char string[LONGEST_WORD] = {0}; /* holds copy of given word */
  FILE *pFile;                     /* dictionary file          */
  int result = WORD_BAD;           /* result of spell check,   */
                                   /* default is bad spelling  */

  strcpy(string, word); /* create copy of the word */
  strcpy(string, mystrupr(string)); /* set to uppercase */

  /* Open a file for read/text */
  pFile = fopen(dictionary, "rt");
  if(!pFile)
    return FILE_ERR_OPEN;

   /* While there are more lines in the file */
  while(!feof(pFile))
  {
    if (fgets(buffer, LONGEST_WORD, pFile)) /* Read in a line. */
    {
      removeNewline(buffer); /* remove newline at the end */
      strcpy(buffer, mystrupr(buffer));; /* set to uppercase */
      if (strcmp(buffer, string) == 0) /* words are spelled the same */
      {
        result = WORD_OK; /* set result to matching */
        break;
      }
    }
  }

   /* Close the file. */
  fclose(pFile);

  return result;
}
