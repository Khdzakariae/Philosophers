#include "philo.h"

bool	monitoring(t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philos->data->number_of_philosophers)
		{
			if (cheack_time_died(philos, i) == false)
			{
				set_philo_died(philos);
				print_msg(3, &philos[i], false);
				return (false);
			}
			i++;
		}
	}
	return (true);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		if (cheaak_died(philo) == false)
			break ;
		thinking(philo);
		pthread_mutex_lock(philo->first_fork->forks);
		print_msg(0, philo, true);
		pthread_mutex_lock(philo->second_fork->forks);
		print_msg(0, philo, true);
		print_msg(4, philo, true);
		set_time(philo, i);
		pthread_mutex_unlock(philo->second_fork->forks);
		pthread_mutex_unlock(philo->first_fork->forks);
		sleping(philo);
		i++;
	}
	return (NULL);
}

void	start_simulation(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	start_time(true);
	data->start_time = the_time();
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philos[i].thread_philo, NULL, philosophers, &philos[i]);
		i++;
	}
}
