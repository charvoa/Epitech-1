/*
** my_put_nbr.c for my_put_nbr.c in /home/charvo_a/rendu/Piscine-C-Jour_03
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Oct  3 19:23:32 2013 CHARVOZ Nicolas
** Last update Wed Nov 13 11:47:20 2013 Nicolas Charvoz
*/

int	my_put_nbr(int nb)
{
  if (nb < -2147483647)
    my_putstr("-2147483648");
  else if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  else if (nb > 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + '0');
}
