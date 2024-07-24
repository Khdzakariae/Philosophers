/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopuers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:41:56 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/24 19:38:41 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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
	
	while (1) {

	int status;
	int ret = waitpid(-1, &status, 0);
	if (ret == -1) 
		{
		
    sem_close(philo->data->forks_semaphore);
    sem_close(philo->data->cont_semaphore);
    sem_close(philo->data->semaphore_print);
    sem_close(philo->data->semaphore_died);
    sem_close(philo->data->protect_last_eat);
				free(philo);
			exit(122);
		}

    	// if (WIFEXITED(status)) {
		if (WEXITSTATUS(status) == 0) {
				continue;
		} 
		else if (WEXITSTATUS(status) != 0) {
				arrete(philo);
				print_msg(3, &philo[WEXITSTATUS(status)  - 1], false);

	    sem_close(philo->data->forks_semaphore);
    sem_close(philo->data->cont_semaphore);
    sem_close(philo->data->semaphore_print);
    sem_close(philo->data->semaphore_died);
    sem_close(philo->data->protect_last_eat);
				free(philo);

				// exit(10);
		}
	}
	
}
