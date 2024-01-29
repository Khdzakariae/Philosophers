#include "so_long.h"

int key_press(int keycode, t_data *data)
{
    printf("the key |%i|\n",keycode);
    if (keycode == 65307)
        exit(0);

    if (keycode == 65361 ||keycode == 97) 
        data->player_x -= 10;
    else if (keycode == 65363 ||keycode == 100) 
        data->player_x += 10;
    else if (keycode == 65364 ||keycode == 115) 
        data->player_y += 10;
    else if (keycode == 65362 ||keycode == 119) 
        data->player_y -= 10;

    mlx_clear_window(data->mlx, data->win);
    draw_player(data);

    return (0);
}
