/*
** my_strcpy.c for my_strcpy in /home/charvo_a/rendu/Piscine-C-Jour_06
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Oct  7 09:27:33 2013 CHARVOZ Nicolas
** Last update Wed Nov 13 10:14:19 2013 Nicolas Charvoz
*/

char	*my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
