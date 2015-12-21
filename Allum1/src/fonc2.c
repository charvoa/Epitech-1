/*
** fonc2.c for  in /home/charvo_a/Work/alum1/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Feb 14 15:31:55 2014 Nicolas Charvoz
** Last update Sun Feb 16 16:10:54 2014 Nicolas Charvoz
*/

#include "alum.h"

int	xread(int fd, char *buffer, int size)
{
  int	ret;

  ret = read(fd, buffer, size);
  if (buffer == NULL)
    {
      my_putstr("Error of read. Buffer empty");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	twoplayer(t_alum *a)
{
  int	ret;

  my_printf("Hello PLayer 1 ! What's your name ?\n");
  ret = xread(0, a->name, 4095);
  a->name[ret - 1] = ' ';
  my_printf("Hello PLayer 2 ! What's your name ?\n");
  ret = xread(0, a->name2, 4095);
  a->name2[ret - 1] = ' ';
  while (1)
    {
      aff_alum(a);
      my_printf("%s is playing :\n", a->name);
      my_read(a);
      my_printf("%s is playing :\n", a->name2);
      my_read(a);
    }
}

void	oneplayer(t_alum *a)
{
  int	ret;

  my_printf("Hello ! What's your name ?\n");
  ret = xread(0, a->name, 4095);
  a->name[ret -1] = ' ';
  my_printf("Oh %s! The Best AER in Nice ! Good Luck\n", a->name);
  while (1)
    {
      aff_alum(a);
      my_printf("%sis playing :\n", a->name);
      my_read(a);
      my_printf("Player 2 is playing :\n");
      player2(a);
    }
}

void		my_choice(t_alum *a)
{
  char		buff[4096];
  int		retour;
  int		choice;

  my_printf("Mode 1 Joueur (1) | Mode 2 Joueurs (2)\n");
  retour = xread(0, buff, 4095);
  buff[retour] = '\0';
  choice = my_getnbr(buff);
  if (choice == 1)
    oneplayer(a);
  else if (choice == 2)
    twoplayer(a);
  else
    {
      my_printf("Wrong Choice !\n");
      my_choice(a);
    }
}
