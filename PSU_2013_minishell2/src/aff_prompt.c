/*
** aff_prompt.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:13:29 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:13:32 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/my.h"
#include "../headers/printf.h"
# define READ_SIZE 4096

int	check_builtin(t_mini *mini)
{
  if (my_strcmp("cd", mini->current[0]) == 0)
    {
      my_cd(mini->current[1], mini->env);
      return (0);
    }
  else if (my_strcmp(mini->current[0], "env") == 0)
    {
      aff_env(mini->env);
      return (0);
    }
  else if (my_strncmp("exit", mini->current[0], 4) == 0)
    exit(0);
  return (-1);
}

int	do_cmd(t_mini *mini)
{
  int	i;
  int	status;
  pid_t	pid;
  char	*pass;

  if (check_builtin(mini) == 0)
    return(0);
  i = -1;
  if ((pid = fork()) == -1)
    exit(-1);
  else if (pid == 0)
    {
      while (mini->tab[++i])
	{
	  pass = my_strcat(mini->tab[i], mini->current[0]);
	  if (execve(pass, mini->current, mini->env) != -1)
	    return(0);
	}
      my_printf("%s: Command not found\n", mini->current[0]);
      exit(0);
    }
  else
    wait(&status);
  return (0);
}

void	aff_prompt(t_mini *mini)
{
  int	i;

  i = 0;
  mini->cmdrnon = xmalloc(READ_SIZE * sizeof(char));
  mini->cmdr = xmalloc(READ_SIZE * sizeof(char));
  my_printf("[user] ~ $> ");
  signal(SIGINT, get_sigint);
  if ((xread(0, mini->cmdrnon, READ_SIZE)) == 0)
    {
      my_printf("\n");
      exit(0);
    }
  mini->cmdr = epur_str(mini->cmdrnon);
  mini->cmdr = epur_str2(mini->cmdr);
  parser(mini);
  while (mini->cmd[i] != NULL)
    {
      parser2(mini->cmd[i], mini);
      do_cmd(mini);
      my_memset(mini);
      i++;
    }
}
