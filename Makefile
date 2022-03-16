NAME = push_swap

BONUS = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = ft_atol.c ind_utils.c longsort.c \
	parse_arg.c push_swap.c sort_5ex.c \
	stack_init_and_index.c stack_operations_a.c \
	stack_operations_b.c stack_operations_both.c \
	stack_utils.c utils.c

SRC_BONUS = checker_src/checker.c checker_src/check_rev_rot.c \
			checker_src/check_rot.c checker_src/check_swap.c \
			checker_src/check_push.c gnl/get_next_line.c \
			gnl/get_next_line_utils.c stack_init_and_index.c \
			utils.c ind_utils.c stack_utils.c parse_arg.c ft_atol.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

.PHONY: all clean fclean re libft bonus

all: libft $(NAME)

libft:
	make -C ./libft

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -Llibft ./libft/libft.a -o $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Llibft ./libft/libft.a -o $(NAME)

%.o: %.c push_swap.h libft/libft.h gnl/get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make fclean -C libft

re:	fclean all
