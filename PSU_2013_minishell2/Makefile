##
## Makefile for  in /home/charvo_a/rendu/PSU_2013_minishell2
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Sun Mar  9 16:26:49 2014 Nicolas Charvoz
## Last update Sun Mar  9 16:31:28 2014 Nicolas Charvoz
##

CC =		gcc

RM =		rm -f

MYSH =		mysh

SRCC =		./src/aff_prompt.c \
		./src/main.c \
		./src/parser.c \
		./src/parser2.c \
		./src/strtotab.c \
		./src/epur_str.c \
		./src/xfiles.c \
		./src/my_cd.c

LIB	=	-L ./libraryprintf/ -lmy

FLAGS	=	-W -Wall -Werror -Wextra -ansi -pedantic


OBJ =		$(SRCC:.c=.o)

all:		$(MYSH)

$(MYSH):	$(OBJ)
		$(CC) $(OBJ) -o $(MYSH) $(LIB) $(FLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(MYSH)

re:		fclean all

.PHONY:		re all fclean clean
