/*
** check1.c for  in /home/charvo_a/42/lexer
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 14:55:27 2014 Nicolas Charvoz
** Last update Wed May 28 10:02:06 2014 Nicolas Charvoz
*/

#include "lexer.h"

int     check_letter(char c)
{
  int   i;
  char  *str;

  str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789 -./\\$?=~";
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (0);
      i++;
    }
  return (-1);
}

int      red_l(char *str, int i, t_token **token)
{
  int   j;

  j = i;
  while (str[i] == '<')
    {
      if (str[j + 1] == '<')
	{
	  *token = insert(*token, TOKEN_DBL_R, "<<", i);
	  i++;
	}
      else
        *token = insert(*token, TOKEN_RED_R, "<", i);
      i++;
    }
  return (i);
}

int      red_r(char *str, int i, t_token **token)
{
  int   j;

  j = i;
  while (str[i] == '>')
    {
      if (str[j + 1] == '>')
	{
	  *token = insert(*token, TOKEN_DBL_R, ">>", i);
	  i++;
	}
      else
        *token = insert(*token, TOKEN_RED_R, ">", i);
      i++;
    }
  return (i);
}

int      comma_check(char *str, int i, t_token **token)
{

  while (str[i] == ';')
    {
      *token = insert(*token, TOKEN_COMMA, ";", i);
      i++;
    }
  return (i);
}

int      pipe_check(char *str, int i, t_token **token)
{
  int   j;

  j = i;
  while (str[i] == '|')
    {
      if (str[j + 1] == '|')
	{
	  *token = insert(*token, TOKEN_OR, "||", i);
	  i++;
	}
      else
        *token = insert(*token, TOKEN_PIPE, "|", i);
      i++;
    }
  return (i);
}
