NAME = pipex

COMP = cc
FLAGS = -Wall -Wextra -g # -Werror

SRCS = main.c free.c path.c errors.c
OBJS = $(SRCS:.c=.o)
ARCH = libft.a

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o objs/$@

all: $(ARCHst) $(NAME)

$(ARCH):
	make -C ./libft
	cp ./libft/libft.a ./libft.a

$(NAME): $(OBJS) $(ARCH)
	$(COMP) $(FLAGS) $(addprefix objs/,$(OBJS)) -o $(NAME) $(ARCH)

clean:
	make clean -C ./libft
	rm -rf $(addprefix objs/,$(OBJS))

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(ARCH)
	rm -rf $(addprefix objs/,$(OBJS))

re: fclean all

make:
	make --jobs

.PHONY: all clean fclean re