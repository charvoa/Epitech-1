/*
** my_square_root.c for square root in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:39:15 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 10:53:46 2013 CHARVOZ Nicolas
*/

int	my_square_root(int nb)
{
  int i;

  i = 0;
  if (nb < 0)
    return (0);
  while ((i * i) != nb)
    {
      if ((i * i) > nb)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (i);
}
