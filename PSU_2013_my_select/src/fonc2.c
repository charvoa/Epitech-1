/*
** fonc2.c for fonc2 in /home/charvo_a/Work/select2
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 19 15:03:11 2014 Nicolas Charvoz
** Last update Sun Jan 19 19:36:30 2014 Nicolas Charvoz
*/

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include "../headers/printf.h"
#include "../headers/my.h"

void	my_while(t_elem *list)
{
  int	i;

  i = 0;
  if (tgetent(NULL, "xterm") <= 0)
    {
      my_printf("ERROR\n");
      exit(-1);
    }
  while (i++ <= 1 && list != NULL)
    {
      if (list->val != NULL)
	{
	  tputs(tgetstr("us", NULL), 1, my_int_putchar);
	  my_printf("%s\n", list->val);
	  tputs(tgetstr("ue", NULL), 1, my_int_putchar);
	}
      list = list->suiv;
    }
}

int	xread(int fd, char *buffer, int size)
{
  read(fd, buffer, size);
  if (buffer == NULL)
    {
      my_printf("Error of read. Buffer empty");
      exit(EXIT_FAILURE);
    }
  return (0);
}

void	get_key()
{
  char		buffer[4096];
  struct	termios	*t;

  t = malloc(sizeof(*t));
  if (tcgetattr(0, t) == -1)
    {
      my_printf("ERROR\n");
      exit(-1);
    }
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t) == -1)
    {
      printf("ERROR\n");
      exit(-1);
    }
  xread(0, buffer, 4096);
  if (my_strcmp(buffer, "\x1B") == 0)
    exit(0);
}
