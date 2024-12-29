NAME = pipex

COMP = cc
FLAGS = -Wall -Wextra -g # -Werror

SRCS = main.c free.c path.c errors.c
OFOLDER = objs
OPATH = objs/
OBJS = $(addprefix $(OPATH), $(SRCS:.c=.o))
ARCH = libft.a

$(OPATH)%.o: %.c
	@mkdir -p $(OFOLDER)
	@$(COMP) $(FLAGS) -c $< -o $@

all: $(ARCH) $(NAME)

$(ARCH):
	@make --no-print-directory -C ./libft
	@cp ./libft/libft.a ./libft.a
	@echo "make: $(ARCH) executed!"

$(NAME): $(OBJS) $(ARCH)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME) $(ARCH)
	@echo "make: $(NAME) executed!"

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS)
	@rm -rf $(OFOLDER)
	@rm -rf $(ARCH)
	@echo "make: clean executed!"

fclean: clean
	@rm -rf $(NAME)
	@echo "make: fclean executed!"

re: fclean all

.PHONY: all clean fclean re