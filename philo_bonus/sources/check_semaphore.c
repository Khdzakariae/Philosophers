/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_semaphore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:31 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/29 12:21:44 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

bool	cheaak_died(t_philo *philo)
{
	sem_wait(philo->data->semaphore_died);
	if (philo->data->philosopher_died == true)
	{
		sem_post(philo->data->semaphore_died);
		return (false);
	}
	sem_post(philo->data->semaphore_died);
	return (true);
}

bool	cheack_cont(t_philo *philo)
{
	sem_wait(philo->data->cont_semaphore);
	if (philo->data->cont > philo->data->must_eat)
	{
		sem_post(philo->data->cont_semaphore);
		return (false);
	}
	sem_post(philo->data->cont_semaphore);
	return (true);
}

bool	cheack_time_died(t_philo *philos)
{
	long	current_time;
	long	dure;

	sem_wait(philos->data->protect_last_eat);
	current_time = the_time();
	dure = current_time - philos->time_to_last_eat;
	if (dure >= philos->data->time_to_die)
	{
		sem_post(philos->data->protect_last_eat);
		return (false);
	}
	sem_post(philos->data->protect_last_eat);
	return (true);
}
