NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = disorder_metric.c main.c ope_rotate.c ope_swap_push.c utils.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR) || true

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR) || true

re: fclean all

.PHONY: all clean fclean re

