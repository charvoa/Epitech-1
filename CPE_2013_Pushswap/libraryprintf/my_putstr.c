/*
** my_putstr.c for my_putstr.c in /home/charvo_a/rendu/Piscine-C-Jour_04
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Oct  3 11:35:20 2013 CHARVOZ Nicolas
** Last update Wed Nov 13 10:12:19 2013 Nicolas Charvoz
*/

int	my_putstr(char *str)
{
  int carac;

  carac = 0;
  while (str[carac] != '\0')
    {
      my_putchar(str[carac]);
      carac = carac + 1;
    }
}
