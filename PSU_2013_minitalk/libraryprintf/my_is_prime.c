/*
** my_is_prime.c for prime in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 11:12:47 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 11:20:50 2013 CHARVOZ Nicolas
*/

int     my_is_prime(int nb)
{
  int   i;

  i = 2;
  if (nb == 0 || nb == 1)
    {
      return (0);
    }
  while (i < nb)
    {
      if (nb % i == 0)
        {
          return (0);
        }
      i = i + 1;
    }
  return (1);
}
