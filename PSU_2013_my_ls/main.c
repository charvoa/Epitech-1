/*
** main.c for main in /home/charvo_a/rendu/MyLs
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Nov 25 14:39:53 2013 Nicolas Charvoz
** Last update Sun Dec  1 11:10:41 2013 Nicolas Charvoz
*/

#include <stdio.h>
#include "./headers/myls.h"
#include "./headers/my.h"

void	tab_init(void  (**fs)(char *))
{
  fs[0] = &l_flag;
  fs[1] = &d_flag;
  fs[2] = &r_flag;
}

int	ac2(char *flags, void (**tab)(char *), char **av, char *name)
{
  int	i;

  i = 0;
  if (av[1][0] == '-')
    {
      i = 0;
      while (i < 3)
	{
	  if (av[1][1] == flags[i])
	    {
	      tab[i](".");
	    }
	  i++;
	}
    }
  else
    {
      name = av[1];
      no_flag(name);
    }
  return (0);
}

int	ac3(char *flags, void (**tab)(char *), char **av, char *name)
{
  int	i;

  name = av[2];
  if (av[1][0] == '-')
    {
      i = 0;
      while (i < 3)
	{
	  if (av[1][1] == flags[i])
	    {
	      tab[i](name);
	    }
	  i++;
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  void	(*tab[3])(char *);
  char	*flags;
  char	*name;

  tab_init(tab);
  flags = "ldr";
  if (ac == 1)
    {
      no_flag(".");
    }
  if (ac == 2)
    {
      ac2(flags, tab, av, name);
    }
  if (ac == 3)
    {
      ac3(flags, tab, av, name);
    }
  return (0);
}
