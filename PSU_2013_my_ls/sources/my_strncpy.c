/*
** my_strncpy.c for my_strncpy in /home/charvo_a/rendu/Piscine-C-Jour_06
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Oct  7 10:18:12 2013 CHARVOZ Nicolas
** Last update Wed Nov 13 10:16:31 2013 Nicolas Charvoz
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int i;

  i = 0;
  while (src[i] != '\0' && n > i)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n <=  i)
    {
      dest[i] = '\0';
    }
  return (dest);
}
