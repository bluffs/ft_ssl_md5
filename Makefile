NAME = ft_ssl
SRC = main.c tools.c ft_error.c ft_md5.c ft_md5_tools.c ft_md5_tools2.c ft_md5_init.c ft_print_md5.c \
	  ft_print_sha256.c ft_sha256.c ft_sha256_tools.c ft_sha256_tools2.c
OBJ = $(SRC:.c=.o)
	LIBFT = libft/libft.a
	CC = gcc
	OPTION = -c -Iinc/
	FLAG = #-Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
		make -Clibft
		$(CC) -o $(NAME) $(FLAG) $(OBJ) $(LIBFT)

$(OBJ) : $(addprefix src/, $(SRC))
		$(CC) $(FLAG) $(OPTION) $(addprefix src/, $(SRC))

clean :
		make clean -Clibft
		rm -rf $(OBJ)

fclean : clean
		make fclean -Clibft
		rm -rf $(NAME)

re : fclean all
