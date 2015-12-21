/*
** main.c for 42sh in /home/heitzl_s/42/alias
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 00:49:48 2014 heitzl_s
** Last update Sun May 25 19:37:51 2014 Nicolas Charvoz
*/

#include "alias.h"
#include "../xlib/xlib.h"

void	init_pwd_alias(t_42sh *shell)
{
  if (shell->pwd_alias == NULL
      && (shell->pwd_alias = get_env("PWD", shell->env)) != NULL)
    {
      shell->pwd_alias = realloc(shell->pwd_alias,
				 (strlen(shell->pwd_alias) + 13));
      strcat(shell->pwd_alias, "/alias/alias");
    }
}

t_token		**alias(t_token **token, t_42sh *shell)
{
  int		fd;
  int		ret;
  char		*buffer;
  char		*final;
  char		**tab;
  t_alias	*list;

  list = NULL;
  init_pwd_alias(shell);
  buffer = xcalloc(4096, sizeof(char));
  final = xcalloc(4096, sizeof(char));
  if ((fd = xopen_alias(shell->pwd_alias, O_RDONLY | O_APPEND)) == -1)
    return (token);
  while ((ret = read(fd, buffer, 4096)) != 0)
    {
      final = realloc(final, strlen(buffer) + 4097);
      strcat(final, buffer);
      memset(buffer, 0, 4096);
    }
  tab = str_to_word_tab(final, '\n');
  make_list(tab, &list);
  token = check_list(&list, token);
  return (token);
}
