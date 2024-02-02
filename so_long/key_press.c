#include "so_long.h"


int key_hook(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_clear_window(data->mlx, data->win);
        mlx_destroy_window(data->mlx, data->win);
        free(data->mlx);
        exit(1);
    }

    else if (keysym == 65361 ||keysym == 97) 
       move_player(data, data->player_x, data->player_y - 1);
    else if (keysym == 65363 ||keysym == 100)
        move_player(data, data->player_x, data->player_y + 1);
    else if (keysym == 65364 ||keysym == 115)
       move_player(data, data->player_x + 1, data->player_y);
    else if (keysym == 65362 ||keysym == 1159)
       move_player(data, data->player_x - 1, data->player_y);

    return 0;
}
