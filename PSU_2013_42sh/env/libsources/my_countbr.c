/*
** my_countbr.c for countnbr in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Nov 12 11:17:08 2013 garcia
** Last update Tue Nov 12 11:40:00 2013 garcia
*/

int	my_countnbr(int nb)
{
  int	i;
  int	result;

  i = 0;
  result = nb;
  while (result > 0)
    {
      result = result / 10;
      i++;
    }
  return (i);
}
