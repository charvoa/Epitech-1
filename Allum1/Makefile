##
## Makefile for makefile in /home/charvo_a/Work/alum1
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Fri Feb  7 13:48:35 2014 Nicolas Charvoz
## Last update Sat Feb 21 11:54:48 2015 Nicolas Charvoz
##
NAME=	allum1

CC=	cc -o

SRC=	./src

FILES=	$(SRC)/alum1.c \
	$(SRC)/fonc.c \
	$(SRC)/fonc2.c

LIB=	-L ./libraryprintf/ -lmy -lncurses

HEADERS=	-I./headers/

FLAGS=	-W -Werror -Wextra -Wall -pedantic -ansi

RM=	rm -f

all:
	$(CC) $(NAME) $(FILES) $(HEADERS) $(LIB) $(FLAGS)

clean:
	$(RM)  $(NAME)

fclean: clean

re:	clean all

.PHONY:	clean fclean all re
