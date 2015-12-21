/*
** my_power_rec.c for my_power_rec in /home/charvo_a/rendu/Piscine-C-Jour_05
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Fri Oct  4 15:26:59 2013 CHARVOZ Nicolas
** Last update Mon Oct  7 20:00:17 2013 CHARVOZ Nicolas
*/

int	my_power_rec(int nb, int power)
{
  if (power > 0)
    return (nb *= my_power_rec(nb, power - 1));
  return (1);
}
