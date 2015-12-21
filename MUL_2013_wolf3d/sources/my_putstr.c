/*
** my_putstr.c for my_putstr in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:18:43 2014 Nicolas Charvoz
** Last update Sun Jan 12 15:28:50 2014 Nicolas Charvoz
*/

#include "../headers/wolf.h"

char	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
