/*
** my_str_to_wordtab.c for strtowordtab in /home/charvo_a/rendu/Minishell/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Dec 11 12:55:54 2013 Nicolas Charvoz
** Last update Mon Dec 16 13:13:29 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include "../headers/minishell.h"
#include "../headers/my.h"

char	*epur_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (!str)
    return (0);
  while (str[++i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          str[j] = str[i];
          j++;
          if (str[i + 1] == ' ' || str[i + 1] == '\t')
            {
              str[j] = ' ';
              j++;
            }
        }
    }
  str[j] = '\0';
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}

int     count_word(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int     countchar(char *str)
{
  int   c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}

char	**str_to_wordtab(t_mini *mini, char *str)
{
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  mini->cmd = xmalloc(sizeof(char*) * ((count_word(str) + 1)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i] == ' ')
	    i++;
          a = a + 1;
          b = 0;
        }
      mini->cmd[a] = xmalloc(sizeof(char) * ((countchar(str + i) + 1)));
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        mini->cmd[a][b++] = str[i++];
      mini->cmd[a][b] = '\0';
    }
  mini->cmd[a + 1] = 0;
  a = 0;
  return(mini->cmd);
}
