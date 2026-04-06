NAME = push_swap

CC = CC
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c validator.c
OBJS = $(SRCS:.c= .o)

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
		rm -rf $(OBJS)
		make -C $(LIBFT_DIR) clean

fclean:
		rm -rf $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all