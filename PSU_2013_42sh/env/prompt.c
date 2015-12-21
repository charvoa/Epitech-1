/*
** prompt.c for prompt in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 15:59:36 2014 garcia antoine
<<<<<<< HEAD
** Last update Wed May 28 14:18:52 2014 Nicolas Charvoz
=======
** Last update Sun May 25 12:14:47 2014 Nicolas Charvoz
>>>>>>> d530b8d8769d35fa5736db56f45e95b7dc48c284
*/

#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"
#include "../termcaps/termcaps.h"
#include "./libsources/my.h"

void			prompt(t_42sh *shell)
{
  (void)shell;
  my_printf("§> ");
}
