NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC	= ops_push.c ops_rotate.c ops_rrotate.c ops_swap.c parse.c sort_adaptative.c sort_complex.c sort_medium.c \
	sort_simple.c stack_init.c stack_utils.c utils.c disorder.c push_swap.c check_flags.c

OBJ	= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re