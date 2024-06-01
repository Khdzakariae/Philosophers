/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:24:06 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/01 10:40:42 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->_died);
	philo->data->philosopher_died = true;
	pthread_mutex_unlock(&philo->data->_died);
}

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

void	set_cont(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->cont_mutix);
	philo->cont++;
	pthread_mutex_unlock(&philo->data->cont_mutix);
}

bool	cheack_cont(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->cont_mutix);
	if (philo->cont > philo->data->must_eat + 1)
	{
		pthread_mutex_unlock(&philo->data->cont_mutix);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->cont_mutix);
	return (true);
}

void	set_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->last_eat_mutix);
	philo->time_to_last_eat = the_time();
	pthread_mutex_unlock(&philo->data->last_eat_mutix);
}
