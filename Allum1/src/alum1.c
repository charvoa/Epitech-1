/*
** alum1.c for  in /home/charvo_a/Work/alum1
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Jan 23 10:28:12 2014 Nicolas Charvoz
** Last update Sun Feb 16 16:09:54 2014 Nicolas Charvoz
*/

#include "alum.h"

void	my_enlev(t_alum *a)
{
  a->row[a->line - 1] -= a->nb;
  a->somme -= a->nb;
  aff_alum(a);
}

int	player2(t_alum *a)
{
  int	i;

  i = -1;
  if (a->somme <= 1)
    {
      my_printf("\033[07;01m%s WON\033[00m\n", a->name);
      exit(0);
    }
  while (++i <= 3)
    {
      if ((a->row[i] % 2) == 0 && a->row[i] != 0)
        {
          a->row[i] -= 2;
	  a->somme -= 2;
	  return (0);
        }
      else if ((a->row[i] % 2) != 0 && a->row[i] != 0)
        {
          a->row[i] -= 1;
	  a->somme -= 1;
	  return (0);
        }
    }
  aff_alum(a);
  return (0);
}

void	my_read(t_alum *a)
{
  char	line[4096];
  char	nb[4096];
  int	ret;

  if (a->somme <= 1)
    {
      my_clear();
      my_printf("\033[07;01m%sLOST\033[00m\n", a->name);
      exit(0);
    }
  my_printf("How many matches do you wanna take ?\n");
  ret = xread(0,  nb, 4095);
  nb[ret] = '\0';
  a->nb = my_getnbr(nb);
  my_printf("\nAt which line do you wanna take those poor matches ?\n");
  ret = xread(0, line, 4095);
  line[ret] = '\0';
  a->line = my_getnbr(line);
  if (a->line > 4 || a->line <= 0 || a->nb > a->row[a->line - 1] || a->nb <= 0)
    {
      my_printf("\nWrong choice, try again !\n");
      my_read(a);
    }
  else
    my_enlev(a);
}

void	create_row(t_alum *a)
{
  a->row = xmalloc(8 * sizeof(int));
  a->row[0] = 1;
  a->row[1] = 3;
  a->row[2] = 5;
  a->row[3] = 7;
  a->somme = 16;
}

int		main()
{
  t_alum	*a;

  a = xmalloc(sizeof(*a));
  create_row(a);
  my_clear();
  my_choice(a);
  return (0);
}
