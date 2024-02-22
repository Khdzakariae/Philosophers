#include "../so_long.h"

int	handle_destroy_notify(t_data *data)
{
	write(1, ANSI_COLOR_YELLOW "THE GMAE IS OVER", 21);
	mlx_destroy_window(data->mlx, data->win);
	free_(data->map);
	exit(1);
}

int	key_hook(int keysym, t_data *data)
{
	printf("%d\n", keysym);
	if (keysym == 53 || keysym == 65307)
	{
		write(1, ANSI_COLOR_YELLOW "THE GMAE IS OVER", 21);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_(data->map);
		free(data->mlx);
		exit(1);
	}
	if (keysym == 123 || keysym == 0 || keysym == 65361)
	{
		move_player(data, data->player_x, data->player_y - 1);
	}
	else if (keysym == 124 || keysym == 2 || keysym == 65363)
	{
		move_player(data, data->player_x, data->player_y + 1);
	}
	else if (keysym == 125 || keysym == 1 || keysym == 65362)
	{
		move_player(data, data->player_x + 1, data->player_y);
	}
	else if (keysym == 126 || keysym == 13 || keysym == 65364)
	{
		move_player(data, data->player_x - 1, data->player_y);
	}
	return (0);
}