/*
** my_putnbr_baseu.c for my_putnbr_baseu in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Nov 12 15:43:11 2013 garcia
** Last update Tue Nov 12 16:47:31 2013 garcia
*/

unsigned int	my_putnbr_baseu(unsigned int nb, char *base)
{
  unsigned int   a;
  unsigned int   len_str;

  len_str = my_strlen(base);
  a = nb % len_str;
  nb = nb / len_str;
  if (nb > 0)
    my_putnbr_base(nb, base);
  my_putchar(base[a]);
  return (nb);
}
