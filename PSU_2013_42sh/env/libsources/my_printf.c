/*
** my_printf.c for my_printf in /home/garcia_t/rendu/printf
**
** Made by garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Wed Nov  6 17:33:17 2013 garcia
** Last update Tue Nov 19 16:38:11 2013 garcia
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_flag(char c)
{
  char	*flag;
  int	i;

  flag ="discpbSoxX%u";
  i = 0;
  while (flag[i])
    {
      if (c == flag[i])
	{
	  return (i);
	}
      i++;
    }
  return (-1);
}

void	init_fs(int (**fs)(va_list ap))
{
  fs[0] = &my_putnbr_printf;
  fs[1] = &my_putnbr_printf;
  fs[2] = &my_putstr_printf;
  fs[3] = &my_putchar_printf;
  fs[4] = &my_ptr_printf;
  fs[5] = &my_nbbin_printf;
  fs[6] = &my_putoctal_printf;
  fs[7] = &my_octal_printf;
  fs[8] = &my_puthexa_printf;
  fs[9] = &my_puthexa2_printf;
  fs[10] = &my_modulo_printf;
  fs[11] = &my_putnbru_printf;
}

int	my_printf(const char *format, ...)
{
  va_list ap;
  int	(*fs[12])(va_list ap);
  int	i;
  int	count;

  init_fs(fs);
  va_start(ap, format);
  i = 0;
  count = 0;
  while (format[i])
    {
      if (format[i] == '%' && my_flag(format[i + 1]) != -1)
	{
	  count = fs[my_flag(format[i + 1])](ap) - 2;
	  i++;
	}
      else
	my_putchar(format[i]);
      i++;
    }
  va_end(ap);
  count = count + i;
  return (count);
}
