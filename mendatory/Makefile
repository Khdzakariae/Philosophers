
FLAGS = -Wall -Wextra -Werror 
NAME = so_long

SRC_1_2	 =	so_long.c assists/itoa.c assists/assists2.c assists/assists1.c prasin/parssin.c prasin/parssin2.c \
			prasin/parssin3.c  animation/animation.c key_press/key_press.c  prasin/parssin4.c 

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

OBJ = $(SRC_1_2:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT) :
	@make -C libft

$(PRINTF) :
	@make -C ft_printf

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit  -o $(NAME)
	@echo "SO_LONG DONE [🤡]"
clean:
	@echo "CLEAN DONE [✅]"
	@rm -f $(OBJ) 
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	@echo "FCLEAN DONE [✅]"
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
	
re: fclean all
	@echo "REBUILD DONE [✅]"
