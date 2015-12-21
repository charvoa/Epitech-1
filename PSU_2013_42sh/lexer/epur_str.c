/*
** epur_str.c for 42sh in /home/heitzl_s/42/lexer/src
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 17 09:56:13 2014 heitzl_s
** Last update Fri May 23 10:54:31 2014 heitzl_s
*/

#include <stdlib.h>
#include "../xlib/xlib.h"

int	malloc_epured(char *str)
{
  int	i;
  int	cpt;

  cpt = 0;
  i = 0;
  while (str[i] == ' ')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0')
	{
	  cpt++;
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
	if (str[i] != ' ' && str[i] != '\t')
	  cpt++;
      i++;
    }
  return (cpt);
}

char	*epur_str(char	*s)
{
  int	i;
  int	x;
  char	*new;

  i = 0;
  x = 0;
  new = xmalloc((malloc_epured(s) + 1) * sizeof(char));
  while (s[i] == ' ')
    i++;
  while (s[i] != '\0')
    {
      if ((s[i] == ' ' || s[i] == '\t') && s[i + 1] != '\0')
	{
	  while (s[i] == ' ' || s[i] == '\t')
	    i++;
	  if (s[i] != '\0')
	      new[x++] = ' ';
	}
      if (s[i] != ' ' && s[i] != '\t')
	  new[x++] = s[i];
      i++;
    }
  new[x] = '\0';
  return (new);
}
