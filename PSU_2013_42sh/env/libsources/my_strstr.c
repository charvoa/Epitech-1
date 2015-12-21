/*
** my_strstr.c for my_strstr in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Oct  7 14:13:42 2013 garcia
** Last update Sun Nov 10 10:40:10 2013 garcia
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  char	*str1;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
      j = 0;
      if (str[i] == str[j] || str[i] != '\0')
	{
	  i = i + 1;
	  str1 = &str[i];

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
