/*
** my_showstr.c for showstr in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 13:29:05 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 13:30:48 2013 CHARVOZ Nicolas
*/

int     my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_putchar('-');
    }
  if (nbr >= my_strlen(base) - 1)
    my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
  return (nbr);
}

int     my_showstr(char *str)
{
  int   i;
  
  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] > 126)
        {
          my_putchar('\\');
          if (str[i] < 14)
            {
              my_putchar('0');
            }
          my_putnbr_base((str[i]), "0123456789abcdef");
        }
      else
        {
          my_putchar(str[i]);
        }
      i = i + 1;
    }
  return (0);
}
