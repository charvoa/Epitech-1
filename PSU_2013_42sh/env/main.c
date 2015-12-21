/*
** main.c for main in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:20:14 2014 garcia antoine
** Last update Sun May 25 23:33:50 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include "42sh.h"
#include "listok.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	free_struct_shell(t_42sh *shell)
{
  if (shell->env->lenght > 0)
    free_my_list(shell->env);
  if (shell->cmd != NULL)
    free(shell->cmd);
  if (shell->path != NULL)
    free_tab(shell->path);
}

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  if ((check_pre()) == -1)
    return (-1);
  if (init_my_shell(&shell, env) == -1)
    return (-1);
  if (start_shell(&shell) == -42)
    return (shell.exit_value);
  free_struct_shell(&shell);
  return (0);
}
