NAME = pipex
NAME_B = pipex_bonus

COMP = cc
FLAGS = -Wall -Wextra -Werror -g

SRC_FILES = main.c free.c path.c errors.c helpers.c init.c commands.c
SRCS = $(addprefix src/, $(SRC_FILES))
SRC_FILES_B = main_bonus.c free_bonus.c path_bonus.c errors_bonus.c\
helpers_bonus.c init_bonus.c commands_bonus.c
SRCS_B = $(addprefix bonus/, $(SRC_FILES_B))

OFOLDER = objs
OPATH = objs/
OBJS = $(addprefix $(OPATH), $(SRC_FILES:.c=.o))
OBJS_B = $(addprefix $(OPATH), $(SRC_FILES_B:.c=.o))

ARCH = libft.a

COLOR = \033[1;32m
RESET = \033[0m

all: $(ARCH) $(NAME)

$(OPATH)%.o: src/%.c
	@mkdir -p $(OFOLDER)
	@$(COMP) $(FLAGS) -c $< -o $@

$(OPATH)%.o: bonus/%.c
	@mkdir -p $(OFOLDER)
	@$(COMP) $(FLAGS) -c $< -o $@

$(ARCH):
	@make --no-print-directory -C ./libft
	@cp ./libft/libft.a ./src/libft.a
	@echo "$(COLOR)make: $(ARCH) executed!$(RESET)"

$(NAME): $(OBJS) $(ARCH)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME) $(addprefix src/, $(ARCH))
	@echo "$(COLOR)make: $(NAME) executed!$(RESET)"

$(NAME_B): $(OBJS_B) $(ARCH)
	@$(COMP) $(FLAGS) $(OBJS_B) -o $(NAME_B) $(addprefix src/, $(ARCH))
	@echo "$(COLOR)make: $(NAME_B) executed!$(RESET)"

bonus: $(ARCH) $(NAME_B)

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS)
	@rm -rf $(OFOLDER)
	@rm -rf $(addprefix src/, $(ARCH))
	@rm -rf $(addprefix libft/, $(ARCH))
	@echo "$(COLOR)make: clean executed!$(RESET)"

fclean: clean
	@rm -rf 
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)
	@echo "$(COLOR)make: fclean executed!$(RESET)"

re: fclean all

tidy: all clean

.PHONY: all clean fclean re tidy
