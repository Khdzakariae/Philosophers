/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:42:05 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/04 18:42:37 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

long	start_time(bool init)
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

void	ft_usleep(long time)
{
	long	current_time;

	current_time = the_time();
	while (1)
	{
		if ((the_time() - current_time) >= time)
			break ;
		usleep(70);
	}
}

void	sleping(t_philo *philo)
{
	print_msg(1, philo, true);
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_msg(2, philo, true);
}
