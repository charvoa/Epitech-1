/*
** my_strcpy.c for my_strcpy in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Oct  7 08:59:37 2013 garcia
** Last update Tue Nov 12 10:45:45 2013 garcia
*/

char	*my_strcpy(char *dest, char *src)
{
  char	carac;

  carac = 0;
  while (src[carac] != '\0')
    {
      dest[carac] = src[carac];
      carac = carac + 1;
    }
  dest[carac] = '\0';
  return (dest);
}
