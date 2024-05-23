/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:33 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/23 16:52:01 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define INT_MAX 2147483647

typedef struct s_list
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long long  start_time;
	bool philosopher_died;
	int mat;
	pthread_mutex_t philosopher_died_mutex;
	pthread_mutex_t _died;
	pthread_mutex_t print_mutex;
	pthread_mutex_t p_1;

}			t_data;

typedef struct s_forks
{
	pthread_mutex_t	forks;
	int				id;	
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread_philo;
	long		id;
	t_data		*data;
	t_fork		*first_fork;
	t_fork		*second_fork;
	long	time_to_last_eat;
	pthread_mutex_t time_mutex;
} t_philo;

bool cheaak_died(t_philo *philo);
void sleping(t_philo *philo);
void thinking(t_philo *philo);
long	the_time(void);
long		ft_atoi(char *str);
bool		cheack(t_data *data, char **av);
void ft_usleep(long time, t_data *data);
long 	start_time(bool init);
void print_msg(int flag, t_philo *philo, bool flage);



#endif