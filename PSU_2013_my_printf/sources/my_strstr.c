/*
** my_strstr.c for my_strstr in /home/charvo_a/rendu/Piscine-C-Jour_06/ex_04
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Oct  7 15:30:21 2013 CHARVOZ Nicolas
** Last update Thu Nov 14 16:56:07 2013 Nicolas Charvoz
*/

char	*my_strstr(char *str, char *to_find)
{
  int i;
  int j;
  char *str1;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
      j = 0;
      if (str[i] == str[j] && str[j] != '\0')
	{
	  i = i + 1;
	  str1 = &str[1];
	  if (str[i] == str[j] && str[j] != '\0')
	    {
	      j = j + 1;
	      return (str1);
	    }
	  else
	    i = i + 1;
	}
    }
}
