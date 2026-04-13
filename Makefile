NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c validator.c analytics.c bench.c build.c free.c list.c node.c parser.c push.c rev_rotate.c rotate.c simple_sort.c medium_sort.c stack_utils.c swap.c validator_helpers.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
