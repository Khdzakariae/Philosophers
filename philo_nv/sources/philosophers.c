#include "philo.h"


int main(int argc, char **argv) 
{
    t_data data;
    t_forks *forks;
    t_philo *philo;
    if (check_arguments(argc, argv, &data) != 0)
        return 1;
    forks = initialize_forks(data.number_of_philosophers);
    if (forks == NULL)
        return 1;
    philo = initialize_philosophers(&data, forks);
    cleanup(philo, forks, data.number_of_philosophers);
    return(0);
}