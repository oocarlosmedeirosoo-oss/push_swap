NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = alg_chunk_based.c alg_insertion_sort.c alg_radix_sort.c \
	push_swap_utils.c helper_with_printf.c teste.c \
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re