# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:19:36 by adeters           #+#    #+#              #
#    Updated: 2024/12/18 20:23:11 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
COMP = cc
FLAGS = -Wall -Werror -Wextra
XFLAGS = -lmlx -lXext -lX11 -g -lm
SRCS =	checker.c error_printer.c get_next_line.c handle_events.c\
init.c destroy.c load_map.c locate_pois.c main.c movement.c\
print_gamestate.c reachability.c
ARCH = libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./libft.a
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
	make --jobs

.PHONY: all clean fclean re bonus multi tidy