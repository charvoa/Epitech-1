/*
** my_getnbr.c for get nbr in /home/charvo_a/rendu/PSU_2013_my_printf/sources
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat Nov 16 12:59:35 2013 Nicolas Charvoz
** Last update Sat Nov 16 12:59:38 2013 Nicolas Charvoz
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	isneg;
  int	i;

  isneg = 1;
  nb = 0;
  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	isneg = isneg * -1;
      i = i + 1;
    }
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb = nb * 10;
	  nb = nb + str[i] - '0';
	  i = i + 1;
	}
      else
	return (nb * isneg);
    }
  return (nb * isneg);
}
