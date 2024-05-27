#ifndef PHILO_BONNUS_H
# define PHILO_BONNUS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_data
{
	long			number_of_philosophers;
	long			time_to_died;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;

}					t_data;

int	check_arguments(int argc, char **argv, t_data *data);
#endif