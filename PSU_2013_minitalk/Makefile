##
## Makefile for  in /home/charvo_a/Work/minitalk
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Wed Feb 26 10:10:59 2014 Nicolas Charvoz
## Last update Sat Mar 22 16:37:48 2014 Nicolas Charvoz
##

CC =		gcc

RM =		rm -f

CLIENT =	./client/client

SERVER =	./server/server

SRCLIENT =	./client/client.c \
		./client/my_memset.c \
		./client/fonc.c

CFLAGS	+=	-W -Wall -Werror -Wextra

LIB	=	-L ./libraryprintf/ -lmy -lncurses

OBJCLIENT =	$(SRCLIENT:.c=.o)

SRCSERVER =	./server/server.c \

OBJSERVER =	$(SRCSERVER:.c=.o)

all:	$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJCLIENT)
		$(CC) $(OBJCLIENT) -o $(CLIENT) $(LIB)

$(SERVER):	$(OBJSERVER)
		$(CC) $(OBJSERVER) -o $(SERVER) $(LIB)

clean:
		$(RM) $(OBJCLIENT) $(OBJSERVER)

fclean:		clean
		$(RM) $(CLIENT) $(SERVER)

re:		fclean all

.PHONY:		all fclean clean re
