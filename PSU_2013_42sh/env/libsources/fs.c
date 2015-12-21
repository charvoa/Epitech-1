/*
** fs.c for fs in /home/garcia_t/rendu/printf
**
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Nov  8 16:26:59 2013 garcia
** Last update Mon Dec  2 13:35:24 2013 garcia
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_putstr_printf(va_list ap)
{
  char	*str;
  int	i;

  str = va_arg(ap, char *);
  i = my_strlen(str);
  my_putstr(str);
  return (i);
}

int	my_putnbr_printf(va_list ap)
{
  int	nb;
  int	count;

  nb = va_arg(ap, int);
  my_putnbr(nb);
  count = my_countnbr(nb);
  return (count);
}

int	my_putchar_printf(va_list ap)
{
  char	c;

  c = va_arg(ap, int);
  my_putchar(c);
  return (1);
}

int	my_ptr_printf(va_list ap)
{
  int	format;
  char	*base;
  int	count;

  format = va_arg(ap, int);
  base = "0123456789abcdef";
  my_putstr("0x7fff");
  my_putnbr_base(format, base);
  count = my_countbru(format) + 2;
  return (count);
}

int	my_nbbin_printf(va_list ap)
{
  unsigned int	nb;
  char	*base;
  int	count;

  nb = va_arg(ap, unsigned int);
  base = "01";
  count = my_countbru(nb);
  my_putnbr_baseu(nb, base);
  return (count);
}
