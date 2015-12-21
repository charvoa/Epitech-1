/*
** xlib.h for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:22:03 2014 Nicolas Charvoz
** Last update Sun May 25 21:05:12 2014 Nicolas Charvoz
*/

#ifndef XLIB_H_
# define XLIB_H_

# define _GNU_SOURCE

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../env/42sh.h"

/* XOPEN.C */
int	xopen(const char *pathname, int flags);
int	xopenmode(const char *pathname, int flags, mode_t mode);
int	xcreat(const char *pathname, mode_t mode);
int	xopen_alias(const char *pathname, int flags);

/* XREAD.C */
ssize_t	xread(int fd, void *buf, size_t count);

/* XPIPE.C */
int	xpipe(int pipefd[2]);

/* XDUP2.C */
int	xdup2(int oldfd, int newfd);

/* XCLOSE.C */
int	xclose(int fd);

/* PRINT_ERROR.C */
void	print_error(char *str);

/* XMALLOC.C */
void	*xmalloc(size_t size);
void	*xcalloc(size_t nmemb, size_t size);

#endif
