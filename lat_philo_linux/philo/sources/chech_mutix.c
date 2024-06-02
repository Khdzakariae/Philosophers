/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_mutix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:19:24 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/02 18:20:09 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	cheaak_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->_died);
	if (philo->data->philosopher_died == true)
	{
		pthread_mutex_unlock(&philo->data->_died);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->_died);
	return (true);
}

bool cheack_cont(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->cont_mutix);
	if (philo->cont > philo->data->must_eat + 1)
	{
		pthread_mutex_unlock(&philo->data->cont_mutix);
		return(false);
	}
	pthread_mutex_unlock(&philo->data->cont_mutix);
	return(true);
}

bool	cheack_time_died(t_philo *philos, int i)
{
	pthread_mutex_lock(&philos->data->set_time_mutix);
	long current_time = the_time();
	long dure = current_time - philos->time_to_last_eat;
	if (dure > philos->data->time_to_die)
	{
		pthread_mutex_unlock(&philos->data->set_time_mutix);
		return (false);
	}
	pthread_mutex_unlock(&philos->data->set_time_mutix);
	return (true);
}