/******************************************************************************
filename    list.c
author      Michael Norman
DP email    michael.norman@digipen.edu
course      CS120
section     B
lab         11
due date    11/23/2017

Brief Description:
A program that contains functions for a linked list
  
******************************************************************************/
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */
#include "list.h"   /* Node   */

/**************************************************************************
   Function: add_front
Description: add a new node to the front of the list
     Inputs: **list - list to add to
             value  - value to add to list
    Outputs: none 
**************************************************************************/
void add_front(struct Node **list, int value)
{
  struct Node *newNode; /* new node to add to the front */

  newNode = malloc(sizeof(struct Node)); /* Allocate a new node struct */
  newNode->number = value; /* Set the number */
  newNode->next =  *list;  /* Set next node  */
  *list = newNode;
}

/**************************************************************************
   Function: print_list
Description: prints the value of each node in a list
     Inputs: *list - list to print
    Outputs: none 
**************************************************************************/
void print_list(const struct Node *list)
{
  while (list) 
  {
    printf("%3i", list->number); /* Print data                */
    list = list->next; /* "Follow" the next pointer */
  }
  printf("\n");
}

/**************************************************************************
   Function: free_list
Description: free all of the nodes on the list given
     Inputs: *list - list to free
    Outputs: none 
**************************************************************************/
void free_list(struct Node *list)
{
  while (list)
  {
    struct Node *temp = list->next; /* save the next node in the list */
    free(list); /* free current node */
    list = temp;
  }
}

/**************************************************************************
   Function: size_list
Description: find the number of nodes in given list
     Inputs: *list - list to count
    Outputs: number of nodes 
**************************************************************************/
int size_list(const struct Node *list)
{
  int count = 0; /* count of nodes */

  while (list)
  {
    count++; /* add to count, move to next node */
    list = list->next;
  }
  return count;
}

/**************************************************************************
   Function: sum_list
Description: add up all the values in each node in a list
     Inputs: *list - list to sum
    Outputs: sum of nodes 
**************************************************************************/
int sum_list(const struct Node *list)
{
  int sum = 0; /* sum of values */

  while (list)
  {
    sum+= list->number; /* add each node's value to the sum of the rest */
    list = list->next;
  }
  return sum;
}

/**************************************************************************
   Function: add_back
Description: add a node to the back of a list
     Inputs: **list - list to add to 
             value  - value to add
    Outputs: none
**************************************************************************/
void add_back(struct Node **list, int value)
{
  struct Node *newNode; /* new node to add to the front */

  newNode = malloc(sizeof(struct Node)); /* Allocate a new node struct */
  newNode->number = value; /* Set the number */
  newNode->next = NULL;    /* No next yet */

  if (*list == NULL)
    *list = newNode;
  else
  {
    struct Node *temp = *list; /* temp node to hold one in memory */
      /* Find the end of the list */
    while (temp->next)
      temp = temp->next;

    temp->next = newNode; /* Put new node at the end */
  }
}

/**************************************************************************
   Function: remove_item
Description: remove the first node that contains a value
     Inputs: **list - list to remove from 
             value  - value to remove
    Outputs: none
**************************************************************************/
void remove_item(struct Node **list, int value)
{
  struct Node *pNode = *list; /* temp node to hold one in memory */
  struct Node *temp = NULL;   /* temp node to hold one in memory */

   /* only run if list is not empty */
  if (*list != NULL)
  {
     /* test if first node has value */
    if (pNode->number == value)
    {
       /* remove first node and move header to second node */
      pNode = pNode->next;
      temp = *list;
      *list =temp->next;
      free(temp);
    }
    else /* if first does not have value */
    {
       /* step though to find node with value */
      while(pNode->next)
      {
        if (pNode->next->number == value)
        {
          temp = pNode->next; /* set temp to node with value */
          pNode->next = temp->next; /* remove the node from the list */
          free(temp); /* free remove node's memory */
          break;
        }
        pNode = pNode->next;
      }
    }
  }
}
