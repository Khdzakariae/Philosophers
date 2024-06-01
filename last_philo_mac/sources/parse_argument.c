/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:23:34 by zel-khad          #+#    #+#             */
/*   Updated: 2024/06/01 10:24:29 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	generating_number(char **str, long *result)
{
	while (*(*str) && ft_isdigit(*(*str)))
	{
		if ((*result * 10) >= INT_MAX)
			return ((void)(*result = 55147483647));
		*result = *result * 10 + (*(*str) - '0');
		(*str)++;
	}
}

long	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[i])
		return (55147483647);
	else if (((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0'))
		return (55147483647);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		return (55147483647);
	else if (str[i] == '+')
		i++;
	str += i;
	generating_number(&str, &result);
	if (*str)
		return (55147483647);
	return (result * sign);
}

bool	cheack(t_data *data, char **av, int argc)
{
	data->number_of_philosophers = ft_atoi(av[1]);
	if (data->number_of_philosophers <= 0)
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
	if (argc == 6)
	{
		data->must_eat = ft_atoi(av[5]);
		if (data->must_eat > INT_MAX)
			return (false);
	}
	data->time_to_died = 0;
	data->philosopher_died = false;
	return (true);
}

int	check_arguments(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		if (!cheack(data, argv, argc))
		{
			printf("ERROR\n");
			return (1);
		}
	}
	else
	{
		printf("Usage:%s \n", argv[0]);
		return (1);
	}
	return (0);
}
