#include "so_long.h"

int ft_check_collective(char map[7][19])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] == 'C')
            {
                return 0;
            }
        }
    }
    return 1;
}

void move_player(t_data *data, int dx, int dy)
{
    void *img;
    int img_width;
    int img_height;


    if (map[dx][dy] == 'E' && ft_check_collective(map))
    {
        mlx_clear_window(data->mlx, data->win);
        mlx_destroy_window(data->mlx, data->win);
        free(data->mlx);
        exit(1);
    }

    else if (map[dx][dy] != '1' && map[dx][dy] != 'E')
    {
        map[data->player_x][data->player_y] = '0';
        map[dx][dy] = 'P';
        data->player_x = dx;
        data->player_y = dy;

    }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 19; j++)
            {
                if (map[i][j] == '0')
                {
                    img = mlx_xpm_file_to_image(data->mlx, SPACE, &img_width, &img_height);
                    if (img != NULL)
                        mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);
                }
                else if (map[i][j] == '1')
                {
                    img = mlx_xpm_file_to_image(data->mlx, WALL, &img_width, &img_height);
                    if (img != NULL)
                        mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);
                }
                else if (map[i][j] == 'C')
                {
                    img = mlx_xpm_file_to_image(data->mlx, PIZZA, &img_width, &img_height);
                    if (img != NULL)
                        mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);
                }
                else if (map[i][j] == 'P')
                {
                    img = mlx_xpm_file_to_image(data->mlx, EMOGE, &img_width, &img_height);
                    if (img != NULL)
                        mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);
                }
                else if (map[i][j] == 'E' && !ft_check_collective(map))
                {
                    img = mlx_xpm_file_to_image(data->mlx, SORTIE, &img_width, &img_height);
                    if (img != NULL)
                        mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);
                }
                else if (map[i][j] == 'E' && ft_check_collective(map))
                {
                    img = mlx_xpm_file_to_image(data->mlx, SORTIEM, &img_width, &img_height);
                    if (img != NULL)
                        mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);
                }

            }
        }
    }

