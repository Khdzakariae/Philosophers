/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:23:50 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/01 10:38:07 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->number_of_philosophers)
	{
		pthread_join(philos[i].thread_philo, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	t_forks	*forks;

	if (check_arguments(argc, argv, &data) != 0)
		return (1);
	forks = initialize_forks(data.number_of_philosophers);
	if (forks == NULL)
		return (1);
	philo = initialize_philosophers(philo, &data, forks);
	if (start_simulation(&data, philo) == false)
		return (1);
	if (monitoring(philo, argc) == false)
	{
		if (data.number_of_philosophers != 1)
			join_threads(&data, philo);
		cleanup(philo, forks, data.number_of_philosophers);
		return (1);
	}
	cleanup(philo, forks, data.number_of_philosophers);
	return (0);
}
