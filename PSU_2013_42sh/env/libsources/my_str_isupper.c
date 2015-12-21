/*
** my_str_isupper.c for my_str_isupper in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 07:06:56 2013 garcia
** Last update Tue Oct  8 07:10:42 2013 garcia
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
