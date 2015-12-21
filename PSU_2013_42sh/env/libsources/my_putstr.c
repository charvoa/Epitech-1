/*
** my_putstr.c for my_putstr in /home/garcia_t/rendu/Piscine-C-Jour_04
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Thu Oct  3 11:02:14 2013 garcia
** Last update Thu Nov 14 09:47:24 2013 garcia
*/

int	my_putstr( char *str)
{
  int carac;

  carac = 0;
  while (str[carac] != '\0')
    {
      my_putchar(str[carac]);
      carac = carac + 1;
    }
}
