/*
** my_strupcase.c for my_strupcase in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 01:02:10 2013 garcia
** Last update Sun Nov 10 10:41:54 2013 garcia
*/

char	*my_strupcase (char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 &&  str[i] <= 122)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
