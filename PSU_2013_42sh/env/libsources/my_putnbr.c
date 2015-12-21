/*
** my_putnbr.c for my_putnbr.c in /home/garcia_t/rendu
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Oct 25 13:08:57 2013 garcia
** Last update Sat Jan  4 16:13:11 2014 garcia
*/

void	my_putnbr(int nb)
{
  if (nb == -2147483648)
    my_putstr("-2147483648");
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar(48 + nb);
}
