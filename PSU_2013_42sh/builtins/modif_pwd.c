/*
** modif_pwd.c for 42sh in /home/audibe_l/rendu/42sh/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Mon May 19 22:43:20 2014 louis audibert
** Last update Sat May 24 04:29:55 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

char		*clean_arg(char *arg)
{
  int		i;
  int		j;
  char		*clean_arg;

  clean_arg = xcalloc((strlen(arg) + 1), sizeof(char));
  i = 0;
  j = 0;
  while (arg[i] == '.' && arg[i + 1] == '.' && arg[i + 2] == '/')
    i += 3;
  if (arg[i] == '.' && arg[i + 1] == '.')
    i += 2;
  while (arg[i])
    {
      clean_arg[j] = arg[i];
      j++;
      i++;
    }
  clean_arg[j] = '\0';
  return (clean_arg);
}

void		modif_simple_pwd(char *arg, t_dlist *env)
{
  t_node        *tmp;
  char		*name;

  tmp = env->start;
  name = parse_name(arg, get_env("PWD", env));
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = name;
      tmp = tmp->next;
    }
}

void		modif_pwd_from_home_to_path(char *name, t_dlist *env)
{
  t_node        *tmp;
  char		*pwd;
  char		*pwd2;
  char		*home;

  pwd = calloc((strlen(name) + 1), sizeof(char));
  home = get_my_home(env);
  pwd = get_pwd_from_home(pwd, name, env);
  pwd2 = xcalloc(((strlen(home) + 1) + strlen(pwd) + 1), sizeof(char));
  home = realloc(home, strlen(home) + 1 + strlen(pwd) + 1);
  pwd2 = strcat(home, pwd);
  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strdup(pwd2);
      tmp = tmp->next;
    }
}

void		modif_pwd_home(char *name, t_dlist *env)
{
  t_node        *tmp;

  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strdup(name);
      tmp = tmp->next;
    }
}

int		modif_oldpwd(char *name, t_dlist *env)
{
  t_node	*tmp;
  char		*save;

  tmp = env->start;
  save = get_env("PWD", env);
  if (save == NULL)
    {
      printf("42sh: cd: OLDPWD not set\n");
      return (-1);
    }
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strdup(name);
      tmp = tmp->next;
    }
  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "OLDPWD"))
	tmp->value = strdup(save);
      tmp = tmp->next;
    }
  return (0);
}
