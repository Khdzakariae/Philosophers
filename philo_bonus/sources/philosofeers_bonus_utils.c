#include <philo_bonus.h>



void	arrete(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
}

void	print_msg(int flag, t_philo *philo, bool flage)
{
	long long	time;

	sem_wait(philo->data->semaphore1);
	time = the_time();
	if (flage == false)
	{
		printf("%lld\t%ld died\n", time, philo->id + 1);
		return ;
	}
	else
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
	sem_post(philo->data->semaphore1);
}

t_philo	*initialize_philosophers(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc((data->number_of_philosophers) * sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	sem_unlink("/mysemaphore");
	sem_unlink("/mysemaphore1");
	data->semaphore = (sem_open("/mysemaphore", O_CREAT, 0644,
				data->number_of_philosophers));
	data->semaphore1 = (sem_open("/mysemaphore1", O_CREAT, 0644, 1));
	while (i < data->number_of_philosophers)
	{
		philo[i].id = i;
		philo[i].cont = 0;
		philo[i].data = data;
		philo[i].time_to_last_eat = 0;
		i++;
	}
	return (philo);
}
