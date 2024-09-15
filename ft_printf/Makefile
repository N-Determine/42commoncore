NAME = libftprintf.a
COMP = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_putnbr_base_fd.c ft_putunbr_fd.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re