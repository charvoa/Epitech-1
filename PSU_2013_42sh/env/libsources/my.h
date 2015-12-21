/*
** my.h for my in /home/garcia_t/rendu/Piscine-C-include
**
** Made by garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Oct 11 13:21:20 2013 garcia
** Last update Wed Apr 30 11:25:22 2014 Nicolas Charvoz
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <sys/types.h>

void	my_putchar(char);
char	**my_str_to_word_tab(char*);
char	*my_strdup(char*);
int	my_isneg(int);
void	my_putnbr(int);
int	my_swap(int*, int*);
int	my_putstr(char*);
int	my_strlen(char*);
int	my_getnbr(char*);
void	my_sort_int_tab(int*, int);
int	my_power_rec(int, int);
int	my_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
char	*my_strcpy(char*, char*);
char	*my_strncpy(char*, char*, int);
char	*my_revstr(char*);
char	*my_strstr(char*, char*);
int	my_strcmp(char*, char*);
int	my_strncmp(char*, char*, int);
char	*my_strupcase(char*);
char	*my_strlowcase(char*);
char	*my_strcapitalize(char*);
int	my_str_isalpha(char*);
int	my_str_isnum(char*);
int	my_str_islower(char*);
int	my_str_isupper(char*);
int	my_str_isprintable(char*);
int	my_showstr(char*);
int	my_showmem(char*, int);
char	*my_strcat(char*, char*);
char	*my_strncat(char*, char*, int);
int	my_strlcat(char*, char*, int);
void	my_putnbr_base(int, char*);
int	my_flag(char);
void	init_fs(int (**fs)(va_list ap));
int	my_printf(const char *, ...);
int	my_putstr_printf(va_list ap);
int	my_putnbr_printf(va_list ap);
int	my_putchar_printf(va_list ap);
int	my_ptr_printf(va_list ap);
int	my_nbbin_printf(va_list ap);
int	my_putoctal_printf(va_list ap);
int	my_octal_printf(va_list ap);
int	my_puthexa_printf(va_list ap);
int	my_puthexa2_printf(va_list ap);
int	my_modulo_printf(va_list ap);
int	my_putnbru_printf(va_list ap);
char	*my_memset(char*, char, int);
ssize_t	xread(int, void *, size_t);

#endif
