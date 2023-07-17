NAME = push_swap
NAME_BONUS = checker
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCD = ./src

SRCD_BONUS = ./src_checker

SRC = push_swap.c \
	ft_arg_validate.c \
	ft_exit.c \
	ft_move.c \
	ft_operations_push_swap.c \
	ft_operations_rotate.c \
	ft_optimize_a.c \
	ft_optimize_moves.c \
	ft_solve.c \
	ft_stack_a.c \
	ft_stack_utils.c \

OBJ = $(SRC:%.c=$(SRCD)/%.o)

SRC_BONUS = checker.c \
	ft_exit.c \
	ft_operations_push_swap.c \
	ft_operations_rotate.c \
	ft_stack_a.c \
	ft_stack_utils.c \
	ft_process.c \

OBJ_BONUS = $(SRC_BONUS:%.c=$(SRCD_BONUS)/%.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(LIBFT):	
	$(MAKE) -C libft

$(SRCD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Llibft -lft  -o $(NAME_BONUS)

$(SRCD_BONUS)/%.o: $(SRCD_BONUS)/%.c\
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(LIBFT)

re: fclean all clean

re_bonus: fclean all bonus clean

.PHONY: all bonus libft clean fclean re re_bonus