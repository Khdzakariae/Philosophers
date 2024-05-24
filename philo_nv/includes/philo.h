#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	bool philosopher_died;

}			t_data;

typedef struct s_forks
{
	pthread_mutex_t	*forks;
}				t_forks;


typedef struct s_philo
{
	long		id;
	t_data		*data;
	t_forks		*first_fork;
	t_forks		*second_fork;
    
} 				t_philo;
void cleanup(t_philo *philo, t_forks *forks, int number_of_philosophers) ;
t_forks* initialize_forks(int number_of_philosophers);
t_philo* initialize_philosophers(t_data *data, t_forks *forks);
int check_arguments(int argc, char **argv, t_data *data) ;

#endif