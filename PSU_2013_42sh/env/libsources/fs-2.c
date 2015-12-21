/*
** fs-2.c for fs-2 in /home/garcia_t/rendu/printf
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Sun Nov 10 13:44:39 2013 garcia
** Last update Fri Mar 21 14:08:37 2014 garcia antoine
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_putoctal_printf(va_list ap)
{
  char	*str;
  char	*base;
  int	i;
  int	count;

  str = va_arg(ap, char *);
  i = 0;
  count = 0;
  base = "01234567";
  while (str[i])
    {
      if (str[i] <= 7)
	{
	  my_putstr("\\00");
	  my_putnbr_base(str[i], base);
	}
      else if ((str[i] >  7 && str[i] <= 32) || str[i] >= 127)
	{
	  my_putstr("\\0");
	  my_putnbr_base(str[i], base);
	}
      my_putchar(str[i]);
      i++;
    }
  return (count);
}

int	my_octal_printf(va_list ap)
{
  int	nb;
  char	*base;
  int	count;

  nb = va_arg(ap, int);
  base = "01234567";
  my_putnbr_base(nb, base);
  count = my_countnbr(nb);
  return (count);
}

int	my_puthexa_printf(va_list ap)
{
  unsigned int  nb;
  char	*base;
  int	i;

  nb = va_arg(ap, unsigned int);
  base = "0123456789abcdef";
  my_putnbr_baseu(nb, base);
  i = my_countbru(nb);
  return (i);
}

int	my_puthexa2_printf(va_list ap)
{
  unsigned int	nb;
  char	*base;
  int	i;

  nb = va_arg(ap, unsigned int);
  base = "0123456789ABCDEF";
  i = my_countbru(nb);
  my_putnbr_baseu(nb, base);
  return (i);
}

int	my_modulo_printf(va_list ap)
{
  my_putchar('%');
  return (1);
}
