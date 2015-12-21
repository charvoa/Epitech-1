/*
** my_str_isprintable.c for isprintable in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:03:52 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 10:07:33 2013 CHARVOZ Nicolas
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >=  0 || str[i] <=  31 || str[i] == 127)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
