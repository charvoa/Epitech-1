##
## Makefile for makefile in /home/charvo_a/Work/select2
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Thu Jan 16 15:18:31 2014 Nicolas Charvoz
## Last update Sun Jan 19 19:16:11 2014 Nicolas Charvoz
##

SRCC=	list.c \
	fonc.c \
	fonc2.c \

LIB=	-lncurses

LIBPRINT=	-L ../libraryprintf/ -lmy -g3

FLAGS=	-W -Wall -ansi -pedantic

NAME=	my_select

CC=	cc -o

all:
	$(CC) $(NAME) $(SRCC) $(LIB) $(LIBPRINT) $(FLAGS)

clean:
	rm -f my_select

re:	clean all
