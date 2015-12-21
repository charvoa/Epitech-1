/*
** fonc2.c for fonc2 in /home/charvo_a/Downloads/printf
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Nov 13 03:56:39 2013 Nicolas Charvoz
** Last update Mon Dec  2 05:04:08 2013 Nicolas Charvoz
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/printf.h"

int		hexo_printf(va_list ap)
{
  unsigned int  hexo;
  char		*base;
  unsigned int  count;

  hexo = va_arg(ap, unsigned int);
  base = "0123456789ABCDEF";
  count = nbcount(hexo);
  my_put_un_nbr_base(hexo, base);
  return (count);
}

int     pourcent_printf(va_list ap)
{
  my_putchar('%');
  return (1);
}

int		hexa_printf(va_list ap)
{
  unsigned int  hexa;
  char		*base;
  unsigned int  count;

  hexa = va_arg(ap, unsigned int);
  base = "0123456789abcdef";
  count = nbcount(hexa);
  my_put_un_nbr_base(hexa, base);
  return (count);
}

int		soctal_printf(va_list ap)
{
  char		*oct;
  char		*base;
  unsigned int  count;
  int		i;

  i = 0;
  oct = va_arg(ap, char *);
  base = "01234567";
  while (oct[i])
    {
      if (oct[i] <= 7)
        {
          my_putstr("\\00");
          my_putnbr_base(oct[i], base);
          count = my_strlen(oct) + 3;
        }
      else if (oct[i] > 7 && oct[i] <= 32 || oct[i] >  127)
        {
          my_putstr("\\0");
          my_putnbr_base(oct[i], base);
	  count = my_strlen(oct) + 2;
        }
      my_putchar(oct[i++]);
    }
  return (count);
}

int     nbcount(int nb)
{
  int   i;

  i = 0;
  while (nb)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}
