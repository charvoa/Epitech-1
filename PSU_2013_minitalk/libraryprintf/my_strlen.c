/*
** my_strlen.c for my_strlen.c in /home/charvo_a/rendu/Piscine-C-Jour_04
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Thu Oct  3 11:35:20 2013 CHARVOZ Nicolas
** Last update Thu Oct  3 15:54:43 2013 CHARVOZ Nicolas
*/

int	my_strlen(char *str)
{
  int carac;

  carac = 0;
  while (str[carac] != '\0')
    {
      carac = carac + 1;
    }
  return carac;
}
