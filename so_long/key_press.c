#include "so_long.h"


int key_press(int keycode, t_data *data)
{



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