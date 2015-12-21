/*
** my_sort_int_tab.c for my_sort_int_tab in /home/garcia_t/rendu/Piscine-C-Jour_04
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue Oct  8 16:10:25 2013 garcia
** Last update Sun Nov 10 10:41:21 2013 garcia
*/

int	my_sort_int_tab(int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (tab[i] > tab[i + 1])
	{
	  my_swap(&tab[i], &tab[i + 1]);
	}
      i = i + 1;
    }
  return (i);
}
