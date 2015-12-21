/*
** func_my_cd.c for 42sh in /home/audibe_l/rendu/42sh/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Fri May 23 21:29:41 2014 louis audibert
** Last update Sat May 24 11:34:51 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

void		modif_path_to_root(t_dlist *env)
{
  t_node	*tmp;

  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strcpy(tmp->value, "/");
      tmp = tmp->next;
    }
}

int		cd_home(t_dlist *env, t_cmd *cmd, int i)
{
  if (check_access(env, cmd, i) == -1)
    return (-1);
  chdir(get_my_home(env));
  modif_oldpwd(get_env("PWD", env), env);
  modif_pwd_home(get_my_home(env), env);
  return (0);
}

char		*realloc_path(char *path, t_dlist *env)
{
  path = realloc(path, (strlen(path) + strlen(get_my_home(env)) + 2));
  path = strcat(get_my_home(env), path);
  return (path);
}

int		cd_tild(char **args, t_dlist *env, t_cmd *cmd, int i)
{
  char		*path;

  path = get_path_from_opt(args[1]);
  if (check_access(env, cmd, i) == -1)
    return (-1);
  chdir(get_my_home(env));
  if (strcmp(path, "\0") == 0)
    {
      modif_oldpwd(get_env("PWD", env), env);
      modif_pwd_from_home_to_path(args[1], env);
      return (0);
    }
  path = realloc_path(path, env);
  if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
    {
      if (access(path, F_OK) == -1)
	fprintf(stderr, "42sh: cd: No such file or directory\n");
      else
	print_permission_denied(cmd, i);
      return (-1);
    }
  chdir(path);
  modif_oldpwd(get_env("PWD", env), env);
  modif_pwd_from_home_to_path(args[1], env);
  return (0);
}

int		cd_dash(t_dlist *env, t_cmd *cmd, int i)
{
  if (access(get_old_pwd(env), F_OK) == -1
      || access(get_old_pwd(env), R_OK) == -1)
    {
      if (access(get_old_pwd(env), F_OK) == -1)
        fprintf(stderr, "42sh: cd: No such file or directory.\n");
      else
	print_permission_denied(cmd, i);
      return (-1);
    }
  chdir(get_old_pwd(env));
  modif_oldpwd(get_old_pwd(env), env);
  return (0);
}
