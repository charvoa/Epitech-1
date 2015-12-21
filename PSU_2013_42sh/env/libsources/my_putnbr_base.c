/*
** my_putnbr_base.c for putnbrbase in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed Nov 13 11:02:54 2013 garcia
** Last update Wed Nov 13 11:07:37 2013 garcia
*/

void    my_putnbr_base(int nb, char *base)
{
  int   result;
  int   diviseur;
  int   size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      my_putchar(base[result]);
      diviseur = diviseur / size_base;
    }
}
