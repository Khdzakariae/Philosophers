NAME = philo

# FLAGS = -Wall -Wextra -Werror

SRC_PHILO = sources/philosophers.c sources/ft_atoi.c  sources/argument_parser.c sources/utils.c\


all: $(NAME)
	@echo "philo done [ ✅ ]"


$(NAME): $(SRC_PHILO)
	@cc -fsanitize=thread -g3 $^  $(FLAGS) -o philo

clean:
	@echo "clean [ ✅ ]"

fclean: clean
	@rm -f philo
	@echo "fclean [ ✅ ]"

re: fclean all
