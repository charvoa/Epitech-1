/*
** my_isneg.c for my_isneg.c in /home/charvo_a/rendu/Piscine-C-Jour_03
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Oct  2 12:54:57 2013 CHARVOZ Nicolas
** Last update Wed Nov 13 10:13:13 2013 Nicolas Charvoz
*/

int	my_isneg(int n)
{
  int	b;

  b = 'P';
  if (n < 0)
    {
      b = 'N';
    }
  my_putchar(b);
}
