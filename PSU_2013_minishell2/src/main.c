/*
** main.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:13:53 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:13:55 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/my.h"
#include "../headers/printf.h"

int	check_path(char **envp)
{
  int	flag;
  int	i;

  i = 0;
  flag = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp("PATH=", envp[i], 5) == 0)
	flag = 1;
      i++;
    }
  if (flag == 0)
    {
      my_printf("PATH is not set\n");
      exit(-1);
    }
  return (flag);
}

void	getpath(t_mini *mini, char **envp)
{
  int	i;
  int	ret;
  int	flag;

  if ((flag = check_path(envp)) == 1)
    {
      ret = 0;
      i = 0;
      while (mini->env[i] != NULL)
	{
	  if ((ret = (my_strncmp("PATH=", mini->env[i], 5))) == 0)
	    strtotab(mini, mini->env[i]);
	  i++;
	}
    }
}

void	my_env(char **envp, t_mini *mini)
{
  int	i;
  int	j;

  j = 0;
  i = -1;
  mini->env = xmalloc(200 * sizeof(char*));
  while (envp[++i] != NULL)
    {
      mini->env[j] = xmalloc((my_strlen(envp[i]) + 1) * sizeof(char));
      my_strcpy(mini->env[j], envp[i]);
      j++;
    }
  mini->env[j] = NULL;
}

int		main(int ac, char **av, char **envp)
{
  t_mini	*mini;
  (void)	ac;
  (void)	av;

  mini = malloc(sizeof(*mini));
  my_env(envp, mini);
  getpath(mini, envp);
  while(1)
    aff_prompt(mini);
  return (0);
}
