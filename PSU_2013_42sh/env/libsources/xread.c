/*
** xread.c for xread in /home/garcia_t/rendu/Piscine-C-lib/my
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Wed Dec  4 17:54:10 2013 garcia
** Last update Sun Dec  8 17:26:11 2013 garcia
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t xread(int d, void *buf, size_t nbytes)
{
  int   ret;

  ret = read(d, buf, nbytes);
  if (ret == -1)
    {
      my_printf("Could not read");
      exit(1);
    }
  return (ret);
}

