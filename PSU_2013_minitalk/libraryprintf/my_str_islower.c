/*
** my_str_islower.c for islower in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:02:22 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 10:02:27 2013 CHARVOZ Nicolas
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}

