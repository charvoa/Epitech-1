/*
** 42sh.h for 42sh in /home/heitzl_s/test_zone/42/env
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 02:52:12 2014 heitzl_s
** Last update Wed May 28 12:03:42 2014 Nicolas Girardot
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <stdio.h>
# include "./libsources/my.h"
# include "list.h"

typedef struct s_42sh
{
  t_dlist	*env;
  char		*cmd;
  char		**path;
  char		**envtab;
  char		*pwd_alias;
  int		exit_value;
  int		tok;
}		t_42sh;

extern	t_42sh	shell;

int	isolate_name_and_value_from_env(char *env);
char	*get_name_from_env(char *env);
char	*get_value_from_env(char *env);
char	*get_env(char *name, t_dlist *env);
char	**list_to_tab(t_dlist *env);
void    prompt(t_42sh*);
int	start_shell(t_42sh *shell);
int	init_my_shell(t_42sh *shell, char **env);
char	**strtotab(char*);
int	count_word(char*);
int	count_char(char*);
t_dlist *create_my_env(t_dlist *, char **);
void	get_sigint(int);
void	free_tab(char**);
int	check_pre();

#endif /*SHELL_H_ */
