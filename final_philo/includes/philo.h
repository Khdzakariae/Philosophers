/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:09:19 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/03 09:55:23 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	long			must_eat;
	long			time_to_died;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	bool			philosopher_died;
	pthread_mutex_t	cont_mutix;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	_died;
	pthread_mutex_t	set_time_mutix;

}					t_data;

typedef struct s_forks
{
	pthread_mutex_t	*forks;
}					t_forks;

typedef struct s_philo
{
	long			id;
	long			time_to_last_eat;
	long			cont;
	t_data			*data;
	t_forks			*first_fork;
	t_forks			*second_fork;
	pthread_t		thread_philo;

}					t_philo;

bool				cheaak_died(t_philo *philo);
bool				cheack_cont(t_philo *philo);
bool				cheack_time_died(t_philo *philos);

int					ft_isdigit(int c);
void				generating_number(char **str, long *result);
long				ft_atoi(char *str);
bool				cheack(t_data *data, char **av, int argc);
int					check_arguments(int argc, char **argv, t_data *data);

void				cleanup_forks(t_forks *forks, int j);
void				cleanup(t_philo *philo, t_forks *forks,
						int number_of_philosophers);
void				print_msg(int flag, t_philo *philo, bool flage);
t_forks				*initialize_forks(int number_of_philosophers);
t_philo				*initialize_philosophers(t_data *data, t_forks *forks);

void				join_threads(t_philo *philos);
bool				monitoring(t_philo *philos, int ac);
void				*philosophers(void *arg);
void				start_simulation(t_data *data, t_philo *philos);

void				set_philo_died(t_philo *philo);
void				set_cont(t_philo *philo);
void				set_time(t_philo *philo);

long				start_time(bool init);
long				the_time(void);
void				ft_usleep(long time);
void				sleping(t_philo *philo);
void				thinking(t_philo *philo);

#endif