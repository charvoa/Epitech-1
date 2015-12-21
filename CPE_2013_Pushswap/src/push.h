/*
** push.h for pushswap in /home/charvo_a/rendu/pushswap
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Jan  6 09:56:13 2014 Nicolas Charvoz
** Last update Mon Jan  6 23:03:23 2014 Nicolas Charvoz
*/

#ifndef _PUSH_H_
#define _PUSH_H_
#include <stdlib.h>

struct	node
{
  int	data;
  struct node	*p_next;
  struct node	*p_prev;
};

typedef struct s_dlist
{
  size_t	length;
  struct node	*p_tail;
  struct node	*p_head;
}		t_Dlist;

t_Dlist	*dlist_new(void);
t_Dlist	*dlist_append(t_Dlist *p_list, int data);
t_Dlist	*dlist_prepend(t_Dlist *p_list, int data);
void	dlist_display(t_Dlist *p_list);
size_t	dist_length(t_Dlist *p_list);

#endif /*_PUSH_H_ */
