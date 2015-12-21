/*
** close_functions.c for 42sh in /home/heitzl_s/test_zone/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May 22 13:54:57 2014 heitzl_s
** Last update Tue May 27 16:32:13 2014 heitzl_s
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "../pipe/pipe.h"
#include "../xlib/xlib.h"
#include "../builtins/builtins.h"
#include "execution.h"

int     check_and_close_son(t_cmd *cmd, int i)
{
  if (cmd[i].close_fd == 0 && cmd[i].fdout != 1)
    xclose(cmd[i + 1].fdin);
  else if (cmd[i].close_fd == 1)
    xclose(cmd[i - 1].fdout);
  else if (cmd[i].close_fd == 2)
    {
      xclose(cmd[i - 1].fdout);
      xclose(cmd[i + 1].fdin);
    }
  return (0);
}

int	check_and_close_father(t_cmd *cmd, t_42sh *shell, int i)
{
  int	result;

  if ((result = check_builtins(shell, cmd, shell->env, i)) == 1);
  else if (result == -42)
    return (-42);
  else
    {
      cmd[i].pid = launch(cmd, shell, i);
      if (cmd[i].close_fd == 1)
        xclose(cmd[i - 1].fdout);
      else if (cmd[i].close_fd == 2)
        {
          xclose(cmd[i - 1].fdout);
          xclose(cmd[i].fdin);
        }
    }
  return (0);
}

int	which_one_to_close(t_cmd *cmd, int i)
{
  if (cmd[i].fdin == 0 || i == 0 || (strcmp(cmd[i - 1].token, ";") == 0))
    return (0);
  else if (cmd[i].fdout == 1)
    return (1);
  else
    return (2);
}
