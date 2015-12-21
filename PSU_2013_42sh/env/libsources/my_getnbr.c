/*
** my_getnbr.c for my_getnbr in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Thu Nov 14 13:58:14 2013 garcia
** Last update Thu Nov 14 13:59:15 2013 garcia
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
