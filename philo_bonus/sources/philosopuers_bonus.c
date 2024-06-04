
#include <philo_bonus.h>

void arrete(t_philo *philo)
{
	int i = 0;
	while (i < philo->data->number_of_philosophers)
	{
        pthread_join(philo[i].thread_philo, NULL);
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	free(philo);
}

int main (int argc , char **argv)
{
    t_data data;
    t_philo *philo;


	if (check_arguments(argc, argv, &data) != 0)
		return (1);
    philo = initialize_philosophers(&data);
    if (philo == NULL)
        return(1);
    start_simulation(&data, philo);

    while (1)
    {
        int status = waitpid(-1, &status ,0);
        if (status == -1)
            {
	            free(philo);
                exit(22);
            }
            else {
                arrete(philo);
                exit(1);
            }
    }
}




