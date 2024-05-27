NAME_BONUS = philo_bonus

INCLUDES = -I "includes/"

# FLAGS = -Wall -Wextra -Werror


SRC_PHILO__BONUS = sources/philosopuers_bonus.c \


all : $(NAME_BONUS)
	@echo "philo_bonus done by success [ ✅ ]"

$(NAME_BONUS) : $(SRC_PHILO__BONUS)
	@cc   $^  $(FLAGS) $(INCLUDES) -o philo_bonus

clean:
	@echo "clean [ ✅ ]"

fclean: clean
	@rm  -f philo_bonus
	@echo "fclean [ ✅ ]"


re: fclean all