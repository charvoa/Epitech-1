/*
** my_cd.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:14:03 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:14:04 2014 Nicolas Charvoz
*/

#include "../headers/minishell.h"
#include "../headers/my.h"
#include "../headers/printf.h"

void	aff_env(char **env)
{
  int   i;

  i = 0;
  while (env)
    my_printf("%s\n", env[i++]);
}

char    *get_home(char **env)
{
  int   i;
  int   j;
  int   k;
  int	flag;
  char  *str;

  i = 0;
  flag = 0;
  str = xmalloc(4096 * sizeof(char));
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "HOME=", 5) == 0)
        {
          flag = 1;
          j = 5;
          k = 0;
          while (env[i][j] != '\0')
            str[k++] = env[i][j++];
        }
      i++;
    }
  if (flag == 0)
    chdir("/");
  return (str);
}

void	my_cd(char *arg, char **env)
{
  char  *home;

  home = get_home(env);
  if (arg == 0)
    chdir(home);
  else
    if (chdir(arg) == -1)
      my_printf("cd: No such file or directory\n");
  free(home);
}
