# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:19:36 by adeters           #+#    #+#              #
#    Updated: 2024/11/11 19:33:17 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = long
COMP = cc
FLAGS = -Wall -Werror -Wextra
XFLAGS = -lmlx -lXext -lX11 -g -lm
SRCS =	$(wildcard *.c)
ARCH = libft.a
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make multi -C ./libft
	cp ./libft/libft.a ./libft.a
	cc $(OBJS) -o $(NAME) $(ARCH) $(XFLAGS)

all: $(NAME)
	cc $(OBJS) -o $(NAME) $(ARCH) $(XFLAGS)

clean:
	rm -rf $(OBJS) $(ARCH)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

tidy: multi clean

multi:
	make --jobs=16

.PHONY: all clean fclean re bonus multi tidy