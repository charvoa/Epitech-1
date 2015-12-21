/*
** make_list.c for  in /home/charvo_a/alias
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri May 23 16:31:46 2014 Nicolas Charvoz
** Last update Sat May 24 05:08:13 2014 Nicolas Charvoz
*/

#include "alias.h"

int	char_count(char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] != '=' && str[i])
    {
      count++;
      i++;
    }
  return (count);
}

t_alias			*insert_alias(t_alias *alias, char *cmd, char *args)
{
  t_alias		*a;
  t_alias		*tmp;
  int			i;

  i = 0;
  a = xmalloc(sizeof(*a));
  a->ali = xmalloc(3 * sizeof(char*));
  a->ali[i] = strdup(cmd);
  i++;
  a->ali[i] = strdup(args);
  a->next = NULL;
  if (alias == NULL)
    return (a);
  else
    {
      tmp = alias;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = a;
      return (alias);
    }
}

char	*clean_alias(char *args)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  j = 1;
  str = xcalloc((strlen(args) + 1), sizeof(char));
  while (args[i] != '\0')
    {
      str[i] = args[j];
      i++;
      j++;
    }
  str[i - 2] = '\0';
  return (str);
}

void	make_list(char **tab, t_alias **list)
{
  char	*cmd;
  char	*args;
  int	a;
  int	b;
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      b = 0;
      a = 0;
      cmd = xcalloc(char_count(tab[i]) + 1, sizeof(char));
      while (tab[i][b] != '=' && tab[i][b] != '\n')
	{
	  if ((check_letter(tab[i][b])) == 0 || tab[i][b] == '\'')
	      cmd[a++] = tab[i][b];
	  else
	    fprintf(stderr, "Unexpected token in alias list\n");
	  b++;
	}
      args= calloc(4096, sizeof(char));
      args = clean_alias(&tab[i][b + 1]);
      *list = insert_alias(*list, cmd, args);
      i++;
    }
}
