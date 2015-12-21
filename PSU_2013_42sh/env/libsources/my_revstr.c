/*
** my_revstr.c for my_revstr.c in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Oct  7 11:50:50 2013 garcia
** Last update Sun Nov 10 10:38:39 2013 garcia
*/

char	*my_revstr(char *str)
{
  int	num;
  int	lenght;
  char	opmet;

  num = 0;
  lenght = my_strlen(str) - 1;
  while (num < lenght)
    {
      opmet = str[num];
      str[num] = str[lenght];
      str[lenght] = opmet;
      num++;
      lenght--;
    }
  return (str);
}
