NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf.c ft_printf_c.c ft_printf_str.c ft_printf_hex.c \
ft_printf_dec_int.c ft_printf_u.c

OBJS = $(SRCS:.c=.o)
COMP = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Compilation rules -----------------------------
# Compile each .c file into a .o file
%.o: %.c
	$(COMP) $(FLAGS) -c $<

# Archive all object files into the static library
$(NAME): $(OBJS)
	$(AR) $(NAME) $^

# Targets --------------------------
# Builds the library
all: $(NAME)

# Removes object files(.o)
clean:
	$(RM) $(OBJS)

#Removes object files(.o) and the library(.a)
fclean: clean
	$(RM) $(NAME)

# Remove .o, .a and rebuilds
re: fclean all

.PHONY: all clean fclean re