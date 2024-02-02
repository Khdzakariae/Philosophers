#include "so_long.h"
void ft_position_player(int *x, int *y)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            if (map[i][j] == 'P')
            {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}
int ft_check_collective(char map[7][24])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            if (map[i][j] == 'C')
            {
                return 0;
            }
        }
    }
    return 1;
}

int ft_check_collective1(char map[7][24])
{
    int tmp = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            if (map[i][j] == 'C')
            {
                tmp ++;
            }
        }
    }
    return (tmp);
}



int ft_check_sortie(char map[7][24])
{
    int tmp = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            if (map[i][j] == 'E')
            {
                tmp ++;
            }
        }
    }
    return (tmp);
}

int ft_check_player(char map[7][24])
{
    int tmp = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            if (map[i][j] == 'P')
            {
                tmp ++;
            }
        }
    }
    return (tmp);
}
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
    else if (keysym == 65362 ||keysym == 119)
       move_player(data, data->player_x - 1, data->player_y);

    return 0;
}
void move_player(t_data *data, int dx, int dy)
{
    void *img;
    int img_width;
    int img_height;


    if (map[dx][dy] == 'E' && ft_check_collective(map))
    {
        perror("BRAVOOOOO !!");
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
            for (int j = 0; j < 24; j++)
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
void draw_player(t_data *data)
{

    void *img;
    
    int img_width;
    int img_height;

    for(int i = 0; i< 7; i++)
    {
        for(int j = 0; j < 24; j++)
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



int main()
{
    t_data data;
    if (ft_check_collective1(map) <= 0 || ft_check_player(map) != 1 || ft_check_sortie(map) != 1)
    {
        perror("ERROR MAP !!");
        return EXIT_FAILURE ;
    }
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "SO_LONG");
    draw_player(&data);
    ft_position_player(&data.player_x, &data.player_y);
    mlx_key_hook(data.win, key_hook, &data);
    mlx_loop(data.mlx);
    exit(EXIT_SUCCESS);
}