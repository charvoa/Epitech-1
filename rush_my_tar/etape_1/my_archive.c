#include <stdio.h>
#include <stdlib.h>

int	whileopen(FILE **fs, int i, char **av)
{
  int	k;
  int	j;

  k = 1;
  j = 0;
  while (i > 0)
    {
      fs[j] = fopen(av[k], "r");
      i--;
      j++;
      k++;
    }
  fs[j] = NULL;
}

int	whileput(FILE **fs, FILE *ft)
{
  int	j;
  char	ch;

  j = 0;
  while (fs[j] != NULL)
    {
      while ((ch = fgetc(fs[j])) != EOF)
	fputc(ch, ft);
      fprintf(ft, "@X@X@X@X@X@X@X@X@X@X@X@X@X@X@X@X@X@X@\n");
      j++;
    }
}

int	main(int ac, char **av)
{
  FILE	**fs;
  FILE	*ft;
  int	i;
  int	j;
  int	k;

  k = 1;
  j = 0;
  i = ac - 1;

  fs = malloc(ac * sizeof(FILE *));
  whileopen(fs, i, av);
  ft = fopen(av[ac - 1], "w");
  whileput(fs, ft);
  while (fs[j])
    {
      fclose(fs[j]);
      j++;
    }
  fclose(ft);
  free(fs);
  return(0);
}
