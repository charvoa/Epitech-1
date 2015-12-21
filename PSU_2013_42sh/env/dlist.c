/*
** list.c for list in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 11:55:23 2014 garcia antoine
** Last update Sun May 25 19:36:39 2014 Nicolas Girardot
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "../xlib/xlib.h"

void            show_list(t_dlist *list)
{
  t_node        *tmp;

  tmp = list->start;
  while (tmp)
    {
      printf("%s=%s\n", tmp->name, tmp->value);
      tmp = tmp->next;
    }
}

t_dlist		*create_list()
{
  t_dlist	*list;

  list = xmalloc(sizeof(*list));
  if (list != NULL)
    {
      list->lenght = 0;
      list->start = NULL;
      list->end = NULL;
    }
  return (list);
}

void	add_node(t_dlist *list, t_node *node)
{
  if (list != NULL)
    {
      if (list->start == NULL)
	{
	  list->start = node;
	  list->end = node;
	  node->next = NULL;
	  node->prev = NULL;
	}
      else
	{
	  list->end->next = node;
	  node->prev = list->end;
	  node->next = NULL;
	  list->end = node;
	}
      list->lenght++;
    }
}

void		put_in_list(t_dlist *list, char *name, char *value)
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->name = strdup(name);
  node->value = strdup(value);
  add_node(list, node);
}

void	free_my_list(t_dlist *list)
{
  t_node	*tmp;
  t_node	*del;

  tmp = list->start;
  while (tmp)
    {
      del = tmp;
      tmp = tmp->next;
      free(del->name);
      free(del->value);
      free(del);
    }
  free(list);
}
