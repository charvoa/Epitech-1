/*
** fonc3.c for fonc3 in /home/charvo_a/rendu/PSU_2013_my_printf/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Nov 15 16:32:48 2013 Nicolas Charvoz
** Last update Sun Nov 17 16:39:57 2013 Nicolas Charvoz
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/printf.h"

int		octal_printf(va_list ap)
{
  unsigned int	oct;
  char		*base;
  unsigned int	count;

  oct = va_arg(ap, unsigned int);
  base = "01234567";
  count = nbcount(oct);
  my_put_un_nbr_base(oct, base);
}
