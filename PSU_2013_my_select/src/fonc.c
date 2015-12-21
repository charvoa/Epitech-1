/*
** fonc.c for fonc in /home/charvo_a/Work/select2
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 19 15:03:18 2014 Nicolas Charvoz
** Last update Sun Jan 19 19:37:25 2014 Nicolas Charvoz
*/

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include "../headers/printf.h"
#include "../headers/my.h"

int	my_int_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

void	pt(t_elem *list, int sz)
{
  int   i;

  i = -1;
  my_while(list);
  list = list->suiv;
  list = list->suiv;
  while (++i <= sz && list != NULL)
    {
      if (list->val != NULL)
	my_printf("%s\n", list->val);
      list = list->suiv;
    }
}

void	my_clear()
{
  if (tgetent(NULL, "xterm") <= 0)
    {
      my_printf("ERROR\n");
      exit(-1);
    }
  tputs(tgetstr("cl", NULL), 1, my_int_putchar);
}

int     main(int ac, char **av, char **envp)
{
  t_elem        *l_a;
  int           i;

  if (envp == NULL)
    exit(-1);
  i = 1;
  l_a = create();
  if (ac <= 1)
    my_printf("Pas d'éléments à afficher.\n");
  while (i <= ac)
    {
      addav(l_a, av[i]);
      i++;
    }
  my_clear();
  pt(l_a, (ac - 1));
  get_key();
  return (0);
}
