/*
** xpipe.c for xpipe.c in /home/charvo_a/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat May 24 12:36:53 2014 Nicolas Charvoz
** Last update Sun May 25 21:05:39 2014 Nicolas Charvoz
*/

#include "xlib.h"

int	xpipe(int *pipefd)
{
  if ((pipe(pipefd) == -1))
    {
      fprintf(stderr, "Cannot open pipe\n");
      return (-1);
    }
  return (0);
}
