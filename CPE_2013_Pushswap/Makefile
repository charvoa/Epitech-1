##
## Makefile for makefile in /home/charvo_a/rendu/CPE_2013_Pushswap
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Mon Jan  6 22:58:58 2014 Nicolas Charvoz
## Last update Mon Jan  6 23:17:00 2014 Nicolas Charvoz
##

SRCC=	./src/main.c \
	./src/list.c

LIB=	-L ./libraryprintf/ -lmy

FLAGS=	-W -ansi -pedantic

CC=	cc -o

NAME=	push_swap

all:
	$(CC) $(NAME) $(SRCC) $(LIB) $(FLAGS)

fclean:
	rm -f push_swap

re: fclean all