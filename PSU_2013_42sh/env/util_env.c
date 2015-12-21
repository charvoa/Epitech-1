/*
** util_env.c for util_env in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:46:55 2014 garcia antoine
** Last update Sun May 25 23:26:14 2014 Nicolas Charvoz
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"
#include "../xlib/xlib.h"

int	isolate_name_and_value_from_env(char *env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (env[i] == '=')
	return (i);
      i++;
    }
  return (0);
}

char	*get_name_from_env(char *env)
{
  int	size;
  char	*name;

  size = isolate_name_and_value_from_env(env);
  if ((name = strndup(env, size)) == NULL)
    return (NULL);
  return (name);
}

char	*get_value_from_env(char *env)
{
  char	*value;
  int	size;

  size = isolate_name_and_value_from_env(env);
  if ((value = strndup(env + (size + 1), strlen(env + size))) == NULL)
    return (NULL);
  return (value);
}

char		*get_env(char *name, t_dlist *env)
{
  t_node	*tmp;

  tmp = env->start;
  while (tmp)
    {
      if (strcmp(name, tmp->name) == 0)
	return (strdup(tmp->value));
      tmp = tmp->next;
    }
  return (NULL);
}

char	**list_to_tab(t_dlist *env)
{
  char	**tab;
  t_node *tmp;
  int	i;

  i = 0;
  tmp = env->start;
  tab = xmalloc((env->lenght + 1) * sizeof(char *));
  if (tab == NULL)
    return (NULL);
  while (tmp)
    {
      tab[i] = xmalloc(strlen(tmp->name) + strlen(tmp->value) + 2
		       * sizeof(char));
      tab[i] = strcpy(tab[i], tmp->name);
      tab[i] = strcat(tab[i], "=");
      tab[i] = strcat(tab[i], tmp->value);
      tmp = tmp->next;
      i++;
    }
  tab[i] = '\0';
  return (tab);
}
