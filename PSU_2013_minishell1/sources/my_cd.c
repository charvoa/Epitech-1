/*
** my_cd.c for mycd in /home/charvo_a/rendu/PSU_2013_minishell1/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Dec 13 15:26:37 2013 Nicolas Charvoz
** Last update Mon Dec 16 12:36:35 2013 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../headers/minishell.h"

char    *get_home(char **env)
{
  int   i;
  int   j;
  int   k;
  char  *str;
  int   flag;

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

int     my_cd(char *arg, char **env)
{
  char  *home;

  home = get_home(env);
  if (arg == 0)
    chdir(home);
  else
    {
      if (chdir(arg) == -1)
        my_printf("cd: No such file or directory\n");
    }
  free(home);
}
