/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofeers_bonus_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:41:50 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/29 11:49:49 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	print_msg(int flag, t_philo *philo, bool flage)
{
	long long	time;

	sem_wait(philo->data->semaphore_print);
	time = the_time();
	if (flage == false)
	{
		printf("%lld\t%ld died\n", time, philo->id + 1);
		sem_post(philo->data->semaphore_print);
		return;
	}
	if (flage == true)
	{
		if (cheaak_died(philo) == true)
		{
			if (flag == 0)
				printf("%lld\t%ld has taken a fork\n", time, philo->id + 1);
			else if (flag == 1)
				printf("%lld\t%ld is sleeping\n", time, philo->id + 1);
			else if (flag == 2)
				printf("%lld\t%ld is thinking\n", time, philo->id + 1);
			else if (flag == 4)
				printf("%lld\t%ld is eating\n", time, philo->id + 1);
		}
	}
	sem_post(philo->data->semaphore_print);
}

t_philo	*initialize_philosophers(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc((data->number_of_philosophers) * sizeof(t_philo));
	sem_unlink("/forks_semaphore");
	sem_unlink("/cont_semaphore");
	sem_unlink("/semaphore_print");
	sem_unlink("/semaphore_died");
	sem_unlink("/protect_last_eat");
	sem_unlink("/maaat");
	data->forks_semaphore = (sem_open("/forks_semaphore", O_CREAT, 0644,
				data->number_of_philosophers));
	data->cont_semaphore = (sem_open("/cont_semaphore", O_CREAT, 0644, 1));
	data->semaphore_print = (sem_open("/semaphore_print", O_CREAT, 0644, 1));
	data->semaphore_died = (sem_open("/semaphore_died", O_CREAT, 0644, 1));
	data->protect_last_eat = (sem_open("/protect_last_eat", O_CREAT, 0644, 1));
	data->maaat = (sem_open("/maaat", O_CREAT, 0644, 1));
	data->philosopher_died = false;
	data->cont = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].id = i;
		philo[i].data = data;
		philo[i].time_to_last_eat = 0;
		i++;
	}
	return (philo);
}
