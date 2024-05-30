#ifndef PHILO_BONNUS_H
# define PHILO_BONNUS_H

#include <semaphore.h>
#include <sys/stat.h> 
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
	long			must_eat;
	long			start_time;
	sem_t 			*semaphore;

}					t_data;

typedef struct s_philo
{
	int				pid;
	long			id;
	long			time_to_last_eat;
	long			cont;
	t_data			*data;
}					t_philo;


long	start_time(bool init);
long	the_time(void);
void	ft_usleep(long time);
void	sleping(t_philo *philo);
void	thinking(t_philo *philo);
void	print_msg(int flag, t_philo *philo, bool flage);
void  start_simulation(t_data *data, t_philo *philo);
t_philo  *initialize_philosophers(t_data *data);
int	check_arguments(int argc, char **argv, t_data *data);
#endif