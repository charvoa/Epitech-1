/*
** my_strcat.c for my_strcat in /home/garcia_t/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed Oct  9 09:42:09 2013 garcia
** Last update Mon Dec  9 12:20:38 2013 garcia
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
