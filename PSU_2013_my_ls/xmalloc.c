/*
** xmalloc.c for xmalloc in /home/charvo_a/rendu/PSU_2013_my_ls
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Dec  1 09:41:21 2013 Nicolas Charvoz
** Last update Sun Dec  1 11:11:47 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include <unistd.h>
#include "./headers/myls.h"
#include "./headers/my.h"

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
