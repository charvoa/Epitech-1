##
## Makefile for Makefile in /home/garcia_t/rendu/Piscine-C-lib
## 
## Made by garcia
## Login   <garcia_t@epitech.net>
## 
## Started on  Mon Oct 21 10:01:48 2013 garcia
## Last update Fri Mar 21 14:09:09 2014 garcia antoine
##

SRCC= 	my_putchar.c \
	my_putnbr.c \
	my_swap.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	my_strcpy.c \
	my_strncpy.c \
	my_revstr.c \
	my_strstr.c \
	my_strcmp.c \
	my_strncmp.c \
	my_strupcase.c \
	my_strlowcase.c \
	my_strcapitalize.c \
	my_str_isalpha.c \
	my_str_isnum.c \
	my_str_islower.c \
	my_str_isupper.c \
	my_str_isprintable.c \
	my_strcat.c \
	my_strncat.c \
	my_putnbr_base.c \
	my_countbr.c \
	my_putnbr_unsign.c \
	my_putnbr_baseu.c \
	my_countbru.c  \
	fs.c \
	fs-2.c \
	fs-3.c \
	my_printf.c \
	my_memset.c \
	xread.c \

OBJ=	$(SRCC:.c=.o) 	
NAME=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib libmy.a

clean:
		rm -f libmy.a
		rm -f $(OBJ)
.PHONY : all clean fclean re
