/*
** my_putnbr_base.c for nbr base in /home/charvo_a/Downloads/printf
** 
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Nov 12 18:12:10 2013 Nicolas Charvoz
** Last update Tue Nov 12 18:16:05 2013 Nicolas Charvoz
*/

int	my_putnbr_base(int nb, char *base)
{
  int	a;
  int	len_str;

  if (nb == -2147483648)
    return (nb);
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  len_str = my_strlen(base);
  a = nb % len_str;
  nb = nb / len_str;
  if (nb > 0)
    my_putnbr_base(nb, base);
  my_putchar(base[a]);
  return (nb);
}
