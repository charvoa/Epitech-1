/*
** my_memset.c for my_memset in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Dec  2 13:31:13 2013 garcia
** Last update Mon Dec  2 13:32:52 2013 garcia
*/

char    *my_memset(char *s, char c, int size)
{
  int   i;

  i = 0;
  while (i < size)
    s[i++] = c;
  return (s);
}
