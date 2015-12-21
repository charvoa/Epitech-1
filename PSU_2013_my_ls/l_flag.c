/*
** l_flag.c for l flag in /home/charvo_a/rendu/PSU_2013_my_ls
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Dec  1 09:40:57 2013 Nicolas Charvoz
** Last update Sun Dec  1 11:10:06 2013 Nicolas Charvoz
*/

#define _BSD_SOURCE
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <time.h>
#include "./headers/myls.h"
#include "./headers/my.h"


void	mydir(struct stat sb)
{
  (S_ISDIR(sb.st_mode) != 0) ? my_printf("d") :
    (S_ISSOCK(sb.st_mode) != 0) ? my_printf("s") :
    (S_ISBLK(sb.st_mode) != 0) ? my_printf("b") :
    (S_ISCHR(sb.st_mode) != 0) ? my_printf("c") :
    (S_ISLNK(sb.st_mode)!= 0) ? my_printf("l") :
    (S_ISFIFO(sb.st_mode) != 0) ? my_printf("p") : my_printf("-");
}

void	my_rights(struct stat sb)
{
  ((sb.st_mode & S_IRUSR) != 0) ? my_printf("r") : my_printf("-");
  ((sb.st_mode & S_IWUSR) != 0) ? my_printf("w") : my_printf("-");
  ((sb.st_mode & S_IXUSR) != 0) ? my_printf("x") : my_printf("-");
  ((sb.st_mode & S_IRGRP) != 0) ? my_printf("r") : my_printf("-");
  ((sb.st_mode & S_IWGRP) != 0) ? my_printf("w") : my_printf("-");
  ((sb.st_mode & S_IXGRP) != 0) ? my_printf("x") : my_printf("-");
  ((sb.st_mode & S_IROTH) != 0) ? my_printf("r") : my_printf("-");
  ((sb.st_mode & S_IWOTH) != 0) ? my_printf("w") : my_printf("-");
  ((sb.st_mode & S_IXOTH) != 0) ? my_printf("x\t") : my_printf("-\t");
}

char	*mytime(char *str)
{
  char	*str2;
  int	j;
  int	i;

  str2 = xmalloc(my_strlen(str) * sizeof(*str));
  j = 0;
  i = 4;
  while (i <= 15)
    {
      if (i == 7)
	{
	  str2[j++] = '.';
	}
      str2[j++] = str[i++];
    }
  str2[j] = '\0';
  return (str2);
}

void	my_aff_data(struct stat sb, struct passwd *pass, struct group *group)
{
  pass = getpwuid(sb.st_uid);
  group = getgrgid(pass->pw_gid);
  mydir(sb);
  my_rights(sb);
  my_printf("%d\t", sb.st_nlink);
  my_printf("%s\t", pass->pw_name);
  my_printf("%s\t", group->gr_name);
  my_printf("%d\t", sb.st_size);
  my_printf("%s\t", mytime(ctime(&sb.st_mtime)));
}

void		l_flag(char *name)
{
  DIR		*dirp;
  struct stat	sb;
  struct dirent	*list;
  struct passwd	*pass;
  struct group	*group;
  char		path[1024];

  if ((dirp = opendir(name)) != NULL)
    {
      while ((list = readdir(dirp)) != NULL)
	{
	  if (my_strcmp(list->d_name, ".") && my_strcmp(list->d_name, ".."))
	    {
	      my_strcpy(path, name);
	      my_strcat(path, "/");
	      my_strcat(path, list->d_name);
	      lstat(path, &sb);
	      my_aff_data(sb, pass,  group);
	      my_printf("%s\n", list->d_name);
	    }
	}
      closedir(dirp);
    }
  else
    my_printf("%s : Is not a file or a directory you can access\n", name);
}
