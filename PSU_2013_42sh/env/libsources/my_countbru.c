/*
** my_countbru.c for my_countnbru in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed Nov 13 10:15:16 2013 garcia
** Last update Wed Nov 13 10:27:09 2013 garcia
*/

int     my_countbru(unsigned int nb)
{
  int   i;
  unsigned int   result;

  i = 0;
  result = nb;
  while (result > 0)
    {
      result = result / 10;
      i++;
    }
  return (i);
}
