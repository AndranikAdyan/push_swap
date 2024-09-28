NAME	= push_swap

# BONUS	= checker

BUILD	= ./build

SRC		= ./src

# SRC_B	= ./bonus_src

SRCS	= $(shell find $(SRC) -name '*.c')

SRCS_B	= $(shell find $(SRC_B) -name '*.c')

OBJS	= $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

OBJS_B	= $(patsubst $(SRC_B)%/.c, $(BUILD)/%.o, $(SRCS_B))

INC		= -I ./includes

# INC_B	= -I ./bonus_includes

HEADER	= ./includes/push_swap.h

# HEADER_B	= ./bonus_includes/checker.h

FLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g3

all:	$(BUILD) $(NAME)

RESET			= \033[0m
YELLOW			= \033[38;2;255;239;0m
GREEN			= 	\033[0;32m

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
				@echo "${GREEN} Compiling $<${RESET}"
				@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(BUILD)/%.o:	$(SRC_B)/%.c $(HEADER_B) Makefile
				@echo "${GREEN} Compiling $<${RESET}"
				@$(CC) $(FLAGS) $(INC_B) -c $< -o $@

${NAME}:		${OBJS}
			@$(CC) $(FLAGS) $(OBJS) $(INC) -o ${NAME}
			@echo "${YELLOW}Done Compiling! ${RESET}"

# ${BONUS}:		${OBJS_B}
# 			@$(CC) $(FLAGS) $(OBJS_B) $(INC_B) -o ${BONUS}
# 			@echo "${YELLOW}Done! ${RESET}"

$(BUILD):
	@mkdir -p $(BUILD)

# bonus: $(BUILD) $(BONUS)

clean:
	@rm -rf $(BUILD)
	@echo "${YELLOW}Done Cleaning! ${RESET}"

fclean:		clean
			@rm -f ${NAME} ${BONUS}
			@rm -f ${NAME}
			@echo "${YELLOW}Done Fcleaning! ${RESET}"

re:	fclean all

.PHONY: all clean fclean re
