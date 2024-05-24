#include "philo.h"

bool cheaak_died(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->_died);
    if (philo->data->philosopher_died == true)
    {
        pthread_mutex_unlock(&philo->data->_died);
        return(false);
    }
    pthread_mutex_unlock(&philo->data->_died);
    return(true);
}

bool monitoring(t_philo *philos) 
{
    int i;

    while (1) 
    {
        i = 0;
        if (cheaak_died(philos) == true)
                return(false);
        while (i < philos->data->number_of_philosophers) 
        {
            pthread_mutex_lock(&philos[i].time_mutex);
            long current_time = the_time();

            if (philos->data->time_to_die < current_time - philos[i].time_to_last_eat) 
            {
                pthread_mutex_unlock(&philos[i].time_mutex);
                pthread_mutex_lock(&philos->data->_died);
                philos->data->philosopher_died = true;
                pthread_mutex_unlock(&philos->data->_died);
                print_msg(3, &philos[i], false);
                return false;
            }
            pthread_mutex_unlock(&philos[i].time_mutex);
            i++;
        }
    }
    return true;
}
void *philosophers(void *arg) 
{
    t_philo *philo = (t_philo *)arg;
    int i ;
    while (1) 
    { 
        i = 0;
        while (i < philo->data->number_of_philosophers)
        {
            thinking(philo);
            pthread_mutex_lock(philo->first_fork->forks);
            print_msg(0, philo, true);
            pthread_mutex_lock(philo->second_fork->forks);
            print_msg(0, philo, true);
            print_msg(4, philo, true);
            ft_usleep(philo->data->time_to_eat);
            pthread_mutex_lock(&philo[i].time_mutex);
            philo[i].time_to_last_eat = the_time();
            pthread_mutex_lock(&philo[i].time_mutex);
            pthread_mutex_unlock(philo->second_fork->forks);
            pthread_mutex_unlock(philo->first_fork->forks);
            sleping(philo);
            i++;
        }         

    }
    return NULL;
}

void  start_simulation(t_data *data, t_philo *philos)
{
    int i = 0;
    start_time(true);
    data->start_time = the_time();

    while (i < data->number_of_philosophers) 
    {
        pthread_create(&philos[i].thread_philo, NULL, philosophers, &philos[i]);
        pthread_detach(philos[i].thread_philo);
        i++;
    }
}

