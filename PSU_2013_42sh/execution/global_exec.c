/*
** global_exec.c for 42sh in /home/heitzl_s/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Fri May 23 11:05:26 2014 heitzl_s
** Last update Wed May 28 13:01:31 2014 Nicolas Girardot
*/

#include <unistd.h>
#include "../parser/parser.h"
#include "execution.h"

int	global_prepa(t_cmd *cmd, int i)
{
  while (cmd[i].token != NULL && cmd[i].token[0] != ';')
    {
      if (!strncmp(cmd[i].token, ">>", 2) || !strncmp(cmd[i].token, ">", 1)
	  || !strncmp(cmd[i].token, "<<", 2) || !strncmp(cmd[i].token, "<", 1))
	redirections(&cmd[i], &cmd[i + 1], cmd, i);
      i++;
    }
  return (0);
}

void	semi_col(t_cmd *cmd, t_cmd *cmd2)
{
  cmd2->fdin = 0;
  cmd->fdout = 1;
}

int	prepa_semi_col(t_cmd *cmd, int i)
{
  while (cmd[i].token != NULL && cmd[i].token[0] != ';')
    {
      if (!strncmp(cmd[i].token, ";", 1))
	semi_col(&cmd[i], &cmd[i + 1]);
      else if (cmd[i].token == NULL)
	cmd[i].fdout = 1;
      i++;
    }
  return (0);
}

int	print(t_cmd *cmd)
{
  int   i;

  i = 0;
  while (cmd[i].token != NULL)
    i++;
  return (0);
}

int	global_exec(t_cmd *cmd, t_42sh *shell, int tok)
{
  int	i;

  i = 0;
  shell->tok = tok;
  while (shell->tok > 0)
    {
      global_prepa(cmd, i);
      prepa_pipes(cmd, i);

      prepa_semi_col(cmd, i);

      if (execution(cmd, shell, tok, i) == -42)
	return (-42);
      while (cmd[i].token != NULL && cmd[i].token[0] != ';')
	i++;
      i++;
    }
  check_signal(cmd->status);
  return (0);
}
