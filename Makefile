NAME = ft_ssl
SRC = main.c tools.c ft_error.c
OBJ = $(SRC:.c=.o)
	LIBFT = libft/libft.a
	CC = gcc
	OPTION = -c -Iinc/
	FLAG = -Wall -Werror -Wextra

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
