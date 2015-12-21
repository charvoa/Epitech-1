/*
** server.h for  in /home/charvo_a/Work/minitalk/headers
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Feb 26 10:08:11 2014 Nicolas Charvoz
** Last update Wed Feb 26 10:10:02 2014 Nicolas Charvoz
*/

#ifndef _SERVER_H_
# define _SERVER_H_

#include        <stdlib.h>
#include        <sys/types.h>
#include        <unistd.h>
#include        <signal.h>
#include        "printf.h"
#include        "my.h"

int	convert_writer(int);
void	my_sig(int);
void	x_error();

#endif
