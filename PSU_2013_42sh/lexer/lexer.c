/*
** lexer.c for  in /media/5c1be222-3ce0-4181-925b-c458f62a0f76/charvo_a/rendu/PSU_2013_42sh/lexer
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat May 24 01:01:18 2014 Nicolas Charvoz
** Last update Tue May 27 22:40:39 2014 Nicolas Charvoz
*/

#include "lexer.h"
#include "../parser/parser.h"
#include "../xlib/xlib.h"

int	check_unk(char *str, int i, t_token **token)
{
  char	*unk;
  int	j;

  j = 0;
  unk = xmalloc((strlen(str) + 1) * sizeof(char*));
  unk = memset(unk, 0, (strlen(str) + 1));
  while (((check_letter2(str[i]) == -1) && str[i] != '\t' ) && str[i] != '\0')
    {
      unk[j] = str[i];
      j++;
      i++;
    }
  unk[i] = '\0';
  if (unk[0] != '\0')
    *token = insert(*token, TOKEN_UNK, strdup(unk), i);
  free(unk);
  return (i);
}

int	word_check(char *str, int i, t_token **token)
{
  char	*word;
  int	j;

  j = 0;
  word = xmalloc((strlen(str) + 1) * sizeof(char*));
  word = memset(word, 0, (strlen(str) + 1));
  while (((check_letter(str[i]) != -1) || str[i] == '\t' ) && (str[i] != '\0'))
    {
      word[j] = str[i];
      j++;
      i++;
    }
  word[i] = '\0';
  if (word[0] != '\0')
    {
      word = epur_str(word);
      *token = insert(*token, TOKEN_WORD, strdup(word), i);
    }
  free(word);
  return (i);
}

char	*check_carac(char *str)
{
  int	i;

  i = strlen(str);
  i = i - 1;
  if ((!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
      && str[i] != '.' && str[i] != '/' && !(str[i] >= '0' && str[i] <= '9')
      && str[i] != '~' && str[i] != '-')
    {
      str[i] = '\0';
      return (str);
    }
  return (str);
}

int	lex(char *str, t_token **token)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = comma_check(str, i, token);
      i = pipe_check(str, i, token);
      i = red_r(str, i, token);
      i = red_l(str, i, token);
      i = check_and(str, i, token);
      i = word_check(str, i, token);
      i = check_unk(str, i, token);
    }
  return (0);
}

int	lexer(char *cmd, t_token **token, t_42sh *shell)
{
  char	*error;
  t_lex	*lexi;

  lexi = xmalloc(sizeof(*lexi));
  cmd = check_carac(cmd);
  lexi->cmd = epur_str(strdup(cmd));
  if (!(lexi->cmd[0]))
    return (0);
  lex(lexi->cmd, token);
  if ((error = check_token(token, lexi)) != NULL)
    {
      printf("42sh : Syntax error near unexpected token `%s`\n", error);
      return (0);
    }
  else
    return (parser(token, shell));
  return (0);
}
