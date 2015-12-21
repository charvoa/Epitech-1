/*
** check_access.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Sat May 24 06:10:26 2014 louis audibert
** Last update Sat May 24 11:21:12 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

void	print_permission_denied(t_cmd *cmd, int i)
{
  cmd[i].status = 42;
  fprintf(stderr, "42sh: cd: Permission Denied\n");
}

int	check_access(t_dlist *env, t_cmd *cmd, int i)
{
  if (access(get_my_home(env), F_OK) == -1
      || access(get_my_home(env), R_OK) == -1)
    {
      if (access(get_my_home(env), F_OK) == -1)
        fprintf(stderr, "42sh: cd: No such file or directory.\n");
      else
	print_permission_denied(cmd, i);
      return (-1);
    }
  return (0);
}
