#include <philo_bonus.h>

void arrete(t_philo *philo)
{
	int i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	
}

void	set_time(t_philo *philo)
{
	philo->time_to_last_eat = the_time();
}

bool	cheack_time_died(t_philo *philos, int i)
{

	long current_time = the_time();
	long dure = current_time - philos->time_to_last_eat;
	if (dure > philos->data->time_to_die)
		return (false);
	return (true);
}

void	set_philo_died(t_philo *philo)
{
	philo->data->philosopher_died = true;
}

bool	monitoring(t_philo *philos , int ac)
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
				arrete(philos);
				print_msg(3, &philos[i], false);
				exit(1);
			}
			i++;
		}
	}
	return (true);
}