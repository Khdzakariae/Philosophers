

#include "so_long.h"

// #define HEIGHT 300
// #define WIDTH 740

// typedef struct
// {
//     void *mlx;
//     void *win;
//     int player_x;
//     int player_y;
// } t_data;

char map[5][12] = {
    "111111111111",
    "100000000001",
    "1000P0000001",
    "100000000E01",
    "111111111111"};

int main()
{
    t_data data;

    int i = 0;
    int j = 0;
    char *s;
    void *img;

    // int img_width = 1;
    // int img_height = 1;

    // data.mlx = mlx_init();
    // data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "SO_LONG");
    // data.player_x = 300;
    // data.player_y = 800;

    while (i < 5)
    {
        j = 0;
        while (j < 12)
        {
            if (map[i][j] == '1')
            {
                s = "/nfs/homes/zel-khad/Desktop/so_long/so_long/7ayt.xpm";
                img = mlx_xpm_file_to_image(data.mlx, s, &img_width, &img_height);
                mlx_put_image_to_window(data.mlx, data.win, img, j * img_width, i * img_height);
            }
            j++;
        }
        i++;
    }
    return 0;
}
