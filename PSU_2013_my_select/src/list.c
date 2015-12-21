/*
** list.c for list in /home/charvo_a/Work/select2
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 19 15:03:31 2014 Nicolas Charvoz
** Last update Sun Jan 19 19:37:54 2014 Nicolas Charvoz
*/

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

t_elem	*create()
{
  t_elem	*racine;

  racine = malloc(sizeof(*racine));
  if (racine != NULL)
    {
      racine->prec = racine;
      racine->suiv = racine;
    }
  return (racine);
}

void	addav(t_elem *elem, char *val)
{
  t_elem	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem != NULL)
    {
      new_elem->val = val;
      new_elem->prec = elem->prec;
      new_elem->suiv = elem;
      elem->prec->suiv = new_elem;
      elem->prec = new_elem;
    }
}

void	addap(t_elem *elem, char  *val)
{
  t_elem	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem != NULL)
    {
      new_elem->val = val;
      new_elem->prec = elem;
      new_elem->suiv = elem->suiv;
      elem->suiv->prec = new_elem;
      elem->suiv = new_elem;
    }
}

void	ajouterentete(t_elem *racine, char *val)
{
  addap(racine, val);
}
