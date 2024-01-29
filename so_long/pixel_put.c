#include "so_long.h"

void draw_player(t_data *data)
{
    mlx_pixel_put(data->mlx, data->win, data->player_x, data->player_y, 0x000000FF);
}