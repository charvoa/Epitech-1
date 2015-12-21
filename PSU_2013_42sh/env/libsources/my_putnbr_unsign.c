/*
** my_putnbr_unsign.c for my_putnbr_unsign in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Nov 12 15:28:18 2013 garcia
** Last update Tue Nov 12 17:30:41 2013 garcia
*/

void     my_putnbr_unsign(unsigned int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }

  if (nb > 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}
