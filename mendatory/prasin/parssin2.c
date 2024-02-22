#include "../so_long.h"

size_t	count_map_colone(char **map)
{
	int	i;
	int	max_len;

	if (!map)
		return (0);
	i = 0;
	max_len = ft_strlen(*map);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(*map);
		i++;
	}
	return (max_len);
}

size_t	count_map_line(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	ft_position_player(char **map, int *x, int *y)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	size_t	smp;

	i = 0;
	smp = count_map_colone(map);
	tmp = count_map_line(map);
	while (i < tmp)
	{
		j = 0;
		while (j < smp)
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

size_t	ft_check_collective(char **map)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	size_t	smp;

	i = 0;
	smp = count_map_colone(map);
	tmp = count_map_line(map);
	while (i < tmp)
	{
		j = 0;
		while (j < smp)
		{
			if (map[i][j] == 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

size_t	ft_check_collective1(char **map)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	tmp = 0;
	i = 0;
	while (i < count_map_line(map) && map[i])
	{
		j = 0;
		while (j < (count_map_colone(map)) && map[i][j])
		{
			if (map[i][j] == 'C')
			{
				tmp++;
			}
			j++;
		}
		i++;
	}
	return (tmp);
}
