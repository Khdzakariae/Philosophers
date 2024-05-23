/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:41:23 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/23 15:13:38 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


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


void print_msg(int flag, t_philo *philo, bool flage) 
{
    pthread_mutex_lock(&philo->data->print_mutex);
    long long time = the_time() - philo->data->start_time;
    if (philo->data->philosopher_died == true) {
        printf("%lld\t%ld died\n", time, philo->id + 1);
        pthread_mutex_unlock(&philo->data->print_mutex);
        return;
    }
    if (flag == 0)
        printf("%lld\t%ld has taken a fork\n", time, philo->id + 1);
    else if (flag == 1)
        printf("%lld\t%ld is sleeping\n", time, philo->id + 1);
    else if (flag == 2)
        printf("%lld\t%ld is thinking\n", time, philo->id + 1);
    else if (flag == 4)
        printf("%lld\t%ld is eating\n", time, philo->id + 1);
    pthread_mutex_unlock(&philo->data->print_mutex);

}



void ft_usleep(long time, t_data *data)
{
    long current_time = the_time();
    while (1)
    {
        if ((the_time() - current_time) >= time)
            break;
        usleep(10);
    }
}
void sleping(t_philo *philo)
{
    print_msg(1, philo, true);
    ft_usleep(philo->data->time_to_sleep, philo->data);
}

void thinking(t_philo *philo)
{
	print_msg(2, philo, true);
}

