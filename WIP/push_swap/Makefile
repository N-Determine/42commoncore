# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 20:32:04 by adeters           #+#    #+#              #
#    Updated: 2024/11/28 17:39:05 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = cc

FLAGS = -Wall -Werror -Wextra -g

SRCS =	push_swap.c print_ops.c print_errors.c check_overflow.c init.c\
		check_args.c filling.c ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c\
		dlist.c testing.c direction.c algorithms.c main_helpers.c block_sort.c

ARCH = libft.a

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./libft.a
	cc $(OBJS) -o $(NAME) $(ARCH)

all: $(NAME)
	cc $(OBJS) -o $(NAME) $(ARCH)

clean:
	make clean -C ./libft
	rm -rf $(OBJS) $(ARCH)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

tidy: all clean

.PHONY: all clean fclean re tidy