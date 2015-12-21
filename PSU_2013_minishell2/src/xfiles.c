/*
** xfiles.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:16:08 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:16:09 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/my.h"
#include "../headers/printf.h"

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

void	*xmalloc(int size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      my_putstr("Cannot alloc");
      exit(-1);
    }
  return (s);
}
