/*
** d_flag.c for d flag in /home/charvo_a/rendu/PSU_2013_my_ls
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Dec  1 09:41:48 2013 Nicolas Charvoz
** Last update Sun Dec  1 10:48:20 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include "./headers/myls.h"
#include "./headers/my.h"

void	d_flag(char *name)
{
  char	*flag;

  flag = ".";
  if (my_strcmp(name, flag) != 0)
    my_printf("\033[34m%s\n\033[1m", name);
  else
    my_printf("\033[34m%c\n\033[1m", '.');
}
