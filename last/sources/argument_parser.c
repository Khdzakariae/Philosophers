/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:54:27 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/14 11:55:55 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	cheack(t_data *data, char **av)
{
	data->number_of_philosophers = ft_atoi(av[1]);
	if (data->number_of_philosophers > INT_MAX)
		return (false);
	data->time_to_die = ft_atoi(av[2]);
	if (data->time_to_die > INT_MAX || data->time_to_die < 60)
		return (false);
	data->time_to_eat = ft_atoi(av[3]);
	if (data->time_to_eat > INT_MAX || data->time_to_eat < 60)
		return (false);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_sleep > INT_MAX || data->time_to_sleep < 60)
		return (false);
	return (true);
}
