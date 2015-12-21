/*
** listok.h for  in /home/charvo_a/42/env
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 16:32:17 2014 Nicolas Charvoz
** Last update Mon Apr 28 10:01:23 2014 Nicolas Charvoz
*/

#ifndef LISTOK_H_
# define LISTOK_H_

typedef struct s_token
{
  int           type;
  char          *value;
  int		pos;
  struct s_token *next;
}               t_token;

t_token *insert(t_token *, int, char *, int);
t_token	*free_my_tok(t_token *token);
int	show_token(t_token *token);

#endif /* LISTOK_H_ */
