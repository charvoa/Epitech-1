/*
** my_strcapitalize.c for capitalize in /home/charvo_a/rendu/Piscine-C-lib
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:31:12 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 14:31:00 2013 CHARVOZ Nicolas
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 1;
  if (str[0] >= 97 && str[0] <= 122)
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if ((str[i - 1] >= 23 && str[i - 1] <= 47) || str[i - 1] <= ';')
	if (str[i] <= 'z' && str[i] >= 'a')
	  str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
