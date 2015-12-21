/*
** server.c for  in /home/charvo_a/Work/minitalk/server
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Feb 26 10:08:38 2014 Nicolas Charvoz
** Last update Sat Mar 22 16:45:48 2014 Nicolas Charvoz
*/

#include "../headers/server.h"

int		convert_writer(int binary)
{
  static char	c;
  static int	i = 0;

  c += (binary << i++);
  if (i > 7)
    {
      my_putchar((c == '\0') ? '\n' : c);
      c = 0;
      i = 0;
    }
  return (0);
}

void	my_sig(int sign)
{
  if (sign == SIGUSR1)
    convert_writer(1);
  if (sign == SIGUSR2)
    convert_writer(0);
}

void	x_error()
{
  if (signal(SIGUSR1, my_sig) == SIG_ERR)
    {
      my_printf("Error.\n");
      exit(-1);
    }
  if (signal(SIGUSR2, my_sig) == SIG_ERR)
    {
      my_printf("Error.\n");
      exit(-1);
    }
}

int	main()
{
  x_error();
  my_printf("Server PID :");
  my_put_nbr(getpid());
  my_putchar('\n');
  while (42)
    pause();
  return (0);
}
