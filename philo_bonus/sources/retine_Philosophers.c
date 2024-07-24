/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retine_Philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:42:00 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/24 19:10:55 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->arg == 6 && cheack_cont(philo) == false)
		{
			pthread_join(philo->thread_philo, NULL);
			exit(0);
		}
		if (cheack_time_died(philo) == false)
		{
			set_philo_died(philo);
			// print_msg(3, philo, false);
			// arrete(philo);
			exit(philo->id + 1);
		}
	}
	return (NULL);
}

void	retine(t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		if (philo->data->arg == 6 && cheack_cont(philo) == false)
			exit(0);
		thinking(philo);
		sem_wait(philo->data->forks_semaphore);
		print_msg(0, philo, true);
		sem_wait(philo->data->forks_semaphore);
		print_msg(0, philo, true);
		set_time(philo);
		print_msg(4, philo, true);
		ft_usleep(philo->data->time_to_eat);
		set_cont(philo);
		sem_post(philo->data->forks_semaphore);
		sem_post(philo->data->forks_semaphore);
		print_msg(1, philo, true);
		ft_usleep(philo->data->time_to_sleep);
		usleep(300);
	}
}

// arg 6 exit 0 ===> wait
// time to die ===> killall
void	start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	start_time(true);
	while (i < data->number_of_philosophers)
	{
		philo[i].pid = fork();
		// printf("------------> |%d|",philo[i].pid);
		if (philo[i].pid == 0)
		{	
			pthread_create(&philo[i].thread_philo, NULL, monitoring, &philo[i]);
			pthread_detach(philo[i].thread_philo);
			retine(&philo[i]);
			exit(0);
		}
		i++;
	}
	// i = 0;
	// while( wait(NULL) != -1);
	// while (i < philo->data->number_of_philosophers)
	// {
	// 	wait(NULL);
	// 	i++;
	// }
}
