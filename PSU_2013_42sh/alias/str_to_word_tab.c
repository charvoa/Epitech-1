/*
** str_to_word_tab.c for  in /home/charvo_a/colle/colle3
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:42:34 2014 Nicolas Charvoz
** Last update Sun May 25 19:34:30 2014 Nicolas Charvoz
*/

#include "alias.h"

int	count_word3(char *str, char delim)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i])
    {
      while (str[i] != delim && str[i])
	i++;
      i++;
      count++;
    }
  return (count);
}

int	count_char3(char *str, int i, char delim)
{
  while (str[i] != delim && str[i] != '\0')
    i++;
  return (i);
}

char    **str_to_word_tab(char *str, char delim)
{
  int   i;
  int   b;
  int   a;
  char	**tab;

  b = 0;
  i = 0;
  a = 0;
  tab = xmalloc(sizeof(char*) * ((count_word3(str, delim) + 4)));
  while (str[i] != '\0')
    {
      if (str[i] == delim)
	{
          while (str[i] == delim)
            i++;
          a = a + 1;
          b = 0;
	}
      tab[a] = xcalloc(((count_char3(str, i, delim) + 1)), sizeof(char));
      while ((str[i] != delim)  && (str[i] != '\0'))
	tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a] = NULL;
  return (tab);
}
