/*
** init.c for 42sh in /home/heitzl_s/42/env
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Fri May 23 10:38:49 2014 heitzl_s
** Last update Sun May 25 20:04:09 2014 Nicolas Girardot
*/

#include <stdlib.h>
#include "42sh.h"
#include "../xlib/xlib.h"

t_dlist	*create_my_env(t_dlist *shell, char **environ)
{
  int		i;
  char		*name;
  char		*value;

  i = 0;
  if ((shell = create_list()) == NULL)
    return (NULL);
  while (environ[i])
    {
      name = get_name_from_env(environ[i]);
      value = get_value_from_env(environ[i]);
      put_in_list(shell, name, value);
      free(name);
      free(value);
      i++;
    }
  return (shell);
}

char    *path_in_cache()
{
  char  *path;

  path = xmalloc(4096 * sizeof(char));
  path = strcpy(path, "/bin/");
  path = strcat(path, ":");
  path = strcat(path, "/usr/bin");
  path = strcat(path, "\0");
  return (path);
}

int	init_my_shell(t_42sh *shell, char **env)
{
  char	*path;

  shell->env = create_my_env(shell->env, env);
  if (shell->env == NULL)
    return (-1);
  path  = get_env("PATH", shell->env);
  if (path == NULL)
    path = path_in_cache();
  shell->path = strtotab(path);
  shell->envtab = list_to_tab(shell->env);
  return (0);
}
