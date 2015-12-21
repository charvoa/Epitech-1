/*
** mini.c for mini.c in /home/charvo_a/rendu/Minishell/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Dec 11 12:56:34 2013 Nicolas Charvoz
** Last update Mon Jan  6 15:37:27 2014 Nicolas Charvoz
*/

#define READ_SIZE 4096
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../headers/minishell.h"
#include "../headers/my.h"

void	get_sigint(int sig)
{
  my_printf("\n[user] ~ $>");
}

int	do_cmd(char **av, t_mini *mini)
{
  int	i;
  pid_t	pid;
  int	status;
  char	*pass;

  i = -1;
  if ((pid = fork()) == -1)
    exit(-1);
  else if (pid == 0)
    {
      signal(SIGINT, get_sigint);
      while (mini->tab[++i])
	{
	  pass = strcat(mini->tab[i], mini->cmd[0]);
	  if (execve(pass, mini->cmd, mini->env) != -1)
	    return(0);
	}
      my_printf("%s: Command not found\n", mini->cmd[0]);
      exit(0);
    }
  else
    wait(&status);
}

int	check_path(char **envp)
{
  int	flag;
  int	i;

  i = 0;
  flag = 0;
  while (envp[i] != NULL )
    {
      if (my_strncmp("PATH=", envp[i], 5) == 0)
	{
	  flag = 1;
	}
      i++;
    }
  if (flag == 0)
    {
      my_printf("PATH is not set\n");
      exit(0);
    }
  return (flag);
}

void	getpath(t_mini *mini, char **envp)
{
  int	i;
  int	ret;
  int	flag;

  flag = check_path(envp);
  ret = 0;
  i = 0;
  while (mini->env[i] != NULL)
    {
      if ((ret = (my_strncmp("PATH=", mini->env[i], 5))) == 0)
	{
	  strtotab(mini, mini->env[i]);
	}
      i++;
    }
}

int    aff_prompt(char **av, t_mini *mini)
{
  char	*cmdnon;
  char	*cmd;
  int	ret;

  cmdnon = xmalloc(READ_SIZE * sizeof(char));
  cmd = xmalloc(READ_SIZE * sizeof(char));
  my_printf("[user] ~ $> ");
  if ((ret = (read(0, cmdnon, READ_SIZE))) != -1)
    {
      if (ret == 0)
	{
	  my_putchar('\n');
	  exit(0);
	}
      if ((check_space(cmdnon)) == 0)
	return (0);
      cmd = epur_str(cmdnon);
      mini->cmd = str_to_wordtab(mini, cmd);
      if ((builtin(cmd, mini) == 1))
	return (0);
      do_cmd(av, mini);
    }
  else
    my_printf("\n[user] ~ $>");
}
