#include "philo.h"


void join_threads(t_data *data, t_philo *philos) 
{
    (void)*data;
    for (int i = 0; i < philos->data->number_of_philosophers  ; i++) 
    {
        // puts("======= bata =======");
        pthread_join(philos[i].thread_philo, NULL);
        // puts("======= allo =======");


    }
}

int main(int argc, char **argv) 
{

    t_data data;
    t_forks *forks;
    t_philo *philo;
    data.philosopher_died = false;
    if (check_arguments(argc, argv, &data) != 0)
        return 1;
    forks = initialize_forks(data.number_of_philosophers);
    if (forks == NULL)
        return 1;
    // pthread_mutex_init(&data._died, NULL);
    philo = initialize_philosophers(&data, forks);
    start_simulation(&data, philo);
    if  (monitoring(philo)== false) 
    {
        if (data.number_of_philosophers != 1)
            join_threads(&data, philo);
        // pthread_join(philos.thread_philo, NULL);
        
        cleanup(philo, forks, data.number_of_philosophers);
        return 1;
    }


    cleanup(philo, forks, data.number_of_philosophers);
    return(0);
}