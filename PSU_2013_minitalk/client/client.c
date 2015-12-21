/*
** client.c for  in /home/charvo_a/rendu/PSU_2013_minitalk/client
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat Mar 22 15:44:33 2014 Nicolas Charvoz
** Last update Fri Mar 27 14:53:52 2015 Nicolas Charvoz
*/

#include "../headers/client.h"

void	x_error()
{
  my_printf("Error. \n");
  exit(-1);
}

int	send_convert(int pid_serv, char msg)
{
  char	c;

  c = 0;
  while (c < 8)
    {
      usleep(50);
      if (((msg >> c) & 1) == 1)
	{
	  if (kill(pid_serv, SIGUSR1) == -1)
	    x_error();
	}
      else
	if (kill(pid_serv, SIGUSR2) == -1)
	  x_error();
      c++;
    }
  return (0);
}

int		client(char **av, char *buff)
{
  int		i;
  int		pid_serv;
  char		*msg;

  pid_serv = my_getnbr(av[1]);
  msg = buff;
  i = 0;
  while (msg[i] != '\0')
    {
      send_convert(pid_serv, msg[i]);
      i++;
    }
  send_convert(pid_serv, msg[i]);
  return (0);
}

void	check_error()
{
  if (signal(SIGUSR1, NULL) == SIG_ERR)
    {
      x_error();
    }
  if (signal(SIGUSR2, NULL) == SIG_ERR)
    {
      x_error();
    }
}

int		main(int ac, char **av)
{
  if (ac == 3)
    {
      check_error();
      client2(av);
    }
  else if (ac == 2)
    {
      check_error();
      my_clear();
      while (1)
	run(av);
    }
  else
    {
      my_printf("Usage : %s PID", av[0]);
      exit(0);
    }
  return (0);
}
