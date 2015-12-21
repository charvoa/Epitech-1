/*
** minishell.h for  in /home/charvo_a/rendu/PSU_2013_minishell2/headers
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:10:54 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:12:37 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

typedef	struct	s_mini
{
  char	**env;
  char	**tab;
  char	*cmdrnon;
  char	*cmdr;
  char	**cmd;
  char	**current;
}		t_mini;

/*AFF_PROMPT.C */
int	do_cmd(t_mini*);
void	aff_prompt(t_mini*);
int	check_builtin(t_mini*);
/*EPUR_STR.C*/
void	get_sigint(int);
void	my_memset(t_mini*);
char	*epur_str(char*);
char	*epur_str2(char*);
/*MAIN.C*/
int	check_path(char**);
void	getpath(t_mini*, char**);
void	my_env(char**, t_mini*);
/*PARSER2.C*/
int	countchar2(char*);
int	count_word2(char*);
void	parser2(char*, t_mini*);
/*PARSER.C*/
int	countchar(char*);
int	count_word(char*);
void	parser(t_mini*);
/*STRTOTAB.C*/
int	count_char(char*);
int	countword(char*);
void	strtotab(t_mini*, char*);
/*XFILES.C*/
int	xread(int, char*, int);
void	*xmalloc(int);
/*MY_CD.C */
void	aff_env(char**);
char	*get_home(char**);
void	my_cd(char*, char**);

#endif
