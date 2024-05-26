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
	// cheack is fail allocation
	while (i < number_of_philosophers)
	{
		forks[i].forks = malloc(sizeof(pthread_mutex_t));
		// cheack is fail allocation
		pthread_mutex_init(forks[i].forks, NULL);
		i++;
	}
	return (forks);
}

t_philo	*initialize_philosophers(t_data *data, t_forks *forks)
{
	int i = 0;
	t_philo *philos = malloc((data->number_of_philosophers) * sizeof(t_philo));
	data->print_mutex = *(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->_died, NULL);
	pthread_mutex_init(&data->_hbsso_l9lawi, NULL);

	while (i < data->number_of_philosophers)
	{
		philos[i].id = i;
		philos[i].data = data;
		philos[i].time_to_last_eat = 0;

		pthread_mutex_init(&philos[i].time_mutex, NULL);
		if (i == 0)
		{
			philos[i].first_fork = &forks[0];
			philos[i].second_fork = &forks[data->number_of_philosophers - 1];
		}
		else if (i % 2)
		{
			philos[i].first_fork = &forks[i - 1];
			philos[i].second_fork = &forks[i];
		}
		else
		{
			philos[i].first_fork = &forks[i];
			philos[i].second_fork = &forks[i - 1];
		}
		i++;
	}
	return (philos);
}