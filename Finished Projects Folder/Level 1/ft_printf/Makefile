NAME = libftprintf.a
COMP = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_putnbr_base_fd.c ft_putunbr_fd.c ft_count_bytes.c ft_putchars_fd.c ft_puthexas_fd.c\
		ft_putnumbers_fd.c ft_putstr_fd_retbytes.c ft_puthexaident.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./libft.a
	mv ./libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re