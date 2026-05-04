NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = lst_utils.c ope_rotate.c ope_swap_push.c utils.c veri_utils.c verifications.c push_swap.c alg_insertion_sort.c

$(NAME):
	cc -g -Wall -Werror -Wextra -o $(NAME) $(SRC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
