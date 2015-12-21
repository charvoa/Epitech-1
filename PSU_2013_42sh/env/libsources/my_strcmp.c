/*
** my_strcmp.c for my_strcmp in /home/garcia_t/rendu/Piscine-C-Jour_06
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Oct  7 20:59:39 2013 garcia
** Last update Sun Nov 10 10:36:58 2013 garcia
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;
  int	resultat;

  i = 0;
  j = 0;
  resultat = 0;
  while (s1[i] != '\0' && s2[j] != '\0')
    {
      if (s1[i] != s2[j])
	{
	  resultat = (s1[i] - s2[j]);
	  return (resultat);
	}
      i = i + 1;
      j = j + 1;
    }
}
