/******************************************************************************
filename    tablen.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         10
due date    11/15/2017

Brief Description:
This program counts tabs and checks line lengths in a file.
  
******************************************************************************/
#include <stdio.h> /* I/O functions */
#include <string.h> /* strlen */
#define MAX_LINE_LENGTH 1000
#define LINE_CHAR_MAX 80
#define TRUE 1
#define FALSE 0

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
   Function: countTabs
Description: counts tabs in a file and prints info
     Inputs: *filename - name of file to be checked
    Outputs: TRUE or FALSE if the file opened successfully
**************************************************************************/
static int countTabs(const char *filename)
{
  char buffer[MAX_LINE_LENGTH] = {0}; /* holds one line of file           */
  int tabs = 0;                       /* number of tabs in a line         */
  int total_tabs = 0;                 /* total number of tabs in the file */
  int line_number = 0;                /* line number in file              */
  int i;                              /* loop variable                    */
  
   /* Open a file for read/text */
  FILE *pFile;
  pFile = fopen(filename, "r");
  if(pFile)
  {
     /* While there are more lines in the file */
    while(!feof(pFile))
    {
      if (fgets(buffer, MAX_LINE_LENGTH, pFile)) /* Read in a line. */
      {
        removeNewline(buffer);
        line_number++;
        tabs = 0;
        i = 0;
        while (buffer[i]) /* Count the number of tabs */
        {
          if (buffer[i] == '\t')
            tabs++;
          i++;
        }
      }

      if (tabs > 0) /* Print that line with tab information */
        printf("#%3i: (tabs:%2i) |%s|\n", line_number, tabs, buffer);
       /* add line tabs to total tabs */
      total_tabs += tabs;
    }

     /* Close the file. */
    fclose(pFile);

     /* Print the summary information. */
    printf("*****  TABS IN USE  *****: Number of tabs in the file is %i.\n",
            total_tabs);
     /* return that file has opened successfully */
    return TRUE;
  }
  else
  {
    printf("Can't open %s for read.", filename);
    return FALSE;
  }
}

/**************************************************************************
   Function: checkLength
Description: checks that  of a line isn't greater than 80 characters 
             in a file and prints info
     Inputs: *filename - name of file to be checked
    Outputs: none 
**************************************************************************/
static void checkLength(const char *filename)
{
  char buffer[MAX_LINE_LENGTH] = {0}; /* holds one line of file          */
  int line_number = 0;                /* line number in file             */
  int str_length;                     /* length of line                  */
  int max_value = 0;                  /* max line length                 */
  int max_line = 0;                   /* line number of max length       */
  int total_over_max = 0;             /* number of lines over max length */
  
   /* Open a file for read/text */
  FILE *pFile;
  pFile = fopen(filename, "r");

  if(pFile)
  { 
     /* While there are more lines in the file */
    while(!feof(pFile))
    {
      str_length = 0;
      if (fgets(buffer, MAX_LINE_LENGTH, pFile)) /* Read in a line. */
      {
        removeNewline(buffer);
        line_number++;
        
        str_length = strlen(buffer); /* Check the length of the line */
         /* Print that line with length information */
        if (str_length > LINE_CHAR_MAX)
        {
          printf("#%3i: (%3i) |%s|\n", line_number, str_length, buffer);
          total_over_max++;
        }
          
        if (str_length > max_value) /* check for new max line length */
        {
          max_value = str_length;
          max_line = line_number;
        }
      }
  
    }
    
     /* Close the file. */
    fclose(pFile);
     /* Print the summary information. */
    printf("***** LINE TOO LONG *****: %i lines longer than %i." 
            " Longest line is %i at %i chars.\n",
            total_over_max, LINE_CHAR_MAX, max_line, max_value);
  }
}


/**************************************************************************
   Function: tablen
Description: counts tabs and checks line lengths in a text file
     Inputs: *filename - name of file to be checked
    Outputs: none 
**************************************************************************/
void tablen(const char *filename)
{
  int file_open; /* T/F if file is open */
  
  /* run count tabs and check if file opened */
  file_open = countTabs(filename);

  if(file_open)
    checkLength(filename);
}