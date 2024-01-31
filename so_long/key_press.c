#include "so_long.h"


int key_press(int keycode, t_data *data)
{
    printf("the key |%i|\n",keycode);
    if (keycode == 65307 )
    {

        mlx_clear_window(data->mlx, data->win);
        mlx_destroy_window(data->mlx, data->win);
        free(data->mlx);
        exit(1);
    }

    if (keycode == 65361 ||keycode == 97) 
        data->player_x -= 20;
    else if (keycode == 65363 ||keycode == 100) 
        data->player_x += 20;
    else if (keycode == 65364 ||keycode == 115) 
        data->player_y += 20;
    else if (keycode == 65362 ||keycode == 119) 
        data->player_y -= 20;

    draw_player(data);

    return (0);
}

int down_mousse(int button, int x, int y, t_data *data)
{
    (void)x;
    (void)y;
    printf("boton %d\n", button);
    if (button == 1958883080 || button == 658865048)
    {
        exit(0);
        mlx_clear_window(data->mlx, data->win);
        mlx_destroy_window(data->mlx, data->win);
        free(data->mlx);
    }
    
    return (0);
}