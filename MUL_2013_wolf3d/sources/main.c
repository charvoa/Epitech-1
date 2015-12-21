/*
** main.c for main in
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 12 15:20:29 2014 Nicolas Charvoz
** Last update Sun Jan 12 14:52:45 2014 Nicolas Charvoz
*/

#include "../headers/wolf.h"
#include "../headers/mlx.h"
#include <math.h>

#define STEP 0.25
#define KEY_UP 65362
#define KEY_DO 6534
#define KEY_LE 65363
#define KEY_RI 65361
#define KEY_ESC 65307

extern int	laby[10][10];

int	expose(t_wolf *w)
{
  mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
}

int	up_down(int key, t_wolf *w)
{
  float	a_rad;

  a_rad = (w->a * (M_PI / 180));
  w->save_x = w->pos_x;
  w->save_y = w->pos_y;
  if (key == KEY_DO)
    {
      w->pos_x += (STEP * cos(a_rad)) * (-1);
      w->pos_y += (STEP * sin(a_rad)) * (-1);
    }
  else if (key == KEY_UP)
    {
      w->pos_x += (STEP * cos(a_rad));
      w->pos_y += (STEP * sin(a_rad));
      printf("pos_x = %.3f\n", w->pos_x);
    }
  w->wall_x = w->pos_x;
  w->wall_y = w->pos_y;
  if (laby[(int)w->wall_y][(int)w->wall_x] == 1)
    {
      w->pos_x = w->save_x;
      w->pos_y = w->save_y;
    }
}

int	left_right(int key, t_wolf *w)
{
  if (key == KEY_LE)
    {
      w->angle = (w->angle + 15);
    }
  else if (key == KEY_RI)
    {
      w->angle = (w->angle - 15);
    }
  /* if (w->angle >= 360 || w->angle < 0)
    {
      c = w->angle;
      if (c >= 360)
      c = c % 360;
    }*/
}

int     moves(int key, t_wolf *w)
{
  up_down(key, w);
  left_right(key, w);
  if (key == KEY_ESC)
    exit (0);
  print(w);
}

void	main(int ac, char **av, char **env)
{
  t_wolf	*w;
  int		i;
  char		*str;

  str = "No Env, can't run Wolf3D bogoss Version !\n";
  i = 0;
  while (env[i++] == NULL)
    {
      my_putstr(str);
      exit (-1);
    }
  w = malloc(sizeof (t_wolf));
  init(w);
  print(w);
  mlx_expose_hook(w->win_ptr, expose, w);
  mlx_key_hook(w->win_ptr, moves, w);
  mlx_loop(w->mlx_ptr);
  free(w);
}
