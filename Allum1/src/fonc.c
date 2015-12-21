/*
** fonc.c for  in /home/charvo_a/Work/alum1
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Feb 13 13:01:57 2014 Nicolas Charvoz
** Last update Sun Feb 16 16:10:11 2014 Nicolas Charvoz
*/

#include "alum.h"

int     my_int_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

void    my_clear()
{
  if (tgetent(NULL, "xterm") <= 0)
    {
      my_printf("ERROR\n");
      exit(-1);
    }
  tputs(tgetstr("cl", NULL), 1, my_int_putchar);
}

void    *xmalloc(int size)
{
  void  *s;

  if ((s = malloc(size)) == NULL)
    {
      my_putstr("Cannot alloc");
      exit(-1);
    }
  return (s);
}

void    remplissage(int nb)
{
  while (nb > 0)
    {
      my_printf("| ");
      nb--;
    }
  my_printf("\n");
}

void    aff_alum(t_alum *a)
{
  my_printf("\n");
  my_printf("1) (%d)       ", a->row[0]);
  remplissage(a->row[0]);
  my_printf("2) (%d)     ", a->row[1]);
   remplissage(a->row[1]);
   my_printf("3) (%d)   ", a->row[2]);
  remplissage(a->row[2]);
  my_printf("4) (%d) ", a->row[3]);
  remplissage(a->row[3]);
  my_printf("\n");
}
