/*
** my_str_isupper.c for my_str_isupper in /home/charvo_a/rendu/Piscine-C-Jour_06
** 
** Made by CHARVOZ NICOLAS
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 07:06:56 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 07:10:42 2013 CHARVOZ Nicolas
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'A' || str[i] > 'z')
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
