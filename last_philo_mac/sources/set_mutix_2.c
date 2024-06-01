/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutix_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:39:31 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/01 10:39:49 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	cheack_time_died(t_philo *philos, int i)
{
	pthread_mutex_lock(&philos->data->last_eat_mutix);
	long current_time = the_time();
	long dure = current_time - philos->time_to_last_eat;
	if (dure >= philos->data->time_to_die)
	{
		pthread_mutex_unlock(&philos->data->last_eat_mutix);
		return (false);
	}
	pthread_mutex_unlock(&philos->data->last_eat_mutix);
	return (true);
}