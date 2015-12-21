/*
** fs-3.c for fs-3 in /home/garcia_t/rendu/printf
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed Nov 13 10:01:56 2013 garcia
** Last update Tue Nov 19 16:38:51 2013 garcia
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_putnbru_printf(va_list ap)
{
  unsigned int	nb;
  int	count;

  nb = va_arg(ap, unsigned int);
  count = my_countbru(nb);
  my_putnbr_unsign(nb);
  return (count);
}
