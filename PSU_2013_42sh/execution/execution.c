/*
** pipes.c for pipes in /home/heitzl_s/test_zone/42/pipe
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May 14 15:05:12 2014 heitzl_s
** Last update Wed May 28 15:13:24 2014 heitzl_s
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

int	check_or_and(t_cmd *cmd, int i, t_42sh *shell)
{
  (void)shell;
  if (i > 0)
    {
      if (strcmp(cmd[i - 1].token, "||") == 0)
	{
	  i--;
	  while (cmd[i].type != 0)
	    i--;
	  if (cmd[i].status != 0)
	    return (0);
	  else
	    return (1);
	}
      else if (strcmp(cmd[i - 1].token, "&&") == 0)
	{
	  i--;
	  while (cmd[i].type != 0)
	    i--;
	  if (cmd[i].status != 0)
	    return (1);
	  else
	    return (0);
	}
    }
  return (0);
}

int	launch(t_cmd *cmd, t_42sh *shell, int i)
{
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      if (cmd[i].fdin == -1)
	exit(-1);
      else if (find_cmd(cmd[i].args[0]) != -1)
      	exit(42);
      else if (check_pipe_cmd(&cmd[i], shell) == -1)
      	{
      	  fprintf(stderr, "Command not found : %s\n", cmd[i].args[0]);
      	  exit(-1);
      	}
      if (check_or_and(cmd, i, shell) == 1)
	exit(-1);
      xdup2(cmd[i].fdout, 1);
      xdup2(cmd[i].fdin, 0);
      check_and_close_son(cmd, i);
      if (exec_cmd(&cmd[i], shell) == -1)
	fprintf(stderr, "Command not found : %s\n", cmd->args[0]);
      exit(pid);
    }
  return (pid);
}

int	waiting_process(t_cmd *cmd)
{
  int	i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      waitpid(cmd[i].pid, &cmd[i].status, 0);
      i++;
    }
  waitpid(cmd[i].pid, &cmd[i].status, 0);
  return (0);
}

int	execution(t_cmd *cmd, t_42sh *shell, int tok, int i)
{
  int	mabool;

  mabool = 0;
  (void)tok;
  if (cmd[i].token != NULL && (strcmp(cmd[i].token, ";") != 0))
    {
      while (cmd[i].token != NULL && (strcmp(cmd[i].token, ";") != 0))
	{
	  if (start_execution(cmd, shell, i) == -42)
	    return (-42);
	  mabool = 1;
	  shell->tok--;
	  i++;
	}
    }
  if (mabool == 1)
    {
      if (start_execution(cmd, shell, i) == -42)
	return (-42);
      shell->tok--;
      i++;
    }
  else
    {
      if (start_execution(cmd, shell, i) == -42)
	return (-42);
      shell->tok--;
      i++;
    }
  waiting_process(cmd);
  return (0);
}
