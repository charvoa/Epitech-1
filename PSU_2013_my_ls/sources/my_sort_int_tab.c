/*
** my_sort_int_tab.c for sort int tab in /home/charvo_a/rendu/Piscine-C-lib
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Tue Oct  8 13:24:11 2013 CHARVOZ Nicolas
** Last update Mon Oct 21 11:41:32 2013 CHARVOZ Nicolas
*/

void    my_sort_int_tab(int *tab, int size)
{
  int   i;
  int   sort;
  int   nb;

  nb = 0;
  sort = 0;
  while (sort == 0)
    {
      i = 0;
      sort = 1;
      while ((i + 1) < size)
        {
          if (tab[i] > tab[i + 1])
            {
              sort = 0;
              my_swap(&tab[i], &tab[i + 1]);
            }
          i = i + 1;
        }
      nb = nb + 1;
    }
}
