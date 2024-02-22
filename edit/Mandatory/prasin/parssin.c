/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:11:20 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/11 18:12:49 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_wall1(char **map)
{
	size_t	i;
	size_t	smp;

	i = 0;
	smp = count_map_colone(map);
	while (i < smp)
	{
		if (map[0][i] != '1')
		{
			return (0);
		}
		else if (!map[0][i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_wall2(char **map)
{
	size_t	i;
	size_t	tmp;

	tmp = count_map_line(map);
	i = 0;
	while (map[tmp - 1][i])
	{
		if (map[tmp - 1][i] != '1')
			return (0);
		else if (!map[tmp - 1][i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_wall3(char **map)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = count_map_line(map);
	while (i < tmp)
	{
		if (map[i][0] != '1')
			return (0);
		else if (!map[i][0])
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_wall4(char **map)
{
	size_t	i;
	size_t	tmp;
	size_t	smp;

	i = 0;
	smp = count_map_colone(map);
	tmp = count_map_line(map);
	while (i < tmp)
	{
		if (map[i][smp - 1] != '1')
			return (0);
		else if (!map[i][smp - 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	cheack_parssin_sortie(char **map, size_t tmp, size_t smp)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < tmp)
	{
		j = 0;
		while (j < smp)
		{
			if (map[i][j] == 'R')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
