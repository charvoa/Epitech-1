/*
** init.c for init in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:19:21 2014 Nicolas Charvoz
** Last update Sun Jan 12 15:28:06 2014 Nicolas Charvoz
*/

#include "../headers/wolf.h"
#include "../headers/mlx.h"

void		init(t_wolf *w)
{
  w->L = 640;
  w->H = 640;
  w->mlx_ptr = mlx_init();
  w->win_ptr = mlx_new_window(w->mlx_ptr, w->L, w->H, "Wolf3D Nicolas Charvoz");
  w->img_ptr = mlx_new_image(w->mlx_ptr, w->L, w->H);
  w->data = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->size_line, &w->end);
  w->k = 1;
  w->pos_x = 5;
  w->pos_y = 5;
  w->angle = 0;
}
