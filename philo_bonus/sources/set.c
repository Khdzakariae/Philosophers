#include <philo_bonus.h>


bool	cheaak_died(t_philo *philo)
{
	if (philo->data->philosopher_died == true)
	{
		return (false);
	}
	return (true);
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

