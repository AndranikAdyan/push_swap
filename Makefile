NAME	= push_swap

BUILD	= ./build

SRC =	./src

SRCS	= $(shell find $(SRC) -name '*.c')

OBJS	= $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

INC =	-I ./includes

HEADER =	./includes/push_swap.h

FLAGS =	-Wall -Wextra -Werror -fsanitize=address -g3

all:	$(BUILD) $(NAME)

RESET			= \033[0m
YELLOW			= \033[38;2;255;239;0m
GREEN			= 	\033[0;32m

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
				@echo "${GREEN} Compiling $<${RESET}"
				@$(CC) $(FLAGS) $(INC) -c $< -o $@

${NAME}:	${OBJS}
			@$(CC) $(FLAGS) $(OBJS) $(INC) -o ${NAME}
			@echo "${YELLOW}Done! ${RESET}"

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	@rm -rf $(BUILD)
	@echo "${YELLOW}Done Cleaning! ${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@echo "${YELLOW}Done Fcleaning! ${RESET}"

re:	fclean all

.PHONY: all clean fclean re
