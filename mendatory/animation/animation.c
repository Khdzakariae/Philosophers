#include "../so_long.h"

void	display_frame(t_data *data, char *assets, int i, int j)
{
	int	images_size;

	data->sprint = mlx_xpm_file_to_image(data->mlx, assets, &images_size,
			&images_size);
	if (!data->sprint)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->sprint, j * 42, i * 42);
	mlx_destroy_image(data->mlx, data->sprint);
}
