NAME		=	push_swap

BONUS_NAME	=	checker

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	libft
LIBFT		=	-Llibft -lft

INCLUDES	=	-I./includes -I./libft

HEADER		=	./includes/push_swap.h

BONUS_HEADER	=	./includes/checker.h

SRC_DIR		=	./src

BONUS_DIR	=	./bonus

SRCS		=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parse_functions.c \
				$(SRC_DIR)/ft_lstsize.c \
				$(SRC_DIR)/ft_reverse_rotate.c \
				$(SRC_DIR)/ft_lstadds.c \
				$(SRC_DIR)/sorting.c \
				$(SRC_DIR)/butterfly.c \
				$(SRC_DIR)/ft_free_split.c \
				$(SRC_DIR)/ft_swap.c \
				$(SRC_DIR)/ft_atol.c \
				$(SRC_DIR)/math.c \
				$(SRC_DIR)/stack.c \
				$(SRC_DIR)/sort_stack.c \
				$(SRC_DIR)/ft_rotate.c \
				$(SRC_DIR)/ft_push.c

BONUS_SRCS	=	$(BONUS_DIR)/parse_functions_bonus.c \
				$(BONUS_DIR)/main_bonus.c \
				$(BONUS_DIR)/ft_lstsize_bonus.c \
				$(BONUS_DIR)/ft_reverse_rotate_bonus.c \
				$(BONUS_DIR)/ft_free_split_bonus.c \
				$(BONUS_DIR)/ft_swap_bonus.c \
				$(BONUS_DIR)/ft_atol_bonus.c \
				$(BONUS_DIR)/checker_bonus.c \
				$(BONUS_DIR)/stack_bonus.c \
				$(BONUS_DIR)/ft_rotate_bonus.c \
				$(BONUS_DIR)/ft_lstadds_bonus.c \
				$(BONUS_DIR)/ft_push_bonus.c
				
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRCS))

BONUS_OBJS	=	$(patsubst $(BONUS_DIR)/%.c, $(BUILD)/%.o, $(BONUS_SRCS))

BUILD		=	./build

all: build lib $(NAME)

$(BUILD)/%.o: $(SRC_DIR)/%.c Makefile $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(BUILD)/%.o: $(BONUS_DIR)/%.c Makefile $(BONUS_HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBFT)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT)

build:
	mkdir -p $(BUILD)

lib:
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(BUILD)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

bonus: build lib $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus lib build