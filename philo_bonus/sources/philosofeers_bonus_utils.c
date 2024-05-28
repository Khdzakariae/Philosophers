#include <philo_bonus.h>


t_philo  *initialize_philosophers(t_data *data)
{
    int i ;
    i = 0;
	t_philo *philo;
    philo = malloc((data->number_of_philosophers) * sizeof(t_philo));
    if (philo == NULL)
        return NULL;
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
