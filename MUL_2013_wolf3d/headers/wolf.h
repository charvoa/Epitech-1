/*
** wolf.h for wolf.h in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:21:41 2014 Nicolas Charvoz
** Last update Sun Jan 12 15:29:48 2014 Nicolas Charvoz
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/mlx.h"

#ifndef _WOLF_H_
#define _WOLF_H_

typedef struct	s_wolf
{
  char		*data;
  char		*img;
  int		bpp;
  int		size_line;
  int		end;
  float		H;
  float		L;
  float		wall_x;
  float		wall_y;
  float		k;
  float		a;
  float		x1;
  float		y1;
  float		Vx;
  float		Vy;
  float		pos_x;
  float		pos_y;
  float		save_x;
  float		save_y;
  float		angle;
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
}		t_wolf;

#endif /*_WOLF_H_*/
