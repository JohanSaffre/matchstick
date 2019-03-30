##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	main.c \
		print_funcs.c \
		game.c \
		make_board.c \
		game_two.c \
		my_get_nbr.c \
		player.c \
		ia.c

NAME =	matchstick

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Werror -W

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
