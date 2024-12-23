NAME = pipex

COMP = cc
FLAGS = -Wall -Wextra -g # -Werror

SRCS = main.c free.c path.c errors.c
OBJS = $(SRCS:.c=.o)
OPATH = objs/
ARCH = libft.a

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $(OPATH)$@

all: $(ARCH) $(NAME)

$(ARCH):
	make -C ./libft
	cp ./libft/libft.a ./libft.a

$(NAME): $(OBJS) $(ARCH)
	$(COMP) $(FLAGS) $(addprefix $(OPATH),$(OBJS)) -o $(NAME) $(ARCH)

clean:
	make clean -C ./libft
	rm -rf $(addprefix $(OPATH),$(OBJS))

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(ARCH)

re: fclean all

make:
	make --jobs

.PHONY: all clean fclean re