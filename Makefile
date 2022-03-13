NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = ft_atol.c index_utils.c longsort.c \
	parse_arg.c push_swap.c sort_5ex.c \
	stack_init_and_index.c stack_operations_a.c \
	stack_operations_b.c stack_operations_both.c \
	stack_utils.c utils.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: libft $(NAME)

libft:
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft ./libft/libft.a -o $(NAME)

%.o: %.c push_swap.h libft/libft.h
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re:	fclean all