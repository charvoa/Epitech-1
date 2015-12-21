/*
** my_strupcase.c for strupcase in /home/charvo_a/rendu/Piscine-C-Jour_06
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Tue Oct  8 00:59:43 2013 CHARVOZ Nicolas
** Last update Tue Oct  8 01:15:17 2013 CHARVOZ Nicolas
*/

char	*my_strupcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
