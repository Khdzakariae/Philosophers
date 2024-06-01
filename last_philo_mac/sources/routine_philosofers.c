/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosofers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:23:59 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/01 11:22:23 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	monitoring(t_philo *philos, int ac)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philos->data->number_of_philosophers)
		{
			if (ac == 6)
			{
				if (cheack_cont(philos) == false)
				{
					set_philo_died(philos);
					return (false);
				}
			}
			if (cheack_time_died(philos, i) == false)
			{
				set_philo_died(philos);
				print_msg(3, &philos[i], false);
				return (false);
			}
			i++;
		}
	}
	return (true);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (philo->id % 2 != 0)
	// 	usleep(200);
	while (1)
	{
		if (cheaak_died(philo) == false)
			break ;
		thinking(philo);
		pthread_mutex_lock(philo->first_fork->forks);
		print_msg(0, philo, true);
		pthread_mutex_lock(philo->second_fork->forks);
		print_msg(0, philo, true);
		print_msg(4, philo, true);
		ft_usleep(philo->data->time_to_eat);
		set_time(philo);
		set_cont(philo);
		pthread_mutex_unlock(philo->second_fork->forks);
		pthread_mutex_unlock(philo->first_fork->forks);
		sleping(philo);
		usleep(70);
	}
	return (NULL);
}

bool	start_simulation(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	start_time(true);
	data->start_time = the_time();
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&philos[i].thread_philo, NULL, philosophers,
				&philos[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}
