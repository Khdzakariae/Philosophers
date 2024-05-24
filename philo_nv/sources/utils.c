#include "philo.h"

long 	start_time(bool init)
{
	static long	start = 0;

	if (init)
		start = the_time();
	return (start);
}

long	the_time(void)
{
	struct timeval	time;
	long			start;

	start = start_time(false);
	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000) - start);
}

void ft_usleep(long time)
{
    long current_time = the_time();
    while (1)
    {
        if ((the_time() - current_time) >= time)
            break;
        usleep(10 * 1000);
    }
}

void sleping(t_philo *philo)
{
    print_msg(1, philo, true);
    ft_usleep(philo->data->time_to_sleep);
}

void thinking(t_philo *philo)
{
	print_msg(2, philo, true);
}

