/*
** printf.h for  in /home/charvo_a/rendu/PSU_2013_minishell2/headers
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:13:06 2014 Nicolas Charvoz
** Last update Sun Mar  9 15:13:13 2014 Nicolas Charvoz
*/

#ifndef _PRINT_H_
# define _PRINT_H_

# include <stdarg.h>

int	check_flag(char p);
void	fs_init(int (**fs)(va_list ap));
int	my_printf(const char *format, ...);
int	str_printf(va_list ap);
int	nbr_printf(va_list ap);
int	char_printf(va_list ap);
int	ptr_printf(va_list ap);
int	bin_printf(va_list ap);
int	octal_printf(va_list ap);
int	hexa_printf(va_list ap);
int	soctal_printf(va_list ap);
int	nbcount(int nb);
int	hexo_printf(va_list ap);
int	pourcent_printf(va_list ap);

#endif
