/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopuers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:41:56 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/29 12:19:36 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	main_monitor(t_philo *philo)
{
	while (1)
	{
		if (philo->data->chbaa3->__align == 0)
		{
			arrete(philo);
			exit(0);
			break ;
		}
		if (philo->data->maaat->__align == 0)
		{
			break ;
		}
	}
}

void	arrete(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	sem_close(philo->data->forks_semaphore);
	sem_close(philo->data->cont_semaphore);
	sem_close(philo->data->semaphore_print);
	sem_close(philo->data->semaphore_died);
	sem_close(philo->data->protect_last_eat);
	sem_close(philo->data->maaat);
	sem_close(philo->data->chbaa3);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (check_arguments(argc, argv, &data) != 0)
		return (1);
	philo = initialize_philosophers(&data);
	if (philo == NULL)
		return (1);
	start_simulation(&data, philo);
	main_monitor(philo);
	arrete(philo);
	exit(1);
	return (0);
}
