/*
** my_rev_str.c for rev str in /home/charvo_a/rendu/Piscine-C-Jour_06/ex_02
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Oct  7 13:27:02 2013 CHARVOZ Nicolas
** Last update Thu Nov 14 16:35:26 2013 Nicolas Charvoz
*/

char	*my_revstr(char *str)
{
  int a;
  int b;

  b = 0;
  while (str[a] != '\0')
    {
      a = a + 1;
    }
  a = a - 1;
  while (a >= b)
    {
  my_swap(&str[a], &str[b]);
  b =  b + 1;
  a = a - 1;
    }
}
