#include <philo_bonus.h>


int main(int argc, char **argv)
{
    t_data data;

	if (check_arguments(argc, argv, &data) != 0)
		return (1);
    return(0);
}