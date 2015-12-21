/*
** print.c for print in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:20:47 2014 Nicolas Charvoz
** Last update Sun Jan 12 15:04:16 2014 Nicolas Charvoz
*/

#include "../headers/wolf.h"
#include "../headers/mlx.h"

void		ground(t_wolf *w)
{
  int		x;
  int		y;
  int		i;
  char		*data;
  char		*couleur;
  unsigned int	colorexa;

  x = 0;
  y = w->H/2;
  colorexa = 0x00561B;
  couleur = (char *)&colorexa;
  data = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->size_line, &w->end);
  while(y <= w->H)
    {
      while (x <= w->L && y > w->H/2)
	{
	  i = 0;
	  while (i < w->bpp/8)
	    {
	      data[w->size_line * y + x * (w->bpp/8) + i] = couleur[i];
	      i++;
	    }
	  x++;
	}
      x = 0;
      y++;
    }
}

void		sky(t_wolf *w)
{
  int		x;
  int		y;
  int		i;
  char		*data;
  char		*couleur;
  unsigned int	colorexa;

  x = 0;
  y = 0;
  colorexa = 0x77B5FE;
  couleur = (char *)&colorexa;
  data = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->size_line, &w->end);
  while(y <= w->H / 2)
    {
      while (x <= w->L)
	{
	  i = 0;
	  while (i < w->bpp/8)
	    {
	      data[w->size_line * y + x * (w->bpp/8) + i] = couleur[i];
	      i++;
	    }
	  x++;
	}
      x = 0;
      y++;
    }
}


void		down(t_wolf *w, int x)
{
  int		i;
  int		H;
  int		r;
  int		y;
  int		t;
  char		*data;
  unsigned int	colorexa;
  char		*couleur;

  i = 0;
  colorexa = 0x842E1B;
  couleur = (char *)&colorexa;
  H = (w->H / (2 * w->k));
  y = ((w->H / 2) * w->size_line) + (x * w->bpp / 8);
  data = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->size_line, &w->end);
  while(i < H)
    {
      r = 0;
      while (r < (w->bpp / 8))
	{
	  t = y + (i * w->size_line);
	  data[r + t] = couleur[r];
	  r++;
	}
      i++;
    }
}

void		wall(t_wolf *w, int x)
{
  int		i;
  int		H;
  int		r;
  int		y;
  int		t;
  char		*data;
  unsigned int	colorexa;
  char		*couleur;

  i = 0;
  H = (w->H / (2 * w->k));
  y = ((w->H / 2) * w->size_line) + (x * w->bpp / 8);
  colorexa = 0x842E1B;
  couleur = (char *)&colorexa;
  data = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->size_line, &w->end);
  while(i < H)
    {
      r = 0;
      while (r < (w->bpp / 8))
	{
	  t = y - (i * w->size_line);
	  data[r + t] = couleur[r];
	  r++;
	}
      i++;
    }
  down(w, x);
}

void		print(t_wolf *w)
{
  int		x;
  float		a;
  float		x_temp;
  float		y_temp;
  float		X_prim;
  float		Y_prim;

  sky(w);
  ground(w);
  x = 0;
  a = w->angle * (M_PI / 180);
  while (x <= w->L)
    {
      w->x1 = 0.5;
      w->y1 = w->L / 2;
      w->y1 = w->y1 - x;
      w->y1 = w->y1 / w->L;
      x_temp = w->x1;
      y_temp = w->y1;
      w->x1 = (x_temp * cos(a)) - (y_temp * sin(a));
      w->y1 = (x_temp * sin(a)) + (y_temp * cos(a));
      w->x1 = w->x1 + w->pos_x;
      w->y1 = w->y1 + w->pos_y;
      w->k = wall_intersections(w);
      wall(w, x);
      x++;
    }
  mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
}
