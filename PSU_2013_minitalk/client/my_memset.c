/*
** my_memset.c for  in /home/charvo_a/Work/minitalk/client
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Feb 26 09:57:02 2014 Nicolas Charvoz
** Last update Wed Feb 26 11:03:08 2014 Nicolas Charvoz
*/

#include "../headers/client.h"

void	my_memset(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      ++i;
    }
}

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
