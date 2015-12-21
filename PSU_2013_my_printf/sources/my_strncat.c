/*
** my_strncat.c for strncat in /home/charvo_a/rendu/Piscine-C-Jour_07
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Tue Oct  8 16:22:54 2013 CHARVOZ Nicolas
** Last update Thu Nov 14 16:57:18 2013 Nicolas Charvoz
*/

int     m_strlen(char *str)
{
  int	carac;

  carac = 0;
  while (str[carac] != '\0')
    {
      carac = carac + 1;
    }
  return (carac);
}

char    *my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  j = 0;
  i = m_strlen(dest);
  while (src[j] != '\0' && j < nb)
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
