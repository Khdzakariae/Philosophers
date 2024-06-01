/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofeers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:23:43 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/01 11:14:01 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_philo *philo, t_forks *forks, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_destroy(forks[i].forks);
		free(forks[i].forks);
		i++;
	}
	free(philo);
	free(forks);
}

void	print_msg(int flag, t_philo *philo, bool flage)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = the_time();
	if (flage == false)
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		printf("%lld\t%ld died\n", time, philo->id + 1);
		return ;
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
	pthread_mutex_unlock(&philo->data->print_mutex);
}

t_forks	*initialize_forks(int number_of_philosophers)
{
	int		i;
	t_forks	*forks;

	i = 0;
	forks = malloc((number_of_philosophers) * sizeof(t_forks));
	if (forks == NULL)
		return (NULL);
	while (i < number_of_philosophers)
	{
		forks[i].forks = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(forks[i].forks, NULL);
		i++;
	}
	return (forks);
}

t_philo	*initialize_philosophers(t_philo *philos, t_data *data, t_forks *forks)
{
	int	i;
	int	nmbr;

	i = 0;
	philos = malloc((data->number_of_philosophers) * sizeof(t_philo));
	if (philos == NULL)
		return (NULL);
	pthread_mutex_init(&data->cont_mutix, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->_died, NULL);
	pthread_mutex_init(&data->last_eat_mutix, NULL);
	nmbr = data->number_of_philosophers;
	while (i < data->number_of_philosophers)
	{
		philos[i].id = i;
		philos[i].cont = 0;
		philos[i].data = data;
		philos[i].time_to_last_eat = 0;
		if (philos->id % 2)
		{
			philos[i].first_fork = &forks[(i + 1) % nmbr];
			philos[i].second_fork = &forks[i];
		}
		else
		{
			philos[i].first_fork = &forks[i];
			philos[i].second_fork = &forks[(i + 1) % nmbr];
		}
		
		i++;
	}
	return (philos);
}
