NAME = philo

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I "/nfs/homes/zel-khad/Desktop/philo_nv/includes/"


SRC_PHILO = sources/philosophers.c   sources/parse_argument.c sources/utils.c\


all: $(NAME)
	@echo "philo done [ ✅ ]"


$(NAME): $(SRC_PHILO)
	@cc  $^  $(FLAGS) $(INCLUDES) -o philo

clean:
	@echo "clean [ ✅ ]"

fclean: clean
	@rm -f philo
	@echo "fclean [ ✅ ]"

re: fclean all
