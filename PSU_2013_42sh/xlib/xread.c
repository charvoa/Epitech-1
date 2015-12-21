/*
** xread.c for xread in /home/charvo_a/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat May 24 12:35:39 2014 Nicolas Charvoz
** Last update Sun May 25 21:05:36 2014 Nicolas Charvoz
*/

#include "xlib.h"

ssize_t	xread(int fd, void *buf, size_t count)
{
  int	nb;

  if ((nb = read(fd, buf, count)) == -1)
    {
      fprintf(stderr, "Cannot Read file\n");
      return (-1);
    }
  return (nb);
}
