/*
** list.h for list in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 11:40:28 2014 garcia antoine
** Last update Wed May 21 17:15:45 2014 Nicolas Girardot
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct s_node
{
  char		*name;
  char		*value;
  struct s_node *next;
  struct s_node *prev;
}		t_node;

typedef struct s_dlist
{
  unsigned int lenght;
  t_node	*start;
  t_node	*end;
}		t_dlist;

t_dlist		*create_list();
void		add_node(t_dlist *, t_node *);
void		put_in_list(t_dlist *, char *, char *);
void		show_list(t_dlist *);
void		free_my_list(t_dlist *);

#endif  /*LIST_H_*/
