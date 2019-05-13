##
## EPITECH PROJECT, 2018
## PSU_philosopher_2017
## File description:
## makefile
##

CC      = gcc

RM      = rm -rf

NAME    = lemipc

SRCS    =   src/main.c		        \
		    src/map_handling.c	    \
		    src/init_ipc.c		    \
		    src/sem_handling.c	    \
		    src/check_map.c		    \
		    src/end_game.c		    \
		    src/play_game.c         \
		    src/move_handling.c     \
		    src/move_handling2.c    \
		    src/check_death.c

OBJS    = $(SRCS:.c=.o)

CFLAGS  =  -W -Wall -Wextra -I include -g3

all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
