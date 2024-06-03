#include <philo_bonus.h>



void	set_time(t_philo *philo)
{
	// puts("------------------ ENTRER ----------------------------");
	philo->time_to_last_eat = the_time();
	// printf("philo id is : %ld\n", philo->id);
	// printf("----------philo lat eat  is : %ld--------\n", philo->time_to_last_eat);
	// puts("-------------------- SORTIR --------------------------");

}

bool	cheack_time_died(t_philo *philos, int i)
{

	long current_time = the_time();
	long dure = current_time - philos->time_to_last_eat;

	if (dure > philos->data->time_to_die)
		return (false);
	return (true);
}

void	set_philo_died(t_philo *philo)
{
	philo->data->philosopher_died = true;
}

bool monitoring(t_philo *philos, int ac)
{
    int i;
    bool all_alive = true;

    while (all_alive)
    {
        i = 0;
        while (i < philos->data->number_of_philosophers)
        {
            if (!cheack_time_died(&philos[i], i))
            {
                arrete(philos);
                all_alive = false; 
                break;
            }
            i++;
        }
    }
    return (true);
}