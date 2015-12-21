/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
** Last update Sat May 24 00:14:45 2014 Nicolas Girardot
*/

#include "parser.h"
#include "../xlib/xlib.h"

char		*check_token(t_token **token, t_lex *lexi)
{
  t_token       *tok;

  tok = *token;
  if ((tok->type != TOKEN_WORD || tok->type == TOKEN_UNK) && (tok))
    return (tok->value);
  tok = tok->next;
  while (tok && (tok->next != NULL))
    {
      if (tok->type == TOKEN_UNK)
  	{
  	  lexi->cmd[tok->pos - 1] = '\0';
	  return (tok->value);
  	}
      if (tok->type != TOKEN_WORD && (tok->next != NULL))
  	{
	  tok = tok->next;
  	  if (tok->type != TOKEN_WORD || tok->type == TOKEN_UNK)
  	    {
  	      lexi->cmd[tok->pos] = '\0';
	      return (tok->value);
  	    }
  	}
      tok = tok->next;
    }
  return (NULL);
}

int		size_of_list(t_token **token)
{
  t_token	*tok;
  int		i;

  i = 0;
  tok = *token;
  while (tok->next != NULL)
    {
      i++;
      tok = tok->next;
    }
  return (i);
}

int		parser(t_token **token, t_42sh *shell)
{
  t_token	*tok;
  int		a;
  t_pars	*pars;

  a = 0;
  tok = *token;
  pars = xmalloc(sizeof(*pars));
  pars->tab = xmalloc((size_of_list(token) + 2) * sizeof(char*));
  pars->tab = memset(pars->tab, '\0', (size_of_list(token) + 2));
  while (tok->next != NULL)
    {
      pars->tab[a] = xmalloc((strlen(tok->value) + 2) * sizeof(char));
      pars->tab[a] = memset(pars->tab[a], '\0', (strlen(tok->value) + 2));
      pars->tab[a] = strdup(epur_str(tok->value));
      a++;
      tok = tok->next;
    }
  pars->tab[a] = strdup(epur_str(tok->value));
  a++;
  pars->tab[a] = NULL;
  if (struct_fill(pars->tab, token, shell) == -42)
    return (-42);
  return (0);
}
