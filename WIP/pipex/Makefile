NAME = pipex

COMP = cc
# FLAGS = -Wall -Werror -Wextra -g

SRCS = main.c free.c
OBJS = $(SRCS:.c=.o)
ARCH = libft.a

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

all: $(ARCH) $(NAME)

$(ARCH):
	make -C ./libft
	cp ./libft/libft.a ./libft.a

$(NAME): $(OBJS) $(ARCH)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME) $(ARCH)

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(ARCH)

re: fclean all

tidy: all clean

make:
	make --jobs

.PHONY: all clean fclean re tidy arch