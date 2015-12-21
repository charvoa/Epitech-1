/*
** lexer.h for  in /home/charvo_a/Work/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat Apr  5 15:42:30 2014 Nicolas Charvoz
** Last update Sun May 25 12:31:16 2014 Nicolas Charvoz
*/

#ifndef _LEXER_H_
#define _LEXER_H_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../env/42sh.h"
#include "../env/listok.h"

typedef	enum	s_tok
  {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_COMMA,
    TOKEN_RED_L,
    TOKEN_RED_R,
    TOKEN_DBL_L,
    TOKEN_DBL_R,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NONE,
    TOKEN_UNK,
    TOKEN_END
  }		e_token;

typedef	struct s_lex
{
  char		*cmd;
}		t_lex;

/* LEXER.C */
int	unk_check(char*, int, t_token**);
int	word_check(char*, int, t_token**);
int	lex(char*, t_token**);
int	lexer(char*, t_token**, t_42sh*);
/* USELESS.C */
void	lexer_test(char*);
/* CHECK1.C */
int	check_letter(char c);
int	red_r(char*, int, t_token**);
int	red_l(char*, int, t_token**);
int	comma_check(char*, int, t_token**);
int	pipe_check(char*, int, t_token**);
/*  CHECK2.C */
int	check_and(char*, int, t_token**);
int	check_letter2(char);
int	check_error_none(t_token**);
int	check_none(char*, int, t_token**);
/* EPUR_STR.C */
char	*epur_str(char*);
char	*epur_str2(char*, char*, int, int);
#endif
