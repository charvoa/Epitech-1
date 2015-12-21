/*
** my_str_isupper.c for my_str_isupper in /home/charvo_a/rendu/Piscine-C-Jour_06
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Tue Oct  8 07:06:56 2013 CHARVOZ Nicolas
** Last update Thu Nov 14 16:35:02 2013 Nicolas Charvoz
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' &&  str[i] <= 'z')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
