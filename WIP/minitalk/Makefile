# Program names
NAME_S = server
NAME_C = client

# Compiling options
COMP = cc
FLAGS = -Wall -Werror -Wextra

# Source Files
SRCS_B = errors.c
SRCS_S = server.c
SRCS_C = client.c

# Object Files
OBJS_B = $(SRCS_B:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

# Archives
ARCH = libft.a

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

all: server client

$(NAME_S): $(OBJS_S) $(OBJS_B) $(ARCH)
	$(COMP) $(FLAGS) $(OBJS_S) $(OBJS_B) -o $(NAME_S) $(ARCH)

$(NAME_C): $(OBJS_C) $(OBJS_B) $(ARCH)
	$(COMP) $(FLAGS) $(OBJS_C) $(OBJS_B) -o $(NAME_C) $(ARCH)

clean:
	rm -rf $(OBJS_B) $(OBJS_C) $(OBJS_S)
fclean: clean
	rm -rf $(NAME_S) $(NAME_C)

re: fclean all

tidy: all clean

.PHONY: all clean fclean re tidy