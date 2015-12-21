/*
** my_printf.c for my_printf in /home/charvo_a/rendu/printf/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Nov 14 17:06:45 2013 Nicolas Charvoz
** Last update Sun Nov 17 16:55:53 2013 Nicolas Charvoz
*/

#include <stdarg.h>
#include <stdio.h>
#include "../headers/printf.h"

int	check_flag(char p)
{
  char	*flag;
  int	i;

  flag = "discpbSoxX%";
  i = 0;
  while (flag[i])
    {
      if (flag[i] == p)
	return (i);
      i++;
    }
  return (-1);
}

void	fs_init(int (**fs)(va_list ap))
{
  fs[0] = &nbr_printf;
  fs[1] = &nbr_printf;
  fs[2] = &str_printf;
  fs[3] = &char_printf;
  fs[4] = &ptr_printf;
  fs[5] = &bin_printf;
  fs[6] = &soctal_printf;
  fs[7] = &octal_printf;
  fs[8] = &hexa_printf;
  fs[9] = &hexo_printf;
  fs[10] = &pourcent_printf;
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		(*fs[11])(va_list ap);
  int		i;
  int		tab;
  int		count;

  count = 0;
  fs_init(fs);
  va_start(ap, format);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%' && check_flag(format[i + 1]) != -1)
	{
	  count = fs[check_flag(format[i + 1])](ap);
	  i++;
	}
      else
	my_putchar(format[i]);
      i++;
    }
  va_end(ap);
  return (count);
}
