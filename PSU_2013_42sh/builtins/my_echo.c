/*
** my_echo.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  8 11:33:49 2014 louis audibert
** Last update Wed May 28 15:20:47 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

int	echo_from_var_env(char *opt, t_dlist *env, t_cmd *cmd, int i)
{
  char	*path;
  int	x;
  int	j;

  x = 1;
  j = 0;
  path = xmalloc(strlen(opt) * sizeof(char));
  memset(path, 0, strlen(opt));
  while (opt[x])
    {
      path[j] = opt[x];
      j++;
      x++;
    }
  path = get_env(path, env);
  if (path == NULL)
    return (-1);
  write(cmd[i].fdout, path, (strlen(path)));
  return (0);
}

char	**init_echo(char **tab)
{
  int	i;

  i = 0;
  while (i < 10)
    tab[i++] = malloc(3 * sizeof(char));
  tab[0][0] = '\\';
  tab[0][1] = '\0';
  tab[1][0] = '\a';
  tab[1][1] = '\0';
  tab[2][0] = '\b';
  tab[2][1] = '\0';
  tab[3][0] = '\e';
  tab[3][1] = '\0';
  tab[4][0] = '\f';
  tab[4][1] = '\0';
  tab[5][0] = '\n';
  tab[5][1] = '\0';
  tab[6][0] = '\r';
  tab[6][1] = '\0';
  tab[7][0] = '\t';
  tab[7][1] = '\0';
  tab[8][0] = '\v';
  tab[8][1] = '\0';
  tab[9] = NULL;
  return (tab);
}

int     echo_with_backslash(char *opt, int fd)
{
  int   i;
  int	j;
  int	k;
  char	**tab;
  char	*test;
  char	*str;

  i = 0;
  j = 0;
  k = 0;
  test = "\\abefnrtv";
  tab = malloc(10 * sizeof(char*));
  str = calloc((strlen(opt) - 1), sizeof(char));
  tab = init_echo(tab);
  while (opt[i])
    {
      if (opt[i] == '\\')
        {
	  i++;
	  while (test[j])
	    {
	      if (test[j] == opt[i])
		str[k++] = tab[j][0];
	      j++;
	    }
	  i++;
        }
      str[k++] = opt[i++];
    }
  write(fd, str, strlen(str));
  return (0);
}


int	my_echo(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  int	x;
  int	flag;

  (void)shell;
  x = 1;
  flag = 0;
  while (cmd[i].args[x])
    {
      if (cmd[i].args[x][0] == '$')
	echo_from_var_env(cmd[i].args[x], env, cmd, i);
      else if (cmd[i].args[x][0] == '-' && cmd[i].args[x][1] == 'n' && cmd[i].args[x][2] == '\0')
	flag = 1;
      else if (cmd[i].args[x][0] == '-' && cmd[i].args[x][1] == 'e' && cmd[i].args[x][2] == '\0')
	{
	  echo_with_backslash(cmd[i].args[x + 1], cmd[i].fdout);
	  break;
	}
      else
	{
	  write(cmd[i].fdout, cmd[i].args[x], (strlen(cmd[i].args[x])));
	  if (cmd[i].args[x + 1] != NULL)
	    write(cmd[i].fdout, " ", strlen(" "));
	}
      x++;
    }
  if (flag == 0)
    write(cmd[i].fdout, "\n", strlen("\n"));
  return (0);
}
