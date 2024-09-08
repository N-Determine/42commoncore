# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 16:34:00 by adeters           #+#    #+#              #
#    Updated: 2024/09/08 18:56:03 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = cc
FLAGS = -Wall -Werror -Wextra
SRCS =	ft_calloc.c ft_itoa.c ft_memchr.c ft_memcpy.c\
		ft_memmove.c ft_split.c ft_strchr.c ft_strlcpy.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		ft_substr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
