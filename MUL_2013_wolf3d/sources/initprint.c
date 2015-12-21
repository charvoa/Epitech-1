/*
** print_init.c for print init in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:21:02 2014 Nicolas Charvoz
** Last update Sun Jan 12 15:29:29 2014 Nicolas Charvoz
*/

#include "../headers/wolf.h"
#include "../headers/mlx.h"

int	pxl_put_to_img(t_wolf *w, int x, int y, int color)
{
  char	*data;

  data = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->size_line, &w->end);
  w->data[(x * w->bpp/8) + (y * w->size_line)] = color & 0xff;
  w->data[(x * w->bpp/8) + (y * w->size_line) + 1] = (color >> 8) & 0xff;
  w->data[(x * w->bpp/8) + (y * w->size_line) + 2] = (color >> 16) & 0xff;
  w->data[(x * w->bpp/8) + (y * w->size_line) + 3] = (color >> 24) & 0xff;
  return (0);
}
