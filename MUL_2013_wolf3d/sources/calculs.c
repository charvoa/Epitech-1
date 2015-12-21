/*
** calculs.c for calculs in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:20:13 2014 Nicolas Charvoz
** Last update Sun Jan 12 14:54:53 2014 Nicolas Charvoz
*/

#include "../headers/wolf.h"
#include "../headers/mlx.h"

extern int	laby[10][10];

int     laby[10][10] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
  {1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int		wall_intersections(t_wolf *w)
{
  int		x_map;
  int		y_map;
  float		k;
  float		Vx;
  float		Vy;

  k = 1;
  Vx = w->x1 - w->pos_x;
  Vy = w->y1 - w->pos_y;
  x_map = w->pos_x + (k * w->Vx);
  y_map = w->pos_y + (k * w->Vy);
  while (laby[y_map][x_map] == 0)
    {
      x_map = w->pos_x + k * Vx;
      y_map = w->pos_y + k * Vy;
      k = k + 0.001;
    }

  printf("Vx = %.3f || Vy = %.3f || k = %.3f || pos_x = %.3f || pos_y = %.3f\n", Vx, Vy, k, w->pos_x, w->pos_y);


  return (k);
}
