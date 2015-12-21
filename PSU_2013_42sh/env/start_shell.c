/*
** start_shell.c for start_shell in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Apr  7 16:15:48 2014 garcia antoine
** Last update Wed May 28 01:21:12 2014 Nicolas Charvoz
*/

#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <term.h>
#include <curses.h>
#include "42sh.h"
#include "listok.h"
#include "../lexer/lexer.h"
#include "../xlib/xlib.h"
#include "../termcaps/termcaps.h"

t_42sh	shell;

int	check_none_cmd(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] == '|' || str[i] == '<' || str[i] == '>'
	   || str[i] == ';' || str[i] == '&')
	  && str[i + 1] == ' ' && (str[i + 2] == '|' || str[i + 2] == '<'
				|| str[i + 2] == '>' || str[i + 2] == ';'
				   || str[i + 2] == '&'))
	{
	  str[i + 1] = str[i];
	  fprintf(stderr, "NULL is not a command\n");
	  return (-1);
	}
      i++;
    }
  return (0);
}

void	get_sigint(int sig)
{
  sig = sig;
  printf("\n");
  prompt(&shell);
}

char	*read_line()
{
  int	nb;
  char	*cmd;
  char	*buffer;

  buffer = xcalloc(4096, sizeof(char));
  nb = xread(0, buffer, 4096);
  if (nb == 0)
    {
      puts("exit");
      return ("exit");
    }
  buffer[nb - 1] = '\0';
  cmd = strdup(buffer);
  free(buffer);
  cmd = epur_str(cmd);
  if ((check_none_cmd(cmd)) == -1)
    return (cmd);
  else
    return (cmd);
}

int		start_shell(t_42sh *shell)
{
  t_token	*token;

  while (1)
    {
      token = NULL;
      signal(SIGINT, get_sigint);
      prompt(shell);
      shell->cmd = read_line();
      if (lexer(shell->cmd, &token, shell) == -42)
	return (-42);
      free_my_tok(token);
    }
  return (0);
}
