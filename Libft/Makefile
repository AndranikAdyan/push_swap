NAME		= libft.a
BUILD		= ./build
SRC			= ./src
SRCS		= $(shell find $(SRC) -name '*.c')
OBJS		= $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))
HEADER		= libft.h
RM			= rm -f
AR			= ar rcs
CC			= cc
FLAGS		= -Wall -Wextra -Werror

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
		@$(CC) $(FLAGS) -I. -c $< -o $@

all:			$(BUILD) $(NAME)

$(NAME):		$(OBJS)
		@$(AR) $(NAME) $(OBJS)

$(BUILD):
		@mkdir -p $(BUILD)

clean:
		@rm -rf $(BUILD)

fclean:
		@rm -rf $(BUILD)
		@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re