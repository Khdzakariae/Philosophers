NAME = philo
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3
# FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3


INCLUDES = -I "includes/"


SRC_PHILO = sources/philosophers.c   sources/parse_argument.c sources/utils.c sources/routine_philosofers.c\
			sources/philosofeers_utils.c sources/set_mutex.c sources/chech_mutix.c\


all: $(NAME)
	@echo "philo done by success [ ✅ ]"


$(NAME): $(SRC_PHILO)
	@cc   $^  $(FLAGS) $(INCLUDES) -o philo

clean:
	@echo "clean [ ✅ ]"

fclean: clean
	@rm -f philo
	@echo "fclean [ ✅ ]"

re: fclean all
