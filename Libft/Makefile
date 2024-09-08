NAME = libft.a
COMP = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	$(COMP) $(FLAGS) -c $(SRCS) -o $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): %.o
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re