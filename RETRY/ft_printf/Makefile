
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC	 =	ft_printf.c tools.c 


OBJ = $(SRC:.c=.o)
all: $(NAME)
	@echo "PRINTF DONE [✅]"


%.o : %.c
	@cc $(FLAGS) -c $< -o $@
	

$(NAME): $(OBJ)
	@ar rc $@ $^

clean:
	@rm -f $(OBJ) 

fclean: clean
	@rm -f $(NAME)

re: fclean all