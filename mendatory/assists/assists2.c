#include "../so_long.h"

char	*match_path(const char target, char **map)
{
	if (target == '0')
		return (SPACE);
	if (target == 'P')
		return (EMOGE);
	else if (target == '1')
		return (WALL);
	else if (target == 'C')
		return (PIZZA);
	else if (target == 'E' && !ft_check_collective(map))
		return (SORTIE);
	else if (target == 'E' && ft_check_collective(map))
		return (SORTIEM);
	return (NULL);
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (ft_strchr("01CPE", data->map[i][j]))
			{
				display_frame(data, match_path(data->map[i][j], data->map), i,
					j);
			}
		}
	}
}

void	booyah(t_data *data, char target)
{
	if (!(target == 'E' && ft_check_collective(data->map)))
		return ;
	write(1, ANSI_COLOR_GREEN "BRAVOOOOO !!", 18);
	free_(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

void	update_player(t_data *data, int px, int py, int *moved_number)
{
	if (!(data->map[px][py] != '1' && data->map[px][py] != 'E'))
		return ;
	ft_printf("number of movements ..|%d|\n", *moved_number);
	data->map[data->player_x][data->player_y] = '0';
	data->map[px][py] = 'P';
	data->player_x = px;
	data->player_y = py;
	(*moved_number)++;
}