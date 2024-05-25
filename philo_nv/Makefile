NAME = philo

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I "includes/"


SRC_PHILO = sources/philosophers.c   sources/parse_argument.c sources/utils.c sources/routine_philosofers.c\
			sources/philosofeers_utils.c \


all: $(NAME)
	@echo "philo done [ ✅ ]"


$(NAME): $(SRC_PHILO)
	@cc -fsanitize=thread -g $^  $(FLAGS) $(INCLUDES) -o philo

clean:
	@echo "clean [ ✅ ]"

fclean: clean
	@rm -f philo
	@echo "fclean [ ✅ ]"

re: fclean all
