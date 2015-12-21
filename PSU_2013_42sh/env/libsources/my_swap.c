/*
** my_swap.c for my_swap in /home/garcia_t/rendu/Piscine-C-Jour_04
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Thu Oct  3 09:35:46 2013 garcia
** Last update Sun Nov 10 10:40:46 2013 garcia
*/

int	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
