/*
** my_str_isnum.c for my_str_isnum in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 06:56:13 2013 garcia
** Last update Sun Nov 10 10:38:56 2013 garcia
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
