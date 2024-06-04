#include <philo_bonus.h>

void *monitoring(void *arg)
{
    t_philo	*philo;
    long dure;
    long current_time;

	philo = (t_philo *)arg;

    while (1)
    {
        current_time = the_time();
	    dure = current_time - philo->time_to_last_eat;
        if (philo->data->arg == 6)
		{
			if (philo->cont > philo->data->must_eat)
				exit(-1);
		}
        if (dure > philo->data->time_to_die)
        {
            set_philo_died(philo);
            print_msg(3, philo, false);
            exit(1);
        }
        usleep(300);
    }
}

void retine(t_philo *philo)
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
        print_msg(4, philo, true);
        philo->cont++;
        philo->time_to_last_eat = the_time();
        ft_usleep(philo->data->time_to_eat);    
        sem_post(philo->data->semaphore);
        sem_post(philo->data->semaphore);
        print_msg(1, philo, true);
	    ft_usleep(philo->data->time_to_sleep);
        usleep(300);
    }
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
    sem_unlink("/mysemaphore1");
    data->semaphore = (sem_open("/mysemaphore", O_CREAT, 0644, data->number_of_philosophers));
    data->semaphore1 = (sem_open("/mysemaphore1", O_CREAT, 0644, 1));

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


void start_simulation(t_data *data, t_philo *philo)
{
    int i = 0;

    start_time(true);
    while (i < data->number_of_philosophers)
    {

        philo[i].pid = fork();
        if (philo[i].pid == 0)
        {
		    pthread_create(&philo[i].thread_philo, NULL, monitoring, &philo[i]);
            retine(&philo[i]);
            exit(0);
        }
        else
            i++;
    }
}