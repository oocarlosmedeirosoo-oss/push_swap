NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC	= ops_push.c ops_rotate.c ops_rrotate.c ops_swap.c parse.c sort_adaptative.c sort_complex.c sort_medium.c \
	sort_simple.c stack_init.c stack_utils.c utils.c disorder.c main.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 