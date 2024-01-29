#include "so_long.h"

int key_press(int keycode, t_data *data)
{
    if (keycode == 53)
        exit(0);

    if (keycode == 123) 
        data->player_x -= 10;
    else if (keycode == 124) 
        data->player_x += 10;
    else if (keycode == 125) 
        data->player_y += 10;
    else if (keycode == 126) 
        data->player_y -= 10;

    mlx_clear_window(data->mlx, data->win);
    draw_player(data);

    return (0);
}
