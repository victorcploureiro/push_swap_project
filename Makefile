# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:55:17 by vcarrara          #+#    #+#              #
#    Updated: 2024/05/16 17:10:05 by vcarrara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

NAME = push_swap
CC = cc
CFLAGS = -Wextra -Wall -Werror
INCLUDE = -I ./include -I ./libft/includes
LIBFT = ./libft/libft.a

SRC = src/main.c \
		src/s_cost.c \
		src/s_move.c \
		src/s_position.c \
		src/sort.c \
		src/st_assign_index.c \
		src/st_check_input.c \
		src/st_free.c \
		src/st_push.c \
		src/st_rotate.c \
		src/st_rr.c \
		src/st_swap.c \
		src/stack.c

OBJ = obj

SRCOBJ = $(SRC:%.c=$(OBJ)/%.o)

TOTAL_SRCS = $(words $(SRC))
COMPILED_SRCS = 0

all: libft $(NAME)

$(NAME): libft $(SRCOBJ)
	@$(CC) $(CFLAGS) $(SRCOBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compiled.$(NC)"

${OBJ}/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@$(eval COMPILED_SRCS = $(shell echo $$(($(COMPILED_SRCS) + 1))))
	@echo "$(BLUE)Progress: $(shell echo "scale=2; ($(COMPILED_SRCS) / $(TOTAL_SRCS)) * 100" | bc)%$(NC)"

libft:
	@make -C ./libft

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ)
	@echo "$(RED)Cleaned push_swap objects.$(NC)"

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)
	@echo "$(RED)Cleaned push_swap.$(NC)"

re: fclean all

.PHONY: all clean fclean re libft

# Easy testing

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l