/*
** my_str_isnum.c for isnum in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:00:58 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 10:01:33 2013 CHARVOZ Nicolas
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '1' || str[i] > '9')
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
