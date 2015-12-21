/*
** my_putnbr_base.c for putnbr base in /home/charvo_a/Downloads/printf
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Nov 10 00:13:31 2013 CHARVOZ Nicolas
** Last update Sun Nov 17 16:50:07 2013 Nicolas Charvoz
*/

unsigned int		my_put_un_nbr_base(unsigned int nb, char *base)
{
  unsigned int		a;
  unsigned int		len_str;

  len_str = my_strlen(base);
  a = nb % len_str;
  nb = nb / len_str;
  if (nb > 0)
    my_putnbr_base(nb, base);
  my_putchar(base[a]);
  return (nb);
}
