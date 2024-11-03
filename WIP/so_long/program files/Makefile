# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:19:36 by adeters           #+#    #+#              #
#    Updated: 2024/11/03 20:17:16 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = long
COMP = cc
FLAGS = -Wall -Werror -Wextra
XFLAGS = -lmlx -lXext -lX11 -g
SRCS =	main.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME) $(XFLAGS)

all: $(NAME)
	cc $(OBJS) -o $(NAME) $(XFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

tidy: all clean

multire: fclean quick
	
multi:
	make --jobs=16

.PHONY: all clean fclean re bonus multi multire tidy