#include "so_long.h"

void draw_player(t_data *data)
{
	void	*img;
	// char	*relative_path;
	int		img_width = 50;
	int		img_height = 50;
    // mlx_pixel_put(data->mlx, data->win, data->player_x, data->player_y, 0x000000FF);
    img = mlx_png_file_to_image(data->mlx, "/nfs/homes/zel-khad/so_long/so_long/pacman.png",  &img_width, &img_height);
}