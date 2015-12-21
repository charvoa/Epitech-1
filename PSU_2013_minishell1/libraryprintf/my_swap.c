/*
** my_swap.c for my_swap.c in /home/charvo_a/rendu/Piscine-C-Jour_04
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Thu Oct  3 08:53:45 2013 CHARVOZ Nicolas
** Last update Thu Oct  3 22:52:51 2013 CHARVOZ Nicolas
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}