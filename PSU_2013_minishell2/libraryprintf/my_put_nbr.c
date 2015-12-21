/*
** my_put_nbr.c for my_put_nbr.c in /home/charvo_a/rendu/Piscine-C-Jour_03
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Oct  3 19:23:32 2013 CHARVOZ Nicolas
** Last update Tue Feb 25 17:26:13 2014 Nicolas Charvoz
*/

int     my_put_nbr(int nb)
{
  int   div;
  int   ret;

  div = 1;
  ret = 0;
  if (nb > 0)
    nb = nb * -1;
  else if (nb < 0)
    my_putchar('-');
  while (nb / div < -9)
    div = div * 10;
  while (div >= 1)
    {
      ret = ret + 1;
      my_putchar(nb / div * -1 + 48);
      nb = nb % div;
      div = div / 10;
    }
  return (ret);
}
