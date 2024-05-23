/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/23 21:15:52 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool cheaak_died(t_philo *philo)
{
    pthread_mutex_lock(philo->data->_died);
    if (philo->data->philosopher_died == true)
    {
        pthread_mutex_unlock(philo->data->_died);
        return(true);
    }
    pthread_mutex_unlock(philo->data->_died);
    return(false);
}

int check_arguments(int argc, char **argv, t_data *data) 
{
    if (argc != 5) 
    {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", argv[0]);
        return 1;
    }
    if (!cheack(data, argv)) 
    {
        printf("ERROR\n");
        return 1;
    }
    return 0;
}

t_fork* initialize_forks(int number_of_philosophers) 
{
    int i = 0;
    t_fork *forks = malloc((number_of_philosophers - 1) * sizeof(t_fork));
    if (forks == NULL) 
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    while (i < number_of_philosophers) 
    {
        forks[i].id = i;
        forks[i].forks = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(forks[i].forks, NULL);
        i++;
    }
    return forks;
}

t_philo* initialize_philosophers(t_data *data, t_fork *forks) 
{
    int i = 0;
    t_philo *philos = malloc(data->number_of_philosophers * sizeof(t_philo));
    if (philos == NULL) 
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    data->print_mutex =  malloc(sizeof(pthread_mutex_t));
    data->_died =  malloc(sizeof(pthread_mutex_t));
    
    pthread_mutex_init(data->print_mutex, NULL);
    pthread_mutex_init(data->_died, NULL);

    data->mat = 0;
    while (i < data->number_of_philosophers)
    {
        philos[i].id = i;
        philos[i].data = data;
        philos[i].time_to_last_eat = 0;
        philos[i].data->philosopher_died = false;
  
        philos[i].time_mutex = malloc(sizeof(pthread_mutex_t));

        
        pthread_mutex_init(philos[i].time_mutex, NULL);
        
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

bool monitoring(t_philo *philos) 
{
    int i;
    while (1) 
    {
        i = 0;
        while (i < philos->data->number_of_philosophers) 
        {
            long current_time = the_time();

            pthread_mutex_lock(philos[i].time_mutex);
            if (philos->data->time_to_die < current_time - philos[i].time_to_last_eat) 
            {
                pthread_mutex_unlock(philos[i].time_mutex);

                
                pthread_mutex_lock(philos[i].data->_died);
                philos[i].data->philosopher_died = true;
                pthread_mutex_unlock(philos[i].data->_died);
   
                print_msg(3, &philos[i], false);

                puts("last place!");
                return false;
            }

            pthread_mutex_unlock(philos[i].time_mutex);

            i++;
        }
    }
    return true;
}


void *philosophers(void *arg) 
{
    pthread_mutex_t *print_mutex;
    t_philo *philo = (t_philo *)arg;

    
    if (philo->id % 2) {
        usleep(100);
    }
    
    while (1) 
    {
        // if (cheaak_died(philo) == false)
        //     return NULL;
        // if (cheaak_died(philo) == false)
        
        
        pthread_mutex_lock(philo->data->_died);
        if (philo->data->philosopher_died == true)
        {
            pthread_mutex_unlock(philo->data->_died);
            fprintf(stderr, "threads %lu done by success", philo->id);
            return NULL;
        }
        pthread_mutex_unlock(philo->data->_died);
        
        
        thinking(philo);
        pthread_mutex_lock(philo->first_fork->forks);
        if (cheaak_died(philo) == false)
            print_msg(0, philo, true);
        pthread_mutex_lock(philo->second_fork->forks);
        if (cheaak_died(philo) == false)
            print_msg(0, philo, true);
        if (cheaak_died(philo) == false)
            print_msg(4, philo, true);
        ft_usleep(philo->data->time_to_eat, philo->data);
        pthread_mutex_lock(philo->time_mutex);
        philo->time_to_last_eat = the_time();
        pthread_mutex_unlock(philo->time_mutex);
        
        pthread_mutex_unlock(philo->second_fork->forks);
        pthread_mutex_unlock(philo->first_fork->forks);
        sleping(philo);
 
    }
    return NULL;
}


bool start_simulation(t_data *data, t_philo *philos) 
{
    int i =0;
    start_time(true);
    data->start_time = the_time();

    while (i < data->number_of_philosophers) 
    {
        pthread_create(&philos[i].thread_philo, NULL, philosophers, &philos[i]);
        i++;
    }
    
    if (monitoring(philos) == false) {
        return false;
    }

    return true;
}



void cleanup(t_fork *forks, t_philo *philos, int number_of_philosophers) 
{
    int i = 0;

    while (i < number_of_philosophers) 
    {
        pthread_mutex_destroy(forks[i].forks);
        pthread_mutex_destroy(philos[i].time_mutex);
        free(philos[i].time_mutex);
        i++;
    }
    pthread_mutex_destroy(philos->data->_died);
    pthread_mutex_destroy(philos->data->print_mutex);

    

    free(forks);
    free(philos);
}


int main(int argc, char **argv) 
{
    t_data data;
    t_fork *forks;
    t_philo *philos;

    if (check_arguments(argc, argv, &data) != 0)
        return 1;

    forks = initialize_forks(data.number_of_philosophers);
    if (forks == NULL)
        return 1;
    philos = initialize_philosophers(&data, forks);
    if (philos == NULL) {
        free(forks);
        return 1;
    }
    if (start_simulation(&data, philos) == false) 
    {

        usleep(200);
        puts("naa hna");     
        return 1;
    }
    return 0;
}

