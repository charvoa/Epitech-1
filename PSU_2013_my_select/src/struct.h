/*
** struct.h for struct h in /home/charvo_a/Work/select2
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Jan 19 15:03:40 2014 Nicolas Charvoz
** Last update Sun Jan 19 19:35:09 2014 Nicolas Charvoz
*/

#ifndef _STRUCT_H_
# define _STRUCT_H_

typedef struct		s_elem
{
  char			*val;
  struct	s_elem	*prec;
  struct	s_elem	*suiv;
}			t_elem;

int	my_int_putchar(int c);
void	pt(t_elem *list, int s);
t_elem	*create();
void	addav(t_elem *elem, char *val);
void	addap(t_elem *elem, char *val);
void	my_while(t_elem *list);
void	get_key();

# define ESCAPE 27;

#endif /*_STRUCT_H_ */
