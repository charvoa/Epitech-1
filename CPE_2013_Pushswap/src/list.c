/*
** list.c for list in /home/charvo_a/rendu/pushswap
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Jan  6 10:02:46 2014 Nicolas Charvoz
** Last update Mon Jan  6 23:10:28 2014 Nicolas Charvoz
*/

#include "push.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

t_Dlist	*dlist_new(void)
{
  t_Dlist	*p_new;

  p_new  = malloc(sizeof *p_new);
  if (p_new == NULL)
    {
      p_new->length = 0;
      p_new->p_head = NULL;
      p_new->p_tail = NULL;
    }
  return (p_new);
}

t_Dlist *dlist_append(t_Dlist *p_list, int data)
{
  struct node *p_new;

  p_new = malloc(sizeof(*p_new));
  if (p_list != NULL)
    {
      if (p_new != NULL)
        {
	  p_new->data = data;
	  p_new->p_next = NULL;
	  if (p_list->p_tail == NULL)
	    {
	      p_new->p_prev = NULL;
              p_list->p_head = p_new;
	      p_list->p_tail = p_new;
	    }
          else
	    {
	      p_list->p_tail->p_next = p_new;
	      p_new->p_prev = p_list->p_tail;
	      p_list->p_tail = p_new;
	    }
	  p_list->length++;
	}
    }
  return p_list;
}

t_Dlist	*dlist_prepend(t_Dlist *p_list, int data)
{
  struct node	*p_new;

  if (p_list != NULL)
    {
      p_new = malloc(sizeof *p_new);
      if (p_new != NULL)
        {
          p_new->data = data;
	  p_new->p_prev = NULL;
	  if (p_list->p_tail == NULL)
	    {
	      p_new->p_next = NULL;
	      p_list->p_head = p_new;
	      p_list->p_tail = p_new;
	    }
	  else
	    {
              p_list->p_head->p_prev = p_new;
	      p_new->p_next = p_list->p_head;
	      p_list->p_head = p_new;
            }
	  p_list->length++;
	}
    }
  return p_list;
}

void	dlist_delete(t_Dlist **p_list)
{
  struct node	*p_temp;
  struct node	*p_del;

  if (*p_list != NULL)
    {
      p_temp = (*p_list)->p_head;
      while (p_temp != NULL)
	{
	  p_del = p_temp;
	  p_temp = p_temp->p_next;
	  free(p_del);
	}
      free(*p_list);
      p_list = NULL;
    }
}

void	dlist_display(t_Dlist *p_list)
{
  struct node	*p_temp;

  if (p_list != NULL)
    {
      p_temp = p_list->p_head;
      while (p_temp != NULL)
	{
	  my_printf("%d -> \n", p_temp->data);
          p_temp = p_temp->p_next;
	}
    }
}

size_t	dist_length(t_Dlist *p_list)
{
  size_t	ret;

  ret = 0;
  if (p_list != NULL)
    ret = p_list->length;
  return (ret);
}
