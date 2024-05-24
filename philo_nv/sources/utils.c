#include "philo.h"

t_forks* initialize_forks(int number_of_philosophers)
{
    int i = 0;

    t_forks *forks = malloc((number_of_philosophers )* sizeof(t_forks));
    //cheack is fail allocation
    while (i < number_of_philosophers) 
    {

        forks[i].forks = malloc(sizeof(pthread_mutex_t));
        //cheack is fail allocation
        pthread_mutex_init(forks[i].forks, NULL);
        i++;
    }
    return forks;
}

t_philo* initialize_philosophers(t_data *data, t_forks *forks)
{
    int i = 0;
    t_philo *philos = malloc((data->number_of_philosophers - 1)* sizeof(t_philo));

    while (i < data->number_of_philosophers)
    {
        philos[i].id = i;
        philos[i].data = data;
        
        if (i == 0) 
        {
            philos[i].first_fork = &forks[0];
            philos[i].second_fork = &forks[data->number_of_philosophers - 1];
        } 
        else if (i % 2) 
        {
            philos[i].first_fork = &forks[i - 1];
            philos[i].second_fork = &forks[i];
        } 
        else 
        {
            philos[i].first_fork = &forks[i];
            philos[i].second_fork = &forks[i - 1];
        }
        i++;
    }
    return philos;
}

void cleanup(t_philo *philo, t_forks *forks, int number_of_philosophers) 
{
    int i = 0;

    while (i < number_of_philosophers) 
    {
        pthread_mutex_destroy(forks[i].forks);
        free(forks[i].forks);
        i++;
    }
    free(philo);
    free(forks);
}