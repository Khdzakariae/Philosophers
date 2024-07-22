/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_semaphore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:31:22 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/22 19:50:54 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	set_philo_died(t_philo *philo)
{
	sem_wait(philo->data->semaphore_died);
	philo->data->philosopher_died = true;
	sem_post(philo->data->semaphore_died);
}

void	set_cont(t_philo *philo)
{
	sem_wait(philo->data->cont_semaphore);
	philo->data->cont++;
	sem_post(philo->data->cont_semaphore);
}

void	set_time(t_philo *philo)
{
	sem_wait(philo->data->protect_last_eat);
	philo->time_to_last_eat = the_time();
	sem_post(philo->data->protect_last_eat);
}
