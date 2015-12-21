/*
** my_exit.c for 42sh in /home/girard_s/rendu/42bis/builtins
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Fri May 23 22:18:14 2014 Nicolas Girardot
** Last update Sat May 24 12:49:37 2014 Nicolas Charvoz
*/

#include "builtins.h"

int	test_error_on_exit(char **args)
{
  int	i;

  i = 0;
  if (args[1] == NULL)
    return (0);
  while (args[1][i] != '\0')
    {
      if (args[1][i] < '0' || args[1][i] > '9')
	{
	  printf("42sh: exit: %s: numeric argument required\n", args[1]);
	  return (-1);
	}
      else
	i++;
    }
  return (atoi(args[1]));
}

int	my_exit(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  int	result;

  (void)env;
  result = test_error_on_exit(cmd[i].args);
  if (result == 0)
    {
      free_my_list(shell->env);
      free_tab(shell->path);
      free_tab(shell->envtab);
      shell->exit_value = 0;
      return (-42);
    }
  else if (result == -1)
    return (0);
  shell->exit_value = result;
  return (-42);
}
