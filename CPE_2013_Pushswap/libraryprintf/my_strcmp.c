/*
** strcmp.c for strcmp in /home/charvo_a
** 
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Mon Oct  7 18:22:35 2013 CHARVOZ Nicolas
** Last update Mon Oct  7 21:30:49 2013 CHARVOZ Nicolas
*/

int	my_strcmp(char *s1, char *s2)
{
  int i;
  int j;
  int resultat;

  i = 0;
  j = 0;
  resultat = 0;
  while (s1[i] != '\0' &&  s2[j] != '\0')
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
