##
## Makefile for makefile in /home/charvo_a/rendu/Piscine-C-lib/my
##
## Made by CHARVOZ Nicolas
## Login   <charvo_a@epitech.net>
##
## Started on  Mon Oct 21 13:27:27 2013 CHARVOZ Nicolas
## Last update Sat Nov 16 14:17:48 2013 Nicolas Charvoz
##

SRCC=	./sources/my_find_prime_sup.c \
	./sources/my_getnbr.c \
	./sources/my_isneg.c \
	./sources/my_is_prime.c \
	./sources/my_power_rec.c \
	./sources/my_putchar.c \
	./sources/my_put_nbr.c \
	./sources/my_putstr.c \
	./sources/my_revstr.c \
	./sources/my_showmem.c \
	./sources/my_showstr.c \
	./sources/my_sort_int_tab.c \
	./sources/my_square_root.c \
	./sources/my_strcapitalize.c \
	./sources/my_strcat.c \
	./sources/my_strcmp.c \
	./sources/my_strcpy.c \
	./sources/my_str_isalpha.c \
	./sources/my_str_islower.c \
	./sources/my_str_isnum.c \
	./sources/my_str_isprintable.c \
	./sources/my_str_isupper.c \
	./sources/my_strlcat.c \
	./sources/my_strlen.c \
	./sources/my_strlowcase.c \
	./sources/my_strncat.c \
	./sources/my_strncmp.c \
	./sources/my_strncpy.c \
	./sources/my_strstr.c \
	./sources/my_strupcase.c \
	./sources/my_swap.c \
	./sources/fonc.c \
	./sources/fonc2.c \
	./sources/my_printf.c \
	./sources/my_putnbr_base.c \
	./sources/my_put_un_nbr_base.c \
	./sources/fonc3.c \

OBJ=	$(SRCC:.c=.o)

CC=	cc -c

NAME=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRCC)
		ar -rv $(NAME) $(OBJ)
		ranlib libmy.a
		cp libmy.a ./library
clean :
	rm -f libmy.a
	rm -f $(OBJ)
	rm -f *.o
