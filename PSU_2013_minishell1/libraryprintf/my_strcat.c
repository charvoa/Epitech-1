/*
** my_strcat.c for strcat in /home/charvo_a/rendu/Piscine-C-Jour_07
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Tue Oct  8 16:22:54 2013 CHARVOZ Nicolas
** Last update Thu Nov 14 16:56:29 2013 Nicolas Charvoz
*/

int     ma_strlen(char *str)
{
  int	carac;

  carac = 0;
  while (str[carac] != '\0')
    {
      carac = carac + 1;
    }
  return (carac);
}

char    *my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = ma_strlen(dest);
  while (src[j] != '\0')
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
