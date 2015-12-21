/*
** builtin.c for builtin in /home/charvo_a/rendu/PSU_2013_minishell1/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Tue Dec 17 11:39:49 2013 Nicolas Charvoz
** Last update Tue Dec 17 17:30:38 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../headers/minishell.h"
#include "../headers/my.h"

int	aff_env(t_mini *mini)
{
  int	i;

  i = 0;
  while (mini->env)
    my_printf("%s\n", mini->env[i++]);
}

int	builtin(char *cmd, t_mini *mini)
{
  if ((my_strcmp("exit\n", cmd)) == 0)
    exit(0);
  else if ((my_strncmp(cmd, "./", 2)) == 0)
    {

    }
  else if ((my_strcmp("cd", mini->cmd[0])) == 0)
    {
      my_cd(mini->cmd[1], mini->env);
      return (1);
    }
  else
    return (0);
}
