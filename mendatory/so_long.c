
#include "so_long.h"


int check_path(char *str)
{
	char *path;
	path = ".ber";
	int size1  = ft_strlen(path);
	int size = ft_strlen(str);

	while (size != (size - (size1 + 1)))
	{
			if (str[size] != path[size1])
				return(0);
			size--;
			size1--;
	}
	return(1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (write(1, ANSI_COLOR_YELLOW "ENTRER UNE MAP .. !", 24));
	if (check_path(av[1]) ==  0)
		return (write(1, ANSI_COLOR_YELLOW "ENTRER UN PATH VALID |.ber| !", 34));
	if (read_map(&data, av[1]) == 0)
		return (0);
	ft_position_player(data.map, &data.player_x, &data.player_y);
	if (parssin_map(&data, data.tmp_map) == 0)
	{
		free_(data.map);
		return(EXIT_FAILURE);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, count_map_colone(data.map) * 42,
			count_map_line(data.map) * 42, "SO_LONG");
	draw_player(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, handle_destroy_notify, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}