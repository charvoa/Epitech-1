/*
** xdup2.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:19:21 2014 Nicolas Charvoz
** Last update Sun May 25 21:05:57 2014 Nicolas Charvoz
*/

#include "xlib.h"

int	xdup2(int oldfd, int newfd)
{
  int	fd;

  if ((fd = dup2(oldfd, newfd)) == -1)
    {
      fprintf(stderr, "Cannot duplicate fds\n");
      return (-1);
    }
  return (fd);
}
