/*
** my_strlcat.c for strlcat in /home/charvo_a/rendu/Piscine-C-Jour_07
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Tue Oct  8 16:22:54 2013 CHARVOZ Nicolas
** Last update Wed Nov 13 10:11:33 2013 Nicolas Charvoz
*/

void	swap_str(char **e, char **s, char *dest, char *src)
{
  *e = dest;
  *s = src;
}

int	my_strlcat(char *dest, char *src, int size)
{
  char	*e;
  char	*s;
  int	nb;
  int	len;
  int	len_s;

  nb = size;
  swap_str(&e, &s, dest, src);
  while (nb-- != 0 && *e != '\0')
    e += 1;
  len = e - dest;
  while (s[len_s] != '\0')
    len_s++;
  nb = size - len;
  if (nb == 0)
    return (len + len_s);
  while (*s++ != '\0')
    {
      if (nb != 1)
	{
	  *e = *s;
	  *e = *e + 1;
	}
    }
  *e = '\0';
}
