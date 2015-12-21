/*
** alias.h for  in /home/charvo_a/alias
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri May 23 16:24:54 2014 Nicolas Charvoz
** Last update Sun May 25 19:09:12 2014 Nicolas Charvoz
*/

#ifndef ALIAS_H_
# define ALIAS_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../lexer/lexer.h"
# include "../xlib/xlib.h"

typedef	struct		s_alias
{
  char			**ali;
  struct  s_alias	*next;
}			t_alias;

/* STR_TO_WORD_TAB.C */
int	count_word3(char*, char);
int	count_char3(char*, int, char);
char	**str_to_word_tab(char*, char);

/* MAKE_LIST.C */
int	char_count(char*);
void	make_list(char**, t_alias**);

/* CHECK_LIST.C */
t_token **check_list(t_alias**, t_token**);

/* MAIN.C */
t_token	**alias(t_token**, t_42sh*);

#endif
