/*
** open_for_redir.c for open_for_redir in /home/garcia_t/42/execution
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed May 28 11:56:37 2014 garcia antoine
** Last update Wed May 28 15:32:46 2014 garcia antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "execution.h"
#include "../parser/parser.h"
#include "../xlib/xlib.h"

int	open_for_redir_right(char *name)
{
  int	fd;
  
  fd = creat(name, 0644);
  if (access(name, R_OK) == -1)
    {
      fprintf(stderr, "42sh: %s: Permission denied.\n", name);
      return (-1);
    }
  return (fd);
}

int	open_for_dredir_right(char *name)
{
  int	fd;

  fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0666);
  if (access(name, R_OK) == -1)
    {
      fprintf(stderr, "42sh: %s: Permission denied.\n", name);
      return (-1);
    }
  return (fd);
}
