##
## Makefile for Makfile projet in /home/charvo_a/rendu/PSU_2013_my_ls
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Sun Dec  1 10:01:41 2013 Nicolas Charvoz
## Last update Sun Dec  1 11:12:08 2013 Nicolas Charvoz
##

SRCC=	d_flag.c \
	l_flag.c \
	r_flag.c \
	no_flag.c \
	main.c \
	xmalloc.c \

OBJ=	$(SRCC=.c=.o)

CC=	cc

LIB=	-L ./library/ -lmy

NAME=	MyLs

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRCC) $(LIB)
		mv a.out MyLs

clean:
	rm -f *.o

fclean:
	rm -f MyLs
	rm -f $(OBJ)

re:	fclean \
	all
