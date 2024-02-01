#include "so_long.h"


void move_player(t_data *data, int dx, int dy)
{
    void *img;
        int img_width;
    int img_height;
    char *s;
    if (map[dx][dy] != '1')
    {
    map[dx][dy] = 'P';
    map[data->player_x][data->player_y] = '0';
    data->player_x = dx;
    data->player_y = dy;
    for(int i = 0; i< 7; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if (map[i][j] == '1')
                s = "pictures/wall.xpm";
            else if (map[i][j] == '0')
                s = "pictures/space.xpm";
            else if (map[i][j] == 'P')
                s = "pictures/pacman.xpm";
            else if (map[i][j] == 'E')
                s = "pictures/pacman.xpm";
          //  printf("%d  %d",data->player_x, data->player_y);
                 img = mlx_xpm_file_to_image(data->mlx, s,  &img_width, &img_height);
                 if (img != NULL)
                mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);           
                
        }
    }
}
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
    else if (keysym == 65362 ||keysym == 1159)
       move_player(data, data->player_x - 1, data->player_y);

    return 0;
}
void draw_player(t_data *data)
{

    void *img;
    char *s;
    int img_width;
    int img_height;

    for(int i = 0; i< 7; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if (map[i][j] == '1')
                s = "pictures/wall.xpm";
            else if (map[i][j] == '0')
                s = "pictures/space.xpm";
            else if (map[i][j] == 'P')
                s = "pictures/pacman.xpm";
            else if (map[i][j] == 'E')
                s = "pictures/pacman.xpm";
                 img = mlx_xpm_file_to_image(data->mlx, s,  &img_width, &img_height);
                 if (img != NULL)
                mlx_put_image_to_window(data->mlx, data->win, img, j * 42, i * 42);           
        }
    }
}

void ft_position_player(int *x, int *y)
{
    for (int i  = 0; i < 7 ;i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if (map[i][j] == 'P')
            {
                *x = i;
                *y = j;
                //printf("|%d| |%d|", *x, *y);
                return ;
            }
        }
    }
}
int main(void)
{
    t_data data;

    ft_position_player(&data.player_x, &data.player_y);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "SO_LONG");
        //printf("%d  %d",data.player_x, data.player_y);
    draw_player(&data);
    mlx_key_hook(data.win, key_hook, &data);
    ///draw_player(&data);
    mlx_loop(data.mlx);
    exit(EXIT_SUCCESS);
}
