/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:09:00 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/29 21:27:11 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	start_simulation(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	start_time(true);
	data->start_time = the_time();
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philos[i].thread_philo, NULL, philosophers, &philos[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_forks	*forks;
	t_philo	*philo;

	if (check_arguments(argc, argv, &data) != 0)
		return (1);
	forks = initialize_forks(data.number_of_philosophers);
	if (forks == NULL)
		return (1);
	philo = initialize_philosophers(&data, forks);
	start_simulation(&data, philo);
	if (monitoring(philo, argc) == false)
	{
		join_threads(philo);
		cleanup(philo, forks, data.number_of_philosophers);
		return (1);
	}
	else
	{
		join_threads(philo);
		cleanup(philo, forks, data.number_of_philosophers);
		return (0);
	}
	return (0);
}
