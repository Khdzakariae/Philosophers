NAME_BONUS = philo_bonus

INCLUDES = -I "includes/"

# FLAGS = -Wall -Wextra -Werror  
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
# FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address



SRC_PHILO__BONUS = sources/philosopuers_bonus.c sources/parse_argumants.c sources/utils.c \
				   sources/utils.c sources/philosofeers_bonus_utils.c sources/retine_Philosophers.c\
				   sources/check_semaphore.c sources/set_semaphore.c


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