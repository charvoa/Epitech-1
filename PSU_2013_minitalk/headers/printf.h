/*
** printf.h for print in /home/charvo_a/Downloads/printf
**
** Made by CHARVOZ Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Nov  8 21:25:58 2013 CHARVOZ Nicolas
** Last update Wed Feb 26 10:29:28 2014 Nicolas Charvoz
*/

#ifndef PRINT_H_
#define PRINT_H_

#include <stdarg.h>

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
