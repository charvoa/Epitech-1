/*
** my_find_prime_sup.c for find prime sup in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 13:15:45 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 15:42:02 2013 CHARVOZ Nicolas
*/

int     my_find_prime_sup(int nb)
{
  int   sup;
  
  while ((sup = my_is_prime(nb)) == 0)
    {
      nb = nb + 1;
    }
  return (nb);
}
