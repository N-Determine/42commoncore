NAME = pipex

COMP = cc
FLAGS = -Wall -Wextra -g # -Werror

SRCS = main.c free.c path.c errors.c helpers.c init.c
OFOLDER = objs
OPATH = objs/
OBJS = $(addprefix $(OPATH), $(SRCS:.c=.o))
ARCH = libft.a

COLOR = \033[1;32m
RESET = \033[0m

$(OPATH)%.o: %.c
	@mkdir -p $(OFOLDER)
	@$(COMP) $(FLAGS) -c $< -o $@

all: $(ARCH) $(NAME)

$(ARCH):
	@make --no-print-directory -C ./libft
	@cp ./libft/libft.a ./libft.a
	@echo "$(COLOR)make: $(ARCH) executed!$(RESET)"

$(NAME): $(OBJS) $(ARCH)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME) $(ARCH)
	@echo "$(COLOR)make: $(NAME) executed!$(RESET)"

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS)
	@rm -rf $(OFOLDER)
	@rm -rf $(ARCH)
	@echo "$(COLOR)make: clean executed!$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(COLOR)make: fclean executed!$(RESET)"

re: fclean all

tidy: all clean

.PHONY: all clean fclean re tidy
