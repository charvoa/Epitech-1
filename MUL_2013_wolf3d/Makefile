##
## Makefile for make file wolf in 
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Sun Jan 12 15:22:46 2014 Nicolas Charvoz
## Last update Sun Jan 12 15:06:27 2014 Nicolas Charvoz
##

SRC=		./sources/calculs.c \
		./sources/init.c \
		./sources/main.c \
		./sources/my_putstr.c \
		./sources/print.c \
		./sources/initprint.c

MLX=		-L ./sources/minilibx/ -lmlx -lX11 -lXext

CC=		cc -o

LM=		-lm

NAME=		wolf3d

all:
		$(CC) $(NAME) $(SRC) $(LM) $(MLX)

fclean:
	rm $(NAME)

re:	fclean all

