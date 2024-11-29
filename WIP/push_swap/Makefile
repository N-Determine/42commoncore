# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 20:32:04 by adeters           #+#    #+#              #
#    Updated: 2024/11/29 16:45:20 by adeters          ###   ########.fr        #
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

.PHONY: all clean fclean re tidy