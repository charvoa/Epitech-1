/*
** alum.h for  in /home/charvo_a/Work/alum1
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu Jan 23 10:48:12 2014 Nicolas Charvoz
** Last update Fri Feb 14 15:53:45 2014 Nicolas Charvoz
*/

#ifndef _ALUM_H_
# define _ALUM_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include "../headers/my.h"
#include "../headers/printf.h"

typedef	struct s_alum
{
  int	*row;
  int	nb;
  int	line;
  int	somme;
  char	name[4096];
  char	name2[4096];
}		t_alum;

void	aff_alum(t_alum *a);
void	my_error(t_alum *a);
void	remplissage(int nb);
void	my_read(t_alum *a);
void	init_row(t_alum *a);
void	create_row(t_alum *a);
int	my_int_putchar(int c);
void	my_clear();
void	*xmalloc(int size);
void	my_enlev(t_alum *a);
int	player2(t_alum *a);
int	xread(int, char*, int);
void	oneplayer(t_alum*);
void	twoplayer(t_alum*);
void	my_choice(t_alum*);

#endif
