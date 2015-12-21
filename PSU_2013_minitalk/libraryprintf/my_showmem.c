/*
** my_showmem.c for showmem in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 15:25:36 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 15:30:34 2013 CHARVOZ Nicolas
*/

int     my_putnbr_base3(int nb, char *base)
{
  int   i;

  i = 1;
  while (base[i] != '\0')
      i = i + 1;
  if (nb < 0)
      nb = nb * (-1);
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  if (nb >= i)
      my_putnbr_base3(nb / i, base);
  my_putchar(base[nb - (nb / i) * i]);
  return (nb);
}

void    my_verif_printable(int i, char *str)
{
  if (str[i] >= 32 && str[i] != 127)
      my_putchar(str[i]);
  else
      my_putchar('.');
}

int             my_print_hexa(int i, char *str, int size)
{
  unsigned char positive;
  int           space;

  space = 0;
  while ((i + 1) % 16 != 0 && i < size)
    {
      i = i + 1;
      positive = str[i];
      if (positive < 16)
          my_putchar('0');
      my_putnbr_base3(positive, "0123456789abcdef");
      if (i % 2 == 1)
        {
          my_putchar(' ');
          space = space + 1;
        }
    }
  space = space + (i % 16) * 2 + 2;
  while (space < 40 && i >= size)
      {
        space = space + 1;
        my_putchar(' ');
      }
}

void    my_print_adress(int i, char *str, int positive)
{
  int   swap;

  swap = &str[i] - str;
  if (swap == 0)
      swap = swap + 10;
  while (swap < 16000000)
    {
      my_putchar('0');
      swap = swap * 10;
    }
  my_putnbr_base3(&str[i] - str, "0123456789abcdef");
  my_putchar(':');
  my_putchar(' ');
  if (positive < 16)
      my_putchar('0');
  my_putnbr_base3(positive, "0123456789abcdef");
}

int             my_showmem(char *str, int size)
{
  int           i;
  unsigned char positive;

  i = 0;
  while (i < size)
    {
      positive = str[i];
      my_print_adress(i, str, positive);
      my_print_hexa(i, str, size);
      my_verif_printable(i, str);
      while ((i + 1) % 16 != 0 && i < size)
        {
          i = i + 1;
          my_verif_printable(i, str);
        }
      i = i + 1;
      my_putchar('\n');
    }
  return (0);
}
