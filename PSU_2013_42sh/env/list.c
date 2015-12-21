/*
** list.c for list in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Apr 19 16:12:18 2014 garcia antoine
** Last update Sun May 25 20:20:17 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include "listok.h"
#include "../xlib/xlib.h"

t_token	        *insert(t_token *token, int type, char *value, int pos)
{
  t_token	*tok;
  t_token	*tmp;

  tok = xmalloc(sizeof(t_token));
  tok->type = type;
  tok->value = value;
  tok->pos = pos;
  tok->next = NULL;
  if (token == NULL)
    return (tok);
  else
    {
      tmp = token;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = tok;
      return (token);
    }
}

t_token		*free_my_tok(t_token *token)
{
  t_token	*tmp;
  t_token	*tok;

  tmp = token;
  while (tmp != NULL)
    {
      tok = tmp->next;
      free(tmp);
      tmp = tok;
    }
  return (NULL);
}
