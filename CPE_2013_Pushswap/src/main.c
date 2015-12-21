/*
** main.c for main pushswap in /home/charvo_a/rendu/pushswap
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Jan  6 16:04:43 2014 Nicolas Charvoz
** Last update Mon Jan  6 23:08:03 2014 Nicolas Charvoz
*/

#include "push.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int		main(int ac, char **av)
{
  t_Dlist	*l_a;
  int	i;

  l_a = dlist_new();
  i = 1;
  if (ac < 1)
    return(0);
  while (i < ac)
    {
      dlist_append(l_a, atoi(av[i]));
      i++;
    }
  dlist_display(l_a);
  my_printf("List Length : %d\n", dist_length(l_a));
  return (0);
}
