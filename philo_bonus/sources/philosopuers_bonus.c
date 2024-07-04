/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopuers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:41:56 by zel-khad          #+#    #+#             */
/*   Updated: 2024/07/04 18:41:57 by zel-khad         ###   ########.fr       */
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
}
