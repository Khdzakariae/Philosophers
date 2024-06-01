#include "philo.h"

void	set_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->_died);
	philo->data->philosopher_died = true;
	pthread_mutex_unlock(&philo->data->_died);
}

bool	cheaak_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->_died);
	if (philo->data->philosopher_died == true)
	{
		pthread_mutex_unlock(&philo->data->_died);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->_died);
	return (true);
}

void set_cont(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->cont_mutix);
	philo->cont++;
	pthread_mutex_unlock(&philo->data->cont_mutix);
}

bool cheack_cont(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->cont_mutix);
	if (philo->cont > philo->data->must_eat + 1)
	{
		pthread_mutex_unlock(&philo->data->cont_mutix);
		return(false);
	}
	pthread_mutex_unlock(&philo->data->cont_mutix);
	return(true);
}

void	set_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->_hbsso_l9lawi);
	philo->time_to_last_eat = the_time();
	pthread_mutex_unlock(&philo->data->_hbsso_l9lawi);
}

bool	cheack_time_died(t_philo *philos, int i)
{
	pthread_mutex_lock(&philos->data->_hbsso_l9lawi);
	long current_time = the_time();
	long dure = current_time - philos->time_to_last_eat;
	// sleep(10);
	if (dure > philos->data->time_to_die)
	{
		pthread_mutex_unlock(&philos->data->_hbsso_l9lawi);
		return (false);
	}
	pthread_mutex_unlock(&philos->data->_hbsso_l9lawi);
	return (true);
}