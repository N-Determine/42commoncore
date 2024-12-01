# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 20:32:04 by adeters           #+#    #+#              #
#    Updated: 2024/12/01 15:48:21 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = cc

FLAGS = -Wall -Werror -Wextra -g

SRCS =	main.c print_ops.c print_errors.c check_overflow.c init.c\
		check_args.c filling.c ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c\
		dlist.c direction.c push_swap.c main_helpers.c block_sort.c

ARCH = libft.a

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./libft.a
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME) $(ARCH)

all: $(NAME)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME) $(ARCH)

clean:
	make clean -C ./libft
	rm -rf $(OBJS) $(ARCH)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

tidy: all clean

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

.PHONY: all clean fclean re tidy test3 test5 test100 test500