/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:40:12 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/04 18:40:46 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_data
{
	int			arg;
	long		number_of_philosophers;
	long		time_to_died;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		must_eat;
	long		start_time;
	bool		philosopher_died;
	sem_t		*semaphore1;
	sem_t		*semaphore;
	sem_t		*protect_last_eat;
	sem_t		*protect_count;

}				t_data;

typedef struct s_philo
{
	pid_t		pid;
	long		id;
	long		time_to_last_eat;
	long		cont;
	t_data		*data;
	pthread_t	thread_philo;
}				t_philo;

bool			cheaak_died(t_philo *philo);
void			set_philo_died(t_philo *philo);
void			arrete(t_philo *philo);
void			set_time(t_philo *philo);
long			start_time(bool init);
long			the_time(void);
void			ft_usleep(long time);
void			sleping(t_philo *philo);
void			thinking(t_philo *philo);
void			print_msg(int flag, t_philo *philo, bool flage);
void			start_simulation(t_data *data, t_philo *philo);
t_philo			*initialize_philosophers(t_data *data);
int				check_arguments(int argc, char **argv, t_data *data);

#endif