# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeters <adeters@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 16:34:00 by adeters           #+#    #+#              #
#    Updated: 2024/11/15 19:23:39 by adeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = cc
FLAGS = -Wall -Werror -Wextra
SRCS =	ft_atoi.c ft_itoa.c\
		ft_bzero.c ft_calloc.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
		ft_split.c ft_substr.c\
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		ft_tolower.c ft_toupper.c ft_str_tolower.c ft_str_toupper.c ft_lstadd_back.c\
		ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
		ft_lstmap.c ft_lstnew.c ft_lstsize.c
PRINTF = 
GNL	=	get_next_line/get_next_line.c
OBJS = $(SRCS:.c=.o) $(PRINTF:.c=.o) $(GNL:.c=.o)

MAKEFLAGS = --jobs

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
