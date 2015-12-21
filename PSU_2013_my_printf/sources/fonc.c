/*
** fonc.c for fs in /home/charvo_a/Downloads
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Nov  8 21:10:01 2013 CHARVOZ Nicolas
** Last update Fri Nov 15 16:34:22 2013 Nicolas Charvoz
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/printf.h"

int	str_printf(va_list ap)
{
  char	*str;
  unsigned int	count;

  str = va_arg(ap, char*);
  count = my_strlen(str);
  my_putstr(str);
  return (count);
}

int	nbr_printf(va_list ap)
{
  int	nb;
  unsigned int	count;

  nb = va_arg(ap, int);
  count = nbcount(nb);
  my_put_nbr(nb);
  return (count);
}

int	char_printf(va_list ap)
{

  char c;

  c = va_arg(ap, int);
  my_putchar(c);
  return (1);
}

int	ptr_printf(va_list ap)
{
  unsigned int	ptr;
  char	*base;
  int	count;

  ptr = va_arg(ap, unsigned int);
  base = "0123456789abcdef";
  count = nbcount(ptr);
  my_putstr("0x7fff");
  my_put_un_nbr_base(ptr, base);
}

int	bin_printf(va_list ap)
{
  unsigned int	bin;
  char	*base;
  unsigned int	count;

  bin = va_arg(ap, unsigned int);
  base = "01";
  count = nbcount(bin);
  my_put_un_nbr_base(bin, base);
}
