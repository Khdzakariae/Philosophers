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

typedef struct s_data
{
	long	number_of_philosophers;
	long	time_to_died;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	start_time;
	bool	philosopher_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	_died;
	pthread_mutex_t _hbsso_l9lawi;


}			t_data;

typedef struct s_forks
{
	pthread_mutex_t	*forks;
}				t_forks;


typedef struct s_philo
{
	long		id;
	long		time_to_last_eat;
	t_data		*data;
	t_forks		*first_fork;
	t_forks		*second_fork;
	pthread_mutex_t time_mutex;
	pthread_t	thread_philo;
    
} 				t_philo;

bool cheack_time_died(t_philo *philos, int i);
void set_time(t_philo *philo , int i);
void set_philo_died(t_philo *philo);
bool cheaak_died(t_philo *philo);
bool monitoring(t_philo *philos); 
void sleping(t_philo *philo);
void thinking(t_philo *philo);
void ft_usleep(long time);
long	the_time(void);
void print_msg(int flag, t_philo *philo, bool flage) ;
long 	start_time(bool init);
void  start_simulation(t_data *data, t_philo *philos);
void cleanup(t_philo *philo, t_forks *forks, int number_of_philosophers) ;
t_forks* initialize_forks(int number_of_philosophers);
t_philo* initialize_philosophers(t_data *data, t_forks *forks);
int check_arguments(int argc, char **argv, t_data *data) ;

#endif