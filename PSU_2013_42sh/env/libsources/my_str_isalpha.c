/*
** my_str_isalpha.c for my_str_isalpha.c in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 04:15:07 2013 garcia
** Last update Sun Nov 10 10:37:51 2013 garcia
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	  i = i + 1;
      else
	return (0);
    }
  return (1);
}
