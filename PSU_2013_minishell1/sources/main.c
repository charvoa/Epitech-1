/*
** main.c for main minishell in /home/charvo_a/rendu/Minishell/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Dec 12 10:41:31 2013 Nicolas Charvoz
** Last update Mon Dec 16 15:12:29 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../headers/minishell.h"

void	my_env(char **envp, t_mini *mini)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  mini->env = xmalloc(200 * sizeof(char *));
  while (envp[i] != NULL)
    {
      mini->env[j] = xmalloc((strlen(envp[i]) + 1) * sizeof(char));
      my_strcpy(mini->env[j], envp[i]);
      j++;
      i++;
    }
  mini->env[j] = NULL;
}

int     main(int ac, char **av, char **envp)
{
  t_mini        mini;

  my_env(envp, &mini);
  getpath(&mini, envp);
  while (1)
    {
      signal(SIGINT, get_sigint);
      aff_prompt(av, &mini);
    }
}
