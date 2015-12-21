##
## Makefile for makefile in /home/charvo_a/rendu/Piscine-C-lib/my
##
## Made by CHARVOZ Nicolas
## Login   <charvo_a@epitech.net>
##
## Started on  Mon Oct 21 13:27:27 2013 CHARVOZ Nicolas
## Last update Thu Dec 12 23:27:16 2013 Nicolas Charvoz
##

SRCC=	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlcat.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	fonc.c \
	fonc2.c \
	my_printf.c \
	my_putnbr_base.c \
	my_put_un_nbr_base.c \
	fonc3.c \

OBJ=	$(SRCC:.c=.o)

CC=	cc -c

NAME=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRCC)
		ar -rv $(NAME) $(OBJ)
		ranlib libmy.a	$(NAME)

clean:
	rm -f $(OBJ)

fclean :
	rm -f libmy.a
	rm -f $(OBJ)

re:	fclean all clean