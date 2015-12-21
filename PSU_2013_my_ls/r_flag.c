/*
** r_flag.c for rflag in /home/charvo_a/rendu/PSU_2013_my_ls
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Dec  1 09:40:36 2013 Nicolas Charvoz
** Last update Sun Dec  1 11:08:37 2013 Nicolas Charvoz
*/

#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "./headers/myls.h"
#include "./headers/my.h"

void	bubblesortr(char **tab, int N)
{
  int   i;
  int   j;
  char  temp[100];

  i = 0;
  while(i < N)
    {
      j = i + 1;
      while(j < N)
        {
          if(my_strcmp(tab[i], tab[j]) < 0)
            {
              my_strcpy(temp, tab[i]);
              my_strcpy(tab[i], tab[j]);
              my_strcpy(tab[j], temp);
            }
          j++;
        }
      i++;
    }
  i = 0;
  while (i < N)
    my_printf("%s  ", tab[i++]);
  my_printf("\n");
}

int     counttabr(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != 0)
    {
      i++;
    }
  return (i);
}

void     r_flag(char *name)
{
  struct dirent *list;
  DIR *dirp;
  int   i;
  char **tab;
  int  countchar;
  int   count;

  i = 0;
  count = 0;
  tab = xmalloc(1000 * sizeof(char *));
  if ((dirp = opendir(name)) == NULL)
    exit(-1);
  while ((list = readdir(dirp)) != NULL)
    if (my_strcmp(list->d_name, ".") && my_strcmp(list->d_name, ".."))
      {
        countchar = my_strlen(list->d_name);
        tab[i] = xmalloc(countchar + 1 * sizeof(char));
        tab[i] = list->d_name;
        i++;
      }
  closedir(dirp);
  count = counttabr(tab);
  bubblesortr(tab, count);
}
