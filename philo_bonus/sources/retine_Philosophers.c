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
	long	current_time;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->protect_last_eat);
		current_time = the_time();
		if ((current_time - philo->time_to_last_eat) > philo->data->time_to_die)
		{
			philo->data->philosopher_died = true;
			print_msg(3, philo, false);
			sem_post(philo->data->protect_last_eat);
			arrete(philo);
			exit(1);
		}
		sem_post(philo->data->protect_last_eat);
		if (philo->data->arg == 6)
		{
			sem_wait(philo->data->protect_count);
			if ((philo->cont) >= (philo->data->must_eat - 1))
			{
				sem_post(philo->data->protect_count);
				exit(0);
			}
			sem_post(philo->data->protect_count);
		}
	}
}

void	retine(t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		thinking(philo);
		sem_wait(philo->data->semaphore);
		print_msg(0, philo, true);
		sem_wait(philo->data->semaphore);
		print_msg(0, philo, true);
		sem_wait(philo->data->protect_last_eat);
		philo->time_to_last_eat = the_time(); // protect
		sem_post(philo->data->protect_last_eat); 
		print_msg(4, philo, true);
		sem_wait(philo->data->protect_count);
		philo->cont++; // protect 
		sem_post(philo->data->protect_count);
		ft_usleep(philo->data->time_to_eat);
		sem_post(philo->data->semaphore);
		sem_post(philo->data->semaphore);
		print_msg(1, philo, true);


		ft_usleep(philo->data->time_to_sleep);
		usleep(300);
	}
}

void	start_simulation(t_data *data, t_philo *philo)
{
	int i = 0;
	// pid_t child;
	start_time(true);
	while (i < data->number_of_philosophers)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			pthread_create(&philo[i].thread_philo, NULL, monitoring, &philo[i]);
			retine(&philo[i]);
			pthread_join(philo[i].thread_philo, NULL);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		wait(NULL);
		i++;
	}
	
}