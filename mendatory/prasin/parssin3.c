
#include "../so_long.h"

size_t	ft_check_sortie(char **map)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	size_t	smp;
	size_t	stmp;

	tmp = count_map_line(map);
	smp = count_map_colone(map);
	i = 0;
	stmp = 0;
	while (i < tmp)
	{
		j = 0;
		while (j < smp)
		{
			if (map[i][j] == 'E')
			{
				stmp++;
			}
			j++;
		}
		i++;
	}
	return (stmp);
}

size_t	ft_check_player(char **map)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	size_t	smp;
	size_t	stmp;

	tmp = count_map_line(map);
	smp = count_map_colone(map);
	i = 0;
	stmp = 0;
	while (i < tmp)
	{
		j = 0;
		while (j < smp)
		{
			if (map[i][j] == 'P')
			{
				stmp++;
			}
			j++;
		}
		i++;
	}
	return (stmp);
}

int	cheack_map(char **map)
{
	if (ft_check_collective1(map) != 0 || ft_check_player(map) != 0
		|| ft_check_sortie(map) != 0)
		return (0);
	return (1);
}

int	cheack_colone_map(char **map)
{
	size_t	i;
	size_t	tmp;
	size_t	smp;

	tmp = count_map_line(map);
	smp = count_map_colone(map);
	i = 0;
	while (i < tmp)
	{
		if (ft_strlen(map[i]) != smp)
			return (0);
		i++;
	}
	return (1);
}