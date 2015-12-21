/*
** parser.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:14:18 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:14:19 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/my.h"
#include "../headers/printf.h"

int     countchar(char *str)
{
  int   c;
  c = -1;
  while ((str[++c] != ';') && (str[++c] != '\0') && (str[++c] != '\n'));
  c++;
  return (c);
}

int     count_word(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while ((str[i] != '\0') && (str[i] != '\n'))
    {
      if (str[i] == ';' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

void    parser(t_mini *mini)
{
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  mini->cmd = xmalloc(sizeof(char*) * ((count_word(mini->cmdr) + 1)));
  while (mini->cmdr[i] != '\n' && mini->cmdr[i] != '\0')
    {
      if (mini->cmdr[i] == ';' || mini->cmdr[i] == '\n')
        {
          while (mini->cmdr[i] == ';')
	    i++;
	  a = a + 1;
          b = 0;
        }
      mini->cmd[a] = xmalloc(sizeof(char) * ((countchar(mini->cmdr + i) + 1)));
      while ((mini->cmdr[i] != ';')  && (mini->cmdr[i] != '\n')
	     && (mini->cmdr[i] != '\0'))
	mini->cmd[a][b++] = mini->cmdr[i++];
      mini->cmd[a][b] = '\0';
    }
  mini->cmd[a + 1] = 0;
  a = 0;
}
