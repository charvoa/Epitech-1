/*
** struct_fill.c for 42sh in /home/heitzl_s/42
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 27 11:45:11 2014 heitzl_s
** Last update Tue May 27 11:45:12 2014 heitzl_s
*/

#include "parser.h"
#include "../execution/execution.h"
#include "../xlib/xlib.h"

void	init_struct(t_cmd *cmd)
{
  cmd->type = 0;
  cmd->status = 0;
  cmd->fdin = 0;
  cmd->fdout = 0;
}

void	fill_it(t_cmd *cmd, char *str, char *sep)
{
  parser2(str, cmd);
  if (sep != NULL)
    cmd->token = strdup(sep);
  else if (sep == NULL)
    cmd->token = NULL;
   if (sep != NULL)
     free(sep);
}

int		last_token(t_token **token)
{
  t_token       *tok;
  int           type;

  tok = xmalloc(sizeof(*tok));
  tok = *token;
  type = 0;
  while (tok)
    {
      type = tok->type;
      tok = tok->next;
    }
  return (type);
}

int             nbr_of_token(t_token **token)
{
  t_token       *tok;
  int           i;

  tok = xmalloc(sizeof(*tok));
  if (last_token(token) == 2)
    i = 0;
  tok = *token;
  while (tok)
    {
      if (tok->type > 0)
	i = i + 1;
      tok = tok->next;
    }
  return (i);
}

int		struct_fill(char **tab, t_token **token, t_42sh *shell)
{
  t_cmd		*cmd;
  int		i;
  int		j;
  int		count;

  j = 0;
  i = 0;
  count = nbr_of_token(token);
  cmd = xcalloc((count + 1), sizeof(*cmd));
  while (tab[i])
    {
      if (tab[i + 1] == NULL)
	 {
	   fill_it(&cmd[j], tab[i], NULL);
	   if (global_exec(cmd, shell, count + 1) == -42)
	     return (-42);
	   return (0);
	 }
      fill_it(&cmd[j++], tab[i], tab[i + 1]);
      i += 2;
    }
  if (global_exec(cmd, shell, count) == -42)
    return (-42);
  return (0);
}
