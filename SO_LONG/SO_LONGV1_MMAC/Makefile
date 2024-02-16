
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
NAME = so_long.a

SRC_1_2	 =	so_long.c assists/itoa.c assists/assists2.c assists/assists1.c prasin/parssin.c prasin/parssin2.c \
			prasin/parssin3.c  animation/animation.c key_press/key_press.c  prasin/parssin4.c 

LIB = libft/libft.a

OBJ = $(SRC_1_2:.c=.o)
all: $(NAME)
	@echo "LIB DONE ✅"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all