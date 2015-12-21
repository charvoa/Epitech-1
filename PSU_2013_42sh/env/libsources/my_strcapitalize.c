/*
** my_strcapitalize.c for my_strcapitalize in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 06:07:27 2013 garcia
** Last update Tue Oct  8 15:29:18 2013 garcia
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 1;
  if (str[0] >= 97 && str[0] <= 122)
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if (str[i - 1] >= 23 && str[i - 1] <= 47 || str[i - 1] == ';')
	{
	  if (str[i] <= 'z' && str[i] >= 'a')
	    str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
