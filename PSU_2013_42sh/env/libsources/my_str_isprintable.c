/*
** my_str_isprintable.c for my_str_isprintable in /home/garcia_t/rendu/Piscine-C-Jour_06/ex_14
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 10:32:52 2013 garcia
** Last update Tue Oct  8 10:36:44 2013 garcia
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 0 || str[i] <= 31 || str[i] == 127)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
