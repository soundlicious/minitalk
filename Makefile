##
## Makefile for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
## 
## Made by exposi_p
## Login   <exposi_p@epitech.net>
## 
## Started on  Mon Mar 17 17:52:04 2014 exposi_p
## Last update Sat Mar 22 15:45:42 2014 exposi_p
##

CC              =       gcc

SERVER		=	server

CLIENT		=	client

SRCGEN		=	./src/server/my_putchar.c \
			./src/server/my_put_nbr.c \
			./src/server/my_putstr.c \
			./src/client/my_getnbr.c \
			./src/client/my_getnbrbase.c \
			./src/client/my_strlen.c \

SRCS		=	./src/server/main.c \
			./src/server/get_string.c \
			./src/server/xmalloc.c

SRCC		=	./src/client/main.c \
			./src/client/check_arg.c \
			./src/client/check_pid.c \
			./src/client/gentleman.c \

OBJSS		=	$(SRCS:.c=.o)

OBJSC		=	$(SRCC:.c=.o)

OBJGEN		=	$(SRCGEN:.c=.o)

CFLAGS          =       -W

MV              =       mv

RM              =       rm -rf

all		:	$(SERVER) $(CLIENT)

$(CLIENT)	:	$(OBJSC) $(OBJGEN)
			$(CC) -o $(CLIENT) $(OBJSC) $(OBJGEN) -I./includes/client/

$(SERVER)	:	$(OBJSS) $(OBJGEN)
			$(CC) -o $(SERVER) $(OBJSS) $(OBJGEN) -I./includes/server/

clean		:
			$(RM) *.o */*.o

fclean		:	clean
			$(RM) $(SERVER) $(CLIENT)

re		:	all

.PHONY : all clean re
