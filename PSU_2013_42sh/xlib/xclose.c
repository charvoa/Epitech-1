/*
** xclose.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:18:16 2014 Nicolas Charvoz
** Last update Sun May 25 21:05:59 2014 Nicolas Charvoz
*/

#include "xlib.h"

int	xclose(int fd)
{
  if ((close(fd)) == -1)
    {
      fprintf(stderr, "Cannot Close file\n");
      return (-1);
    }
  return (0);
}
