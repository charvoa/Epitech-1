/*
** client.h for  in /home/charvo_a/Work/minitalk/client
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Feb 26 10:03:50 2014 Nicolas Charvoz
** Last update Sat Mar 22 16:37:36 2014 Nicolas Charvoz
*/

#ifndef		_CLIENT_H_
# define	_CLIENT_H_

#define		_POSIX_SOURCE
#define		_BSD_SOURCE
#define		READ_SIZE 4096

#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<signal.h>
#include	<time.h>
#include	<term.h>
#include	"printf.h"
#include	"my.h"

void		x_error();
int		send_convert(int, char);
int		client(char**, char*);
void		check_error();
void		my_memset(char*, char, int);
int		xread(int, char*, int);
void		run(char **);
int		client2(char **av);
void		my_clear();
int		my_int_putchar(int);

#endif
