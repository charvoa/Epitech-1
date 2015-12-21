/*
** pars.c for  in /home/charvo_a/42/execution
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Tue May  6 15:05:52 2014 Nicolas Charvoz
** Last update Fri May 23 10:55:46 2014 heitzl_s
*/

#include "parser.h"
#include "../xlib/xlib.h"

int     countchar2(char *str)
{
  int   c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c++;
  return (c);
}

int     count_word2(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while ((str[i] != '\0') && (str[i] != '\n'))
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

void    parser2(char *str, t_cmd *cmd)
{
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  cmd->args = xmalloc((count_word2(str) + 1) * sizeof(char*));
   while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        while (str[i] == ' ')
          i++;
      if (str[i] != '\0')
        {
          cmd->args[a] = xmalloc(((countchar2(str + i) + 1)) * sizeof(char));
	  cmd->args[a] = memset(cmd->args[a], 0, ((countchar2(str + i) + 1)));
          while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
            cmd->args[a][b++] = str[i++];
          cmd->args[a][b] = '\0';
          a = a + 1;
          b = 0;
        }
    }
  cmd->args[a] = NULL;
}
