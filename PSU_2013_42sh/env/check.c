/*
** check.c for  in /home/charvo_a/rendu/PSU_2013_42sh/env
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 25 23:29:03 2014 Nicolas Charvoz
** Last update Sun May 25 23:34:03 2014 Nicolas Charvoz
*/

#include "string.h"
#include "42sh.h"

int	check_pre()
{
  char	*str;

  if ((str = strdup("lol")) == NULL)
    {
      fprintf(stderr, "I need strdup to work, Goodbye\n");
      return (-1);
    }
  else if ((str = strcpy(str, "str")) == NULL)
    {
      fprintf(stderr, "I need strcpy to work, Goodbye\n");
      return (-1);
    }
  return (0);
}
