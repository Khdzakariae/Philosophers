
#include <philo_bonus.h>

int main (int argc , char **argv)
{
    t_data data;
    t_philo *philo;


	if (check_arguments(argc, argv, &data) != 0)
		return (1);
    philo = initialize_philosophers(&data);
    start_simulation(&data, philo);
    if (philo == NULL)
        return(1);
}




