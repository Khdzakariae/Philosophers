
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
NAME = so_long.a

SRC_1_2	 =	test.c key_press.c pixel_put.c


OBJ = $(SRC_1_2:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all