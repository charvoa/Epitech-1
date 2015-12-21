/*
** my_strlen.c for my_strlen in /home/garcia_t/rendu/Piscine-C-Jour_04
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Oct  4 15:29:23 2013 garcia
** Last update Sun Nov 10 10:26:10 2013 garcia
*/

int	my_strlen(char *str)
{
  int	compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      compt = compt +  1;
    }
  return (compt);
}
