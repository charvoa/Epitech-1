/*
** my_strncat.c for my_strncat in /home/garcia_t/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed Oct  9 08:42:22 2013 garcia
** Last update Wed Oct  9 15:45:28 2013 garcia
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] != '\0' && j <= nb)
      {
	dest[i] = src[j];
	j = j + 1;
	i = i + 1;
      }
  return (dest);
}
