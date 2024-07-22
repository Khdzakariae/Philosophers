/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosofers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:09:04 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/22 19:33:52 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->number_of_philosophers)
	{
		pthread_join(philos[i].thread_philo, NULL);
		i++;
	}
}

bool	monitoring(t_philo *philos, int ac)
{
	int	i;

	while (1)
	{
		i = -1;
		while (i++ < philos->data->number_of_philosophers)
		{
			if (ac == 6)
			{
				if (cheack_cont(philos) == false)
				{
					set_philo_died(philos);
					return (true);
				}
			}
			if (cheack_time_died(philos) == false)
			{
				set_philo_died(philos);
				print_msg(3, &philos[i], false);
				return (false);
			}
		}
		usleep(300);
	}
	return (true);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(20);
	while (1)
	{
		if (cheaak_died(philo) == false || cheack_cont(philo) == false)
			break ;
		if (philo->data->number_of_philosophers == 1)
		{
			
			pthread_mutex_lock(philo->first_fork->forks);
			print_msg(0, philo, true);
			ft_usleep(philo->data->time_to_sleep);
			pthread_mutex_unlock(philo->first_fork->forks);
			return NULL;
		}
		thinking(philo);
		if (philo->id % 2 != 0)
		{
			pthread_mutex_lock(philo->first_fork->forks);
			print_msg(0, philo, true);
			pthread_mutex_lock(philo->second_fork->forks);
			print_msg(0, philo, true);
		}
		else
		{
			pthread_mutex_lock(philo->second_fork->forks);
			print_msg(0, philo, true);
			pthread_mutex_lock(philo->first_fork->forks);
			print_msg(0, philo, true);
			
		}
		print_msg(4, philo, true);
		set_time(philo);
		ft_usleep(philo->data->time_to_eat);
		set_cont(philo);
		pthread_mutex_unlock(philo->second_fork->forks);
		pthread_mutex_unlock(philo->first_fork->forks);
		sleping(philo);
		usleep(300);
	}
	return (NULL);
}

void	start_simulation(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	start_time(true);
	data->start_time = the_time();
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philos[i].thread_philo, NULL, philosophers, &philos[i]);
		i++;
	}
}
