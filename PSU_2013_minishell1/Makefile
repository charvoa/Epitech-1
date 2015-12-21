##
## Makefile for makefile in /home/charvo_a/rendu/Minishell
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Wed Dec 11 12:41:42 2013 Nicolas Charvoz
## Last update Mon Jan  6 22:56:30 2014 Nicolas Charvoz
##

SRCC=	./sources/my_str_to_wordtab.c \
	./sources/mini.c \
	./sources/main.c \
	./sources/my_cd.c \
	./sources/xfiles.c \
	./sources/strtotab.c \
	./sources/builtin.c \

OBJ=	$(SRCC:.c=.o)

CC=	gcc

FLAGS=	-g3 -W -Wall -O3 -ansi -pedantic -Wbad-function-cast -Wcast-align -Wcast-qual -Wchar-subscripts \
	-Winline -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes \
	-Wwrite-strings -std=c99 \

CCO=	-o

NAME=	mysh

LIB=	-L ./libraryprintf -lmy

all:	$(OBJ)
	$(CC) $(OBJ) $(CCO) $(NAME) $(LIB) $(FLAGS)

clean:
	rm -f ./sources/*.o

fclean:
	rm -f ./sources/*.o
	rm -f mysh

re:	fclean all clean