/*
** xfiles.c for xfiles in /home/charvo_a/rendu/PSU_2013_minishell1/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Dec 13 15:28:53 2013 Nicolas Charvoz
** Last update Wed Dec 18 14:38:28 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../headers/minishell.h"

int	check_space(char *str)
{
  int	i;

  i = 0;
  while ((str[i] == ' ') || (str[i] == '\t') && (str[i] != '\0' && str[i] != '\n'))
    i++;
  if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
    return (1);
  else
    return (0);
}

void	*xmalloc(size_t	size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      my_putstr("Cannot malloc !\n");
      exit(-1);
    }
  return (s);
}
