/*
** my_strlowcase.c for my_strlowcase in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 01:10:31 2013 garcia
** Last update Tue Oct  8 02:15:04 2013 garcia
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}

