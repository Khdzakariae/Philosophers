#include "../so_long.h"

int	autr_caracters(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count_map_line(map) && map[i])
	{
		j = 0;
		while (j < (ft_strlen(map[i])) && map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C'
				|| map[i][j] == 'E' || map[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	parssin_map(t_data *data, char **tmp_map)
{
	size_t	tmp;
	size_t	smp;

	smp = count_map_colone(data->tmp_map);
	tmp = count_map_line(data->tmp_map);
	flood_fill(tmp_map, data->player_x, data->player_y);
	if (cheack_map(tmp_map) == 0 || cheack_parssin_sortie(tmp_map, tmp,
			smp) != 0 || cheack_colone_map(data->map) == 0)
	{
		write(1, ANSI_COLOR_RED "EUREUR PARSSIN !!", 24);
		return (free_(tmp_map), 0);
	}
	if (check_wall4(data->map) == 0 || check_wall3(data->map) == 0
		|| check_wall2(data->map) == 0 || check_wall1(data->map) == 0)
	{
		write(1, ANSI_COLOR_RED "MAP INVALID !!", 15);
		return (free_(tmp_map), 0);
	}
	if (ft_check_collective1(data->map) <= 0 || ft_check_player(data->map) != 1
		|| ft_check_sortie(data->map) != 1 || autr_caracters(data->map) == 0)
	{
		write(1, ANSI_COLOR_YELLOW "ERROR MAP !!", 15);
		return (free_(tmp_map), 0);
	}
	return (free_(tmp_map), 1);
}

void	flood_fill(char **map, int pos_x, int pos_y)
{
	size_t	rows;
	size_t	cols;

	cols = count_map_colone(map);
	rows = count_map_line(map);
	if (pos_x < 0 || pos_x >= (int)rows || pos_y < 0 || pos_y >= (int)cols)
		return ;
	if (map[pos_x][pos_y] == '1' || map[pos_x][pos_y] == 'R'
		|| map[pos_x][pos_y] == 'v')
		return ;
	if (map[pos_x][pos_y] == 'E')
	{
		map[pos_x][pos_y] = 'R';
		return ;
	}
	map[pos_x][pos_y] = 'v';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);
}