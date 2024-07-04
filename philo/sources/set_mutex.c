/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:09:08 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/02 18:59:34 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	set_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->_died);
	philo->data->philosopher_died = true;
	pthread_mutex_unlock(&philo->data->_died);
}

void	set_cont(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->cont_mutix);
	philo->cont++;
	pthread_mutex_unlock(&philo->data->cont_mutix);
}

void	set_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->set_time_mutix);
	philo->time_to_last_eat = the_time();
	pthread_mutex_unlock(&philo->data->set_time_mutix);
}
