
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
NAME = so_long.a

SRC_1_2	 =	so_long.c assists/itoa.c assists/assists2.c assists/assists1.c prasin/parssin.c prasin/parssin2.c \
			prasin/parssin3.c  animation/animation.c key_press/key_press.c  prasin/parssin4.c 

LIB = libft/libft.a

OBJ = $(SRC_1_2:.c=.o)
all: $(NAME)
	@echo "LIB DONE ✅"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ)   $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all