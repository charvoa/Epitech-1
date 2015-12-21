/*
** epur_str.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:13:39 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:13:41 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/printf.h"
#include "../headers/my.h"

void    get_sigint(int sig)
{
  sig = sig;
  my_printf("\n");
}

void	my_memset(t_mini *mini)
{
  int	i;
  int	j;

  j = 0;
  i = -1;
  while (mini->current[++i] != NULL)
    mini->current[i][j++] = '\0';
}

char            *epur_str2(char *str)
{
  int           i;
  char          *str2;

  i = 0;
  str2 = xmalloc((my_strlen(str) + 1) * sizeof(char));
  while (*str)
    {
      while (*str == ' ' || *str == '\t')
        str++;
      while (*str != ' ' && *str != '\t' && *str)
        {
          str2[i++] = *(str++);
          str2[i] = 0;
        }
      if (*(str - 1) != ' ' && *(str - 1) != '\t')
        str2[i++] = ' ';
      if (*str == 0 && (str2[i - 1] == ' ' || str2[i - 1] == '\t'))
        str2[i - 1] = 0;
    }
  return (str2);
}

char    *epur_str(char *str)
{
  int   s;
  int   f;
  char  *tmp;
  int   j;

  j = 0;
  tmp = xmalloc(my_strlen(str) * sizeof(*tmp));
  s = 0;
  while (str[s] == ' ' || str[s] == '\t')
    s++;
  f = my_strlen(str);
  while (str[f] == '\n' || str[f] == '\0' || str[f] == ' ' || str[f] == '\t')
    f--;
  while (s <= f)
    tmp[j++] = str[s++];
  tmp[j] = '\0';
  return (tmp);
}
