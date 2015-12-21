/*
** exec_new_redir.c for 42sh in /home/heitzl_s/test_zone/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 08:07:16 2014 heitzl_s
** Last update Wed May 28 15:13:26 2014 heitzl_s
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "execution.h"
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "../pipe/pipe.h"
#include "../xlib/xlib.h"
#include "../builtins/builtins.h"

int     exec_redir(t_cmd *cmd, int i)
{
  char  *buffer;

  buffer = xcalloc(4096, sizeof(*buffer));
  if (cmd[i].type == 1)
    {
      if (strcmp(cmd[i - 1].token, "<<") == 0)
	remove(cmd[i].args[0]);
      else if (cmd[i].type == 1 && cmd[i - 1].type == 1)
	{
	  if ((strcmp(cmd[i - 1].token, ">") == 0)
	      || (strcmp(cmd[i - 1].token, ">>") == 0))
	    {
	      xread(cmd[i - 1].fdout, buffer, 4095);
	      write(cmd[i].fdin, buffer, (strlen(buffer) + 1));
	      xclose(cmd[i - 1].fdout);
	      return (1);
	    }
	}
    }
  return (0);
}

int	start_execution(t_cmd *cmd, t_42sh *shell, int i)
{
  cmd[i].close_fd = which_one_to_close(cmd, i);
  if (cmd[i].type == 0)
    {
      if (check_and_close_father(cmd, shell, i) == -42)
	return (-42);
    }
  else
    exec_redir(cmd, i);
  if (cmd[i].token != NULL && (strcmp(cmd[i].token, "||") == 0
			       || strcmp(cmd[i].token, "&&") == 0))
    waitpid(cmd[i].pid, &cmd[i].status, 0);
  else if (i > 0 && (strcmp(cmd[i - 1].token, "|") != 0))
    waitpid(cmd[i].pid, &cmd[i].status, 0);
  check_signal(cmd[i].status);
  return (0);
}
