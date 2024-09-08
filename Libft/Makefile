NAME = libft.a
COMP = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

	ar rc $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean re