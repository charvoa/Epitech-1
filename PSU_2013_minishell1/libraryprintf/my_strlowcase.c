/*
** my_strlowcase.c for strlowcase in /home/charvo_a/rendu/Piscine-C-Jour_06
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 01:11:07 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 01:14:35 2013 CHARVOZ Nicolas
*/

char	*my_strlowcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
	{
	  str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  return (str);
}
