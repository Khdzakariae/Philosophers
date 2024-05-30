#include <philo_bonus.h>

void retine(t_philo *philo)
{
    sem_wait(philo->data->semaphore);
    thinking(philo);
    sleep(1);
    sem_post(philo->data->semaphore);
    exit(0);
}

t_philo  *initialize_philosophers(t_data *data)
{
    int i ;
    i = 0;
	t_philo *philo;
    philo = malloc((data->number_of_philosophers) * sizeof(t_philo));
    if (philo == NULL)
        return NULL;
    sem_unlink("/mysemaphore");
    data->semaphore = (sem_open("/mysemaphore", O_CREAT, 0644, 1));
    while (i < data->number_of_philosophers)
    {
        philo[i].id = i;
		philo[i].cont = 0;
		philo[i].data = data;
		philo[i].time_to_last_eat = 0;
        i++;
    }
    return(philo);   
}


void  start_simulation(t_data *data, t_philo *philo)
{
    int i = 0;
    int pid = 0;
	start_time(true);
	data->start_time = the_time();
    while (i < data->number_of_philosophers)
    {
        philo[i].pid = fork();
        if (philo[i].pid == 0)
            retine(&philo[i]);
        else
            i++;
    }
    for (int j = 0; j <  data->number_of_philosophers; j++)
        wait(NULL);
}