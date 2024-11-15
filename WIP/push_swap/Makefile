# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 20:32:04 by adeters           #+#    #+#              #
#    Updated: 2024/11/15 20:48:46 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = cc

FLAGS = -Wall -Werror -Wextra

SRCS =	push_swap.c print_ops.c

ARCH = libft.a

OBJS = $(SRCS:.c=.o)

MAKEFLAGS = --jobs

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./libft.a
	cc $(OBJS) -o $(NAME) $(ARCH)

all: $(NAME)
	cc $(OBJS) -o $(NAME) $(ARCH)

clean:
	rm -rf $(OBJS) $(ARCH)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

tidy: multi clean

.PHONY: all clean fclean re tidy