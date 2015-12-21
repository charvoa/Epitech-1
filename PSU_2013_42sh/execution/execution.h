/*
** execution.h for execution in /home/garcia_t/42/execution
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri May  9 11:18:26 2014 garcia antoine
** Last update Wed May 28 15:31:18 2014 garcia antoine
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

#include "../env/42sh.h"
#include "../parser/parser.h"

typedef struct s_signal
{
  int		nb;
  char		*msg;
}		t_signal;

/* redirections.c */
int		open_my_file(char*);
void		redir_left(t_cmd*, t_cmd*);
void		double_redir_right(t_cmd*, t_cmd*);
void		redir_right(t_cmd*, t_cmd*);
void		redirections(t_cmd*, t_cmd*, t_cmd*, int);
int		open_for_redir_right(char*);
int		open_for_dredir_right(char*);
/* global_exec.c */
int		global_exec(t_cmd*, t_42sh*, int);

/* exec_simple_cmd.c */
int		check_cmd(t_cmd*, t_42sh*);
int		exec_cmd(t_cmd*, t_42sh*);
int		exec_cmd_simple(t_cmd*, t_42sh*);
char		*real_path(t_cmd*, t_42sh*);

/* close_functions.c */
int		which_one_to_close(t_cmd*, int);
int		check_and_close_son(t_cmd*, int);
int		check_and_close_father(t_cmd*, t_42sh*, int);

/* execution.c */
int		check_or_and(t_cmd*, int, t_42sh*);
int		launch(t_cmd*, t_42sh*, int);
int		check_and_launch(t_cmd*, t_42sh*, int, int);
int		wainting_process(t_cmd*);
int		execution(t_cmd*, t_42sh*, int, int);

/* execution_next.c */
int		exec_redir(t_cmd*, int);
int		start_execution(t_cmd*, t_42sh*, int);

/* prepa_pipes.c */
int		prepa_pipes(t_cmd*, int);

/* signal.c */
int		check_signal(int);

/* double_refir_left */
void		double_redir_left(t_cmd*, t_cmd*, t_cmd*, int);

#endif
