/*
** my-strncpy.c for my_strncpy in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Oct  7 10:20:27 2013 garcia
** Last update Sun Nov 10 10:33:24 2013 garcia
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  char	carac;

  carac = 0;
  while (carac < n && src[carac] != '\0')
    {
      dest[carac] = src[carac];
      carac = carac + 1;
	}
  if (n <= carac)
    {
      dest[carac] = '\0';
    }
  return (dest);
}
