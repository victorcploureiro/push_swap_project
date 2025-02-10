RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

NAME = libft.a

SRCS = $(wildcard ./srcs/*.c)
OBJS = $(patsubst ./srcs/%.c, ./objs/%.o, $(SRCS))

PATH_OBJS = ./objs/
INCLS = -I ./includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "$(GREEN)Compiled libft.$(NC)"

$(PATH_OBJS)%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJS)
	@rm -rf $(PATH_OBJS_BONUS)
	@echo "$(RED)Cleaned objs.$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Cleaned libft.$(NC)"

re: fclean all

.PHONY: all clean fclean re