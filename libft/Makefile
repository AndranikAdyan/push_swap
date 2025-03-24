MAKEFLAGS += --no-print-directory

NAME		=	libft.a
BUILD		=	./build
SRCS_DIR	=	./src
SRCS		=	./src/ft_isalpha.c \
				./src/ft_striteri.c \
				./src/ft_tolower.c \
				./src/ft_memset.c \
				./src/ft_strlcpy.c \
				./src/ft_strchr.c \
				./src/ft_isascii.c \
				./src/ft_memmove.c \
				./src/ft_strcmp.c \
				./src/ft_memcpy.c \
				./src/ft_strrchr.c \
				./src/ft_strmapi.c \
				./src/ft_calloc.c \
				./src/ft_memchr.c \
				./src/ft_strlcat.c \
				./src/ft_bzero.c \
				./src/ft_strjoin.c \
				./src/ft_strjoin_free.c \
				./src/ft_strnstr.c \
				./src/ft_strlen.c \
				./src/ft_itoa.c \
				./src/ft_atoi.c \
				./src/ft_strdup.c \
				./src/ft_putstr_fd.c \
				./src/ft_strncmp.c \
				./src/ft_isprint.c \
				./src/ft_toupper.c \
				./src/ft_isalnum.c \
				./src/ft_memcmp.c \
				./src/ft_substr.c \
				./src/ft_isdigit.c \
				./src/ft_split.c \
				./src/ft_strtrim.c \
				./src/get_next_line.c

OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(BUILD)/%.o, $(SRCS))
HEADER		=	libft.h
AR			=	ar rcs
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror

RED			= \033[0;31m
YELLOW		= \033[0;33m
B_YELLOW	= \033[1;33m
RESET		= \033[0m

all:			$(BUILD) $(NAME)

$(BUILD)/%.o:	$(SRCS_DIR)/%.c $(HEADER) Makefile
		@echo "$(YELLOW) Compiling $< $(RESET)"
		@$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME):		$(OBJS)
		@echo "$(B_YELLOW) Libft Done! $(RESET)"
		@$(AR) $(NAME) $(OBJS)

$(BUILD):
		@mkdir -p $(BUILD)

clean:
	@echo "$(RED) Removing Libft Objects $(RESET)"
	@rm -rf $(BUILD)

fclean:
	@echo "$(RED) Removing Libft Archive $(RESET)"
	@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re