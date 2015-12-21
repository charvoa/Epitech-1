/*
** my_str_islower.c for my_str_islower in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 07:00:17 2013 garcia
** Last update Tue Oct  8 10:02:45 2013 garcia
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

