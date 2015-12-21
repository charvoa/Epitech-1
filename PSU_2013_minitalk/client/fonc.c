/*
** termcaps.c for  in /home/charvo_a/Work/minitalk/client
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Mar  3 12:25:04 2014 Nicolas Charvoz
** Last update Sat Mar 22 16:42:39 2014 Nicolas Charvoz
*/

#include "../headers/client.h"

int	my_int_putchar(int c)
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
  my_printf("\033[34m\033[1m----------> MINITALK <----------\033[0m\n");
  my_printf("\033[34m       by Nicolas Charvoz       \033[0m\n");
}

int             client2(char **av)
{
  int           i;
  int           pid_serv;
  char          *msg;

  pid_serv = my_getnbr(av[1]);
  msg = av[2];
  i = 0;
  while (msg[i] != '\0')
    {
      send_convert(pid_serv, msg[i]);
      i++;
    }
  send_convert(pid_serv, msg[i]);
  return (0);
}

void	run(char **av)
{
  char		voz[READ_SIZE];
  char		buff[100];
  time_t	now;
  int		ret;

  now = time (0);
  my_printf("\nEntrez un message :\n");
  ret = xread(0, voz, READ_SIZE - 1);
  voz[ret - 1] = '\0';
  client(av, voz);
  strftime(buff, 100, "%Y-%m-%d %H:%M", localtime (&now));
  my_printf ("\033[34m%s\033[0m", buff);
  my_memset(voz, 0, 4096);
}
