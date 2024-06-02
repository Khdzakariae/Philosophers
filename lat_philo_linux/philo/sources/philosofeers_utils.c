/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofeers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:08:54 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/02 19:03:24 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleanup_forks(t_forks *forks, int j)
{
	int i = 0;
	while (i < j)
	{
		pthread_mutex_destroy(forks[i].forks);
		free(forks[i].forks);
		i++;
	}
	free(forks);
}

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
	// pthread_mutex_destroy(&philo->data->cont_mutix);
	// pthread_mutex_destroy(&philo->data->print_mutex);
	// pthread_mutex_destroy(&philo->data->_died);
	// pthread_mutex_destroy(&philo->data->set_time_mutix);

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
				printf("%lld\t%ld has taken a fork\n", time, philo->id +1);
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
		return(NULL);
	while (i < number_of_philosophers)
	{
		forks[i].forks = malloc(sizeof(pthread_mutex_t));
		if (forks[i].forks == NULL)
		{
			cleanup_forks(forks, i);
			return(NULL);
		}
		pthread_mutex_init(forks[i].forks, NULL);
		i++;
	}
	return (forks);
}

t_philo	*initialize_philosophers(t_data *data, t_forks *forks)
{
	t_philo *philos ;
	int nbr;
	int i ;

	i = 0;
	philos = malloc((data->number_of_philosophers) * sizeof(t_philo));

	pthread_mutex_init(&data->cont_mutix, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->_died, NULL);
	pthread_mutex_init(&data->set_time_mutix, NULL);
	nbr = data->number_of_philosophers;

	while (i < data->number_of_philosophers)
	{
		philos[i].id = i;
		philos[i].cont = 0;
		philos[i].data = data;
		philos[i].time_to_last_eat = 0;
		philos[i].first_fork = &forks[(i + 1) % nbr];
		philos[i].second_fork = &forks[i];
		i++;
	}
	return (philos);
}