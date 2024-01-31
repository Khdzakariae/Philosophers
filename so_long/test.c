#include "so_long.h"


int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "SO_LONG");
    data.player_x = 400;
    data.player_y = 300;

    mlx_hook(data.win, 2, 1L << 0, key_press, &data);
    mlx_hook(data.win, 17, 1L << 17,down_mousse, &data);
    draw_player(&data);
    mlx_loop(data.mlx);
    exit(EXIT_SUCCESS);
}
