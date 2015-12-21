/*
** parser2.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:14:11 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:14:12 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/printf.h"
#include "../headers/my.h"

int     countchar2(char *str)
{
  int   c;
  c = -1;
  while ((str[++c] != ' ') && (str[++c] != '\0') && (str[++c] != '\n'));
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

void    parser2(char *str, t_mini* mini)
{
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  mini->current = xmalloc(sizeof(char*) * ((count_word2(str) + 1)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
	while (str[i] == ' ')
	  i++;
      if (str[i] != '\0')
	{
	  mini->current[a] = xmalloc(sizeof(char) * ((countchar2(str + i) + 1)));
	  while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
	    mini->current[a][b++] = str[i++];
	  mini->current[a][b] = '\0';
	  a = a + 1;
          b = 0;
	}
    }
  mini->current[a + 1] = 0;
  a = 0;
}
